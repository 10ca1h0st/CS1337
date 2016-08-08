//******************************************************************
// PayRoll Version 2.0
// Programmer: Ian Olsen
// Completed : 08/01/2016
// Status    : Complete
// Description
// This program gets employee information and holds it in a struct
//******************************************************************

#include <iostream>      // i/o declarations
#include <string>        // string declaration
#include <iomanip>       // i/o manipulator declarations
#include <fstream>		 // file i/o stream

using namespace std;

//FUNCTION PROTOTYPES
void getEmployeeData(class Employee masterFile[]);
void getTransData(struct transData[], class Employee[]);
void processPayroll(struct transData[], class Employee[]);

//STRUCT OF EACH EMPLOYEE
struct transData
{
	int empId;				//EMPLOYEEID NUMBER
	double hoursWorked;		//EMPLOYEE HOURS WORKED
	double finalPay;		//EMPLOYEE FINAL PAY

};

//CREATE EMPLOYEE CLASS AND SET PRIVATE AND PUBLIC VARIABLES
class Employee
{
//SET PRIVATE VARIABLES
private:
	int id;             //EMPLOYEE ID PRIVATE
	string name;        //EMPLOYEE NAME PRIVATE
	double hourlyPay;   //EMPLOYEE HOURLY PAY PRIVATE
	int numDeps;        //EMPLOYEE DEPENDENTS PRIVATE
	int type;           //EMPLOYEE TYPE PRIVATE

//SET PUBLIC VARIABLES
public:

	int getEmpId();			//FUNCTION TO GET ID
	string getName();		//FUNCTION TO GET NAME
	double getHourlyPay();	//FUNCTION TO GET HOURLY PAY
	int getDependents();	//FUNCTION TO GET DEPENDENTS 
	int getType();			//FUNCTION TO GET EMPLOYEE TYPE

	//PREDEFINED CLASS DATA FROM DOCUMENT
	Employee(int initId = 0, string initName = "",
		double initHourlyPay = 0.0,
		int initNumDeps = 0, int initType = 0);  // Constructor

	bool set(int newId, string newName, double newHourlyPay,
		int newNumDeps, int newType);

};

//PREDEFINED CLASS DATA FROM DOCUMENT
Employee::Employee(int initId, string initName,
	double initHourlyPay,
	int initNumDeps, int initType)
{
	bool status = set(initId, initName, initHourlyPay,
		initNumDeps, initType);

	if (!status)
	{
		id = 0;
		name = "";
		hourlyPay = 0.0;
		numDeps = 0;
		type = 0;
	}
}

//PREDEFINED CLASS DATA FROM DOCUMENT
bool Employee::set(int newId, string newName, double newHourlyPay,
	int newNumDeps, int newType)
{
	bool status = false;

	if (newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 &&
		newType >= 0 && newType <= 1)
	{
		status = true;
		id = newId;
		name = newName;
		hourlyPay = newHourlyPay;
		numDeps = newNumDeps;
		type = newType;
	}
	return status;
}



//FUNCTION get*
//GET FUNCTIONS TO RETURN DATA TO OUR EMPLOYEE CLASS
int Employee::getEmpId()
{
	return id;
}

//GET NAME
string Employee::getName()
{
	return name;
}

//GET HOURLY PAY
double Employee::getHourlyPay()
{
	return hourlyPay;
}

//GET DEPS
int Employee::getDependents()
{
	return numDeps;
}

//GET EMPLOYEE TYPE
int Employee::getType()
{
	return type;
}



//BEGIN MAIN FUNCTION
int main()
{
	//SET CONSTANT EMPLOYEE NUMBER
	const int EMPLOYEES = 6;

	//CREATE MASTERFILE with CONSTANT EMPLOYEES OF 6
	Employee masterFile[EMPLOYEES];

	//CREATE PAYCHECK with CONSTANT EMPLOYEES OF 6
	transData paycheck[EMPLOYEES];

	
	//CALL getEmployeeData to obtain master file and create array
	getEmployeeData(masterFile);

	//CALL getTransData to obtain transaction file and create array
	getTransData(paycheck, masterFile);

	//CALL processPayroll and process our company payroll from the two arrays
	processPayroll(paycheck, masterFile);


	//SYSTEM PAUSE AND RETURN
	system("PAUSE");
	return 0;
}


