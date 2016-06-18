//******************************************************************
// Checkbook Balancing program
// Programmer: Ian Olsen
// Completed : 6/16/
// Status    : Complete
// Description
// This program will help track and balance a 
// checkbook at the end of the month for you
//******************************************************************

#include <iostream> // input/output declarations
#include <iomanip>  // i/o manipulator declarations

using namespace std;

void processCheck(float &, float &, int &, float &);
void showMenu(char &);
void processDeposit(float &, float &, float);
void invalidChoice(char &);
void getBalance(float &);
void getTransaction(char, float &);
void processMonth(float, float);

int main()
{
	float	balance;         //monthly balance
	float	totalSvcCharge = 0;  //end of the month sum of all service fees
	float	transAmount;      //transaction amount
	int		numServCharge = 0; //accumulator for total number of service fees
	char	choice;            //User input as a character

							//set all amounts entered to have two decimal places displayed
	getBalance(balance);
	
	do { 
		//Display the menu and get the user's choice
		showMenu(choice);
		//Validate the menu selection
		while ((choice > 'E') || (choice < 'C')){
			invalidChoice(choice);
		}
		//Process the user's choice
		getTransaction(choice, transAmount);
		if (choice == 'C'){
			//process checking transactions
			processCheck(balance, transAmount, numServCharge, totalSvcCharge);			
		}
		//Process a deposit for the user
		else if (choice == 'D'){
			processDeposit(balance, transAmount, totalSvcCharge);
		}
	} while (choice != 'E'); //Loop until E is selected


	if (choice == 'E'){
		processMonth(balance, totalSvcCharge);	
	}
	system("PAUSE");
	return 0;
}//End of Main

void processMonth(float balance, float totalSvcCharge) {
	float	finalBalance;    //End of month processing
	cout << "Processing end of month\n";
	finalBalance = balance - totalSvcCharge;
	cout << "Final balance: $" << finalBalance;
}



void getTransaction(char choice, float &transAmount) {
	if (choice != 'E'){			//Ensure the user enters a positive number
		cout << "Enter transaction amount: ";
		cin >> transAmount;
	} 
	
	while (transAmount <= 0){   //error statement for negative amount
		cout << "Please enter a positive number (larger than zero): ";
		cin >> transAmount;
	}
}


void getBalance(float &balance) {
	cout << fixed << showpoint << setprecision(2);
	cout << "Checkbook Balancing Program\n";
	cout << "Enter the beginning balance: \n";
	cin >> balance;
	while (balance < 0) {
		cout << "Please enter a positive balance: ";
		cin >> balance;
	}
	cout << endl;
}


void processCheck(float &balance, float &transAmount, int &numServCharge, float &totalSvcCharge) {
	
	float SERVICE_FEE = 0.25; //service fee for each written check

	cout << "Processing check for: $" << transAmount << "\n";
	balance -= transAmount;
	cout << "Balance: $" << balance << "\n";
	cout << "Service charge: $0.25 for a check\n";

	numServCharge++; //accumulates total for each service fee charged
	totalSvcCharge = numServCharge * SERVICE_FEE;
	cout << "Total service charges: $ " << totalSvcCharge << endl;
	cout << endl;
}

void showMenu(char &choice) {
	cout << "Commands:\n";
	cout << "C - process a check\n";
	cout << "D - process a deposit\n";
	cout << "E - end the program\n";
	cout << "Enter transaction type: ";
	cin  >> choice;
	cout << endl;
}

void invalidChoice(char &choice) {
	cout << "Invalid choice selected. Please use D, C, and E" << endl;
	cin >> choice;
}

void processDeposit(float &balance, float &transAmount, float totalSvcCharge) {
	cout << "Processing deposit for: $" << transAmount << "\n";
	balance += transAmount;
	cout << "Balance: $" << balance << "\n";
	cout << "Total service charges: $" << totalSvcCharge << "\n";
	cout << endl;
	cout << endl;
}