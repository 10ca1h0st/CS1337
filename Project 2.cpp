//******************************************************************
// Checkbook Balancing program
// Programmer: Ian Olsen
// Completed : 6/16/2016
// Status    : Complete
// Description
// This program will help track and balance a 
// checkbook at the end of the month for you
//******************************************************************

#include <iostream>		// I/O declarations
#include <iomanip>		// I/O manipulation declarations

using namespace std;

//Function Prototypes
void getBalance(float &);
void showMenu(char &);
void getTransaction(char, float &);
void processCheck(float &, float &, float &, int &);
void processDeposit(float &, float &, float);
void processMonth(float, float);


int main() {
//Declare variables for main
	float balance;		//Beginning bank balance
	char  option;		//Users input
	float transAmt;		//Transaction amount
	float totalSvcFee;	//Total service fee
	int	  svcFeeCounter = 0;	//Service fee counter initialized to 0

//	Set precision and display title
	cout << fixed << showpoint << setprecision(2);
	cout << "Checkbook Balancing Program\n" << endl;

//	Get the initial balance of the banking account
	getBalance(balance);

//	Do/While loop to manage the menu loop
	do {
		showMenu(option); 					//Call the menu and receive user option
		getTransaction(option, transAmt);	//Call the transaction loop
		//Process menu selection
		//Call and process a check
		if (option == 'C') { 
			processCheck(balance, transAmt, totalSvcFee, svcFeeCounter);	
		}
		//Call and process a deposit
		else if (option == 'D') {
			processDeposit(balance, transAmt, totalSvcFee);
		}
	} while (option != 'E'); //Loop until E is selected
//	End of DO/WHILE loop	


//	Process end of month statement
	if (option == 'E') {
		processMonth(balance, totalSvcFee);
	}

	return 0; 
}//End of MAIN

//Function getBalance
//Purpose: get initial balance of the banking account
void getBalance(float &balance) {

	cout << "Enter the beginning balance: ";
	cin >> balance;
	cout << endl;
}

//Function showMenu
//Purpose: Display users menu and receives option
void showMenu(char &option) {
	
	//Output banking menu and get user input
	cout << "Commands:\n";
	cout << "C - process a check\n";
	cout << "D - process a deposit\n";
	cout << "E - end the program\n" << endl;
	cout << "Enter transaction type: ";
	cin >> option;
	
	//Menu Validation
	while ((option > 'E') || (option < 'C')) {
		cout << "Invalid option! Please use D, C, and E" << endl;
		cin >> option;
	}
}

//Function getTransaction
//Purpose: Get the amount of currency to be used with the users transaction
void getTransaction(char option, float &transAmt) {
	
	//Get transaction amount
	if (option != 'E') {
		cout << "Enter transaction amount: ";
		cin >> transAmt;
	}
	
	//Prevent negative transaction amounts
	while (transAmt <= 0) {
		cout << "Enter a positive transaction amount: ";
		cin >> transAmt;
	}

}

//Function processCheck
//Purpose: Process a check and calculate service fee
void processCheck(float &balance, float &transAmt, float &totalSvcFee, int &svcFeeCounter) {

	float serviceFee = 0.25;	//Service Fee charge

//Display check processing data
	cout << "Processing check for: $" << transAmt << endl;
	balance -= transAmt;
	cout << "Balance: $" << balance << endl;
	cout << "Service charge: $.25 for a check" << endl;

//Accumulate service fee for checks used
	svcFeeCounter++;
	totalSvcFee = svcFeeCounter * serviceFee;
	cout << "Total service charges: $ " << totalSvcFee << endl;
	cout << endl;
}

//Function processDeposit
//Purpose: Process a banking deposit for the user
void processDeposit(float &balance, float &transAmt, float totalSvcFee) {

	//Get transaction amount and calculate a deposit
	cout << "Processing deposit for: $" << transAmt << endl;
	balance += transAmt;
	cout << "Balance: $" << balance << endl;
	cout << "Total service charges: $" << totalSvcFee << endl;
	cout << endl;
}

//Function processMonth
//Purpose: Calculate final banking total at the end of the month
void processMonth(float balance, float totalSvcFee) {

	float	finalBalance;    //Final bank balance

	//Calculate end of month balance
	cout << "Processing end of month" << endl;
	finalBalance = balance - totalSvcFee;
	cout << "Final balance: $" << finalBalance << endl;
}