//FUNCTION getEmployeeData
//PURPOSE: GET DATA FOR SIX EMPLOYEES FROM A DATA FILE
void getEmployeeData(Employee masterFile[]) {
	
	int tempID;			//SET TEMP HOLDER VARIABLE FOR ID
	string tempName;	//SET TEMP HOLDER VARIABLE FOR NAME
	double tempHourPay;	//SET TEMP HOLDER VARIABLE FOR HOURLY PAY
	int tempNumDep;		//SET TEMP HOLDER VARIABLE FOR DEPENDENTS
	int tempType;		//SET TEMP HOLDER VARIABLE FOR EMPLOYEE TYPE


	//INPUT OUR MASTERFILE TO BE USED
	ifstream employeeFile("master9.txt");

	//VALIDATION CHECK IF MASTERFILE IS NOT ABLE TO BE LOCATED
	if(!employeeFile)
	{
		cout << "File was unable to be located.\n";
	}

	//VALIDATION CHECK IF MASTERFILE WAS LOCATED
	else
	{
		//CYCLE THROUGH OUR EMPLOYEES ARRAY
		for(int i = 0; i < 6; i++)
		{
			//SET FIRST DATA TO tempID
			employeeFile >> tempID;

			//SET EMPLOYEE NAME TO tempName STRING
			getline(employeeFile, tempName, '#');

			//SET SET LAST THREE NUMBER COLUMNS TO CORRESPONDING VARIABLE
			employeeFile >> tempHourPay >> tempNumDep >> tempType;

			//SET DATA POINT TO OUR MASTERFILE ARRAY
			masterFile[i].set(tempID, tempName, tempHourPay, tempNumDep, tempType);
		} //END FOR LOOP
	} // END IF LOOP

	//CLOSE FILE
	employeeFile.close();
}//END OF getEmployeeData 


//FUNCTION getTransData
//PURPOSE: GET TRANSACTION DATA FOR SIX EMPLOYEES FROM A DATA FILE
void getTransData(transData paycheck[], Employee masterFile[])
{

	//OPEN THE TRANSACTION FILE
	ifstream transFile("trans9.txt");

	//VALIDATION CHECK IF TRANS FILE IS NOT ABLE TO BE LOCATED
	if (!transFile)
	{
		cout << "File was unable to be located.\n";
	}

	//VALIDATION CHECK IF TRANSACTION FILE WAS LOCATED
	else
	{
		//CYCLE THROUGH OUR EMPLOYEES ARRAY
		for (int i = 0; i < 6; i++)
		{
			//COPY TRANSACTION DATA INTO ID AND HOURS WORKED
			transFile >> paycheck[i].empId >> paycheck[i].hoursWorked;

			//CALCULATE EMPLOYEES FINAL PAY AND STORE IN finalPay
			paycheck[i].finalPay = (paycheck[i].hoursWorked * masterFile[i].getHourlyPay());

		}//END FOR LOOP
	}//END IF LOOP

	//CLOSE FILE
	transFile.close();
}//END getTransData


