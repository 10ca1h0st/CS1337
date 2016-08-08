//******************************************************************
// Test Scores
// Programmer: Ian Olsen
// Completed : 07/22/2016
// Status    : Complete
// Description
// Get student test scores, sort and then calculate an average
//******************************************************************

#include <iostream>      // i/o declarations
#include <string>        // string declaration
#include <iomanip>       // i/o manipulator declarations

using namespace std;


//STRUCT student
//INPUTS string of students name, integer of the student's test score
struct student
{
	string studentName;
	int score = 0;
};

//FUNCTION PROTOTYPES
void getStudentData(student *, int);
void sortData(student *, int);
float getAverage(student *, int);
void displayData(student *, int, float);


//BEGIN MAIN FUNCTION
int main()
{
	int numStudents;	//Number of Students
	float average;		//Average of test scores

	//GET NUMBER OF STUDENTS TO ADD TO ARRAY
	cout << "Enter the number of students to process: ";
	cin >> numStudents;
	//NEWLINE CHARACTER IGNORE TO PREVENT UNINTENTIONAL INPUT
	cin.ignore();

	//CREATE DYNAMIC ARRAY OF TYPE STRUCT student WITH SIZE OF numStudents
	student *studentTotal = new student[numStudents];

	//CALL TO getStudentData FOR DATA INPUT
	getStudentData(studentTotal, numStudents);

	//CALL TO sortData TO SORT TEST SCORES IN ASCENDING ORDER
	sortData(studentTotal, numStudents);

	// INITIALIZE AVERAGE TO CALL RETURN VALUE OF getAverage
	average = getAverage(studentTotal, numStudents);

	//CALL TO displayData TO OUTPUT TABLE AND USER DATA
	displayData(studentTotal, numStudents, average);

	//DELETE DYNAMIC ARRAY TO FREE MEMORY
	delete [] studentTotal;

	system("PAUSE");
	return 0;
}


//FUNCTION getStudentData
//PURPOSE: Get our students data and input to dynamic array
void getStudentData(student *studentTotal, int numStudents)
{
	//LOOP THROUGH THE NUMBER OF STUDENTS TO ENTER THEIR TEST SCORES
	for (int i = 0; i < numStudents; i++)
	{
		//GET OUR STUDENTS NAME
		cout << "Student Name: ";
		getline(cin, studentTotal[i].studentName);

		//VALIDATION: WHILE STUDENT LENGTH IS GREATER THAN 30, DISPLAY ERROR
		while(studentTotal[i].studentName.length() > 30)
		{
			//OUTPUT ERROR MESSAGE AND RE-ENTER NAME
			cout << "Names may only contain up to 30 characters. Please re-enter the name: ";
			getline(cin, studentTotal[i].studentName);
		}
		
		//GET TEST SCORE FOR STUDENT(X)
		cout << studentTotal[i].studentName << "'s test score: ";
		cin >> studentTotal[i].score;

		//IGNORE NEWLINE CHARACTER TO PREVENT UNINTENTIONAL INPUT
		cin.ignore();

		//VALIDATION: WHILE STUDENT SCORE IS LESS THAN 0 OR GREATER THAN 104, DISPLAY ERROR
		while (studentTotal[i].score < 0 || studentTotal[i].score > 104)
		{
			//OUTPUT ERROR MESSAGE
			cout << "Test scores must be in the range of 0 to 104." << endl;
			cout << studentTotal[i].studentName << "'s test score: ";
			cin >> studentTotal[i].score;
			//IGNORE NEWLINE CHARACTER TO PREVENT UNINTENTIONAL INPUT
			cin.ignore();
		}
	}//ENF OF FOR LOOP
}//END OF getStudentData


//FUNCTION sortData
//PURPOSE: Sort data using a bubble sort in ascending order
void sortData(student *studentTotal, int grade)
{
	student temp;	//Set a temp placeholder for sorting
	int swap = 1;	//Set flag for determining eos

	//DO WHILE LOOP TO BEGIN SORT
	do
	{
		swap = 0;
		//LOOP THROUGH GRADES TO SORT
		for (int i = 0; i < (grade - 1); i++)
		{
			//IF 0 INDEX GRADE IS LESS THAN THE NEXT INDEX 
			if(studentTotal[i].score > studentTotal[i+1].score)
			{
				//SET MAIN INDEX TO TEMP
				temp = studentTotal[i];
				//SET ORIGINAL INDEX TO NEXT INDEX
				studentTotal[i] = studentTotal[i + 1];
				//SET NEXT INDEX TO TEMP
				studentTotal[i + 1] = temp;
				//RELOOP
				swap = 1;
			}
		}//END OF FOR LOOP
	} while (swap); 
}//END OF sortData


//FUNCTION getAverage
//PURPOSE: Calculate an average from our test scores
float getAverage(student *studentTotal, int testCount)
{
	float total = 0;	// initialize our total variable to 0

	//LOOP THROUGH TEST GRADES AND ADD A RUNNING TOTAL
	for (int i = 0; i < testCount; i++)
	{
		total = total + studentTotal[i].score;
	}
	return total / testCount;
}//END OF getAverage


//FUNCTION displayData
//PURPOSE: Output sorted table data from the program
void displayData(student *studentTotal, int testCount, float average)
{
	//TABLE STYLING
	cout << "Name" << setw(27) << "Score" << endl;
	cout << "-------------------------------" << endl;

	//LOOP THROUGH ARRAY AND OUTPUT THE DATA FROM OUR PROGRAM
	for (int i = 0; i < testCount; i++)
	{
		cout << left << setw(18) << studentTotal->studentName << " "
			<< right << setw(12) << studentTotal->score << endl;
		studentTotal++;
	}

	//MORE TABLE STYLING
	cout << "-------------------------------" << endl;
	//OUTPUT OUR PROGRAMS AVERAGE
	cout << "Average" << setw(24) << average << endl;
}//END displayData