//FUNCTION processPayroll
//PURPOSE: USE DATA ARRAYS TO PROCESS PAYROLL DATA FOR COMPANY
void processPayroll(transData paycheck[], Employee masterFile[]) {

	double tax = 0.0;				//CREATE AND INTIALIZE DOUBLE FOR TAX
	double insurance = 0.0;			//CREATE AND INTIALIZE DOUBLE FOR INSURANCE
	double grossPay = 0.0;			//CREATE AND INTIALIZE DOUBLE FOR GROSS PAY
	double netPay = 0.0;			//CREATE AND INTIALIZE DOUBLE FOR NET PAY
	double totalGrossPay = 0.0;		//CREATE AND INTIALIZE DOUBLE FOR TOTAL GROSS
	double totalNetPay = 0.0;		//CREATE AND INTIALIZE DOUBLE FOR TOTAL NET
	int successCounter = 0;			//CREATE AND INTIALIZE INTEGER FOR SUCCESSFUL TRANSACTION 


	//CREATE AND OPEN NEW FILE FOR OUTPUT
	ofstream payrollProcess("payroll9.txt");

	//SET DECIMAL PRECISION
	payrollProcess << fixed << showpoint << setprecision(2);

	//CREATE A TAB USING SETW AND NO TABS
	payrollProcess << "ID" << setw(20) << "Name" << setw(25) << "Gross Pay" << setw(15) << "Tax" << setw(15) << "Insurance" << setw(15) << "Net Pay" << endl;


	//CYCLE THROUGH OUR ARRAY
	for (int i = 0; i < 100; i++)
	{
		//VALIDATION CHECK ENSURING NO ID IS LESS THAN 0
		if (masterFile[i].getEmpId() > 0)
		{

			//WHEN EMPLOYEE HAS WORKED, CALCULATE THE EMPLOYEES GROSS
			if (paycheck[i].hoursWorked > 0)
			{
				//UNION WORKERS GET PAID OVERTIME
				if ((masterFile[i].getType() == 0) && (paycheck[i].hoursWorked > 40))
				{
					//SUBTRACT 40 TO GET OT HOUR AMOUNT AND MULTIPLE BY 1.5, THEN ADD REGULAR PAY
					grossPay = (paycheck[i].hoursWorked - 40)* 1.5 * masterFile[i].getHourlyPay() + 40 * masterFile[i].getHourlyPay();
					
				}

				//MANAGERS DO NOT GET PAID OVERTIME OVER 40HOURS
				else
				{
					//SET GROSS TO HOURS TIMES PAY
					grossPay = paycheck[i].hoursWorked * masterFile[i].getHourlyPay(); 
				}

				//SET INSURANCE TO AMOUNT OF DEPENDENTS TIME 20
				insurance = masterFile[i].getDependents() * 20;

				//ALL EMPLOYEES PAY A FLAT TAX OF 15 PERCENT
				tax = grossPay * .15;

				//NET PAY IS GROSS MINUS DEDUCTIONS
				netPay = (grossPay - tax - insurance);

				//COPY DATA TO FILE TO FIT TABLE SET LINE 261
				payrollProcess << left << setw(17) << masterFile[i].getEmpId() << setw(11) << right << masterFile[i].getName() << setw(9) << grossPay << setw(15) << tax << setw(15) << insurance << setw(15) << netPay << endl;

				//CALCULATE COMPANIES TOTAL GROSS PAY
				totalGrossPay += grossPay;

				//CALCULATE COMPANIES TOTAL NET PAY    
				totalNetPay += netPay;


				//COUNT NUMBER OF SUCCESSFUL TRANSACTIONS
				successCounter++;

			}

			//VALIDATION OUTPUT FOR EMPLOYEES WITH LESS THAN 0 HOURS WORKED
			else
			{

				//OUTPUT ERROR TO SCREEN
				cout << masterFile[i].getName() << "has an hour amount that is less than zero. \n This employee will be excluded from the payroll report." << endl;
			}
		}//END DATA OUTPUT IF LOOP
	}//END DATA OUTPUT FOR LOOP

	//DISPLAY successCounter AMOUNT
	cout << "\nNumber of successful transactions: " << successCounter << endl;


	//PRINT ALL DATA TO PAYROLL REPORT
	for (int i = 0; i < 100; i++)
	{
	}

	//OUT THE TOTAL GROSS AND NET PAY FOR THE COMPANY AFTER EMPLOYEE TABLE
	payrollProcess << "\nTotal Gross Pay: " << totalGrossPay << "\nTotal Net Pay  : " << totalNetPay << endl;

	//CLOSE FILE
	payrollProcess.close();

}//END processPayroll