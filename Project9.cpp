//******************************************************************
// Date Class
// Programmer: Ian Olsen
// Completed : 07/31/2016
// Status    : Complete
// Description
// Have user set date and display various formats for the date
//******************************************************************


#include <iostream>      // i/o declarations
#include <string>        // string declaration

using namespace std;

class Date
{

	//Set PRIVATE VARIABLES
	private:
		int day;				 //INTEGER: day
		int month;				 //INTEGER: month
		int year;				 //INTEGER: year
		string getMonthName();	 //STRING PROTOTYPE: getMonthName

	//Set PUBLIC VARIABLES
	public:
		//Date Constructor
		Date();		
		//setDate prototype
		void setDate(int, int, int);	
		//Format Prototypes
		void dateFormatOne();			
		void dateFormatTwo();
		void dateFormatThree();
		//Date Destructor
		~Date();						
};



/*************************************
* Date Default Constructor			 *
*************************************/

Date::Date() 
{
	day = month = 1;
	year = 2001;
}

/*************************************
*			Date::getMonthName		 *
* Function that gets an integer 	 *
* input from user and sets it to a 	 *
* month with a string name			 *
*************************************/
string Date::getMonthName()
{
	//Create and initialize a placeholder for our integer month
	int x = 0;

	//Set our placeholder to the user's input
	x = month;

	//Create an array of strings with our month names
	string monthString[] = { "January","February","March","April","May","June",
							 "July","August","September","October","November","December" };

	//Return index value of array to get our month name
	return monthString[x - 1];
}

/*************************************
*			Date::setDate			 *
* Function that validates the user	 *
* input values and then sets the	 *
* objects variables.				 *
*************************************/

void Date::setDate(int day, int month, int year)
{

	//VALIDATION FAIL: SET VALUES TO DEFAULT
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1950 || year > 2020) {
		day = month = 1;
		year = 2001;
	}

	//VALIDATION PASS: CREATE A NEW OBJECT
	else
	{
		Date::day = day;		//create day object
		Date::month = month;	//create month object
		Date::year = year;		//create year object	
	}
}


/*************************************
*			Date::dateFormatOne		 *
* Function that displays the first 	 *
* format with the user's data		 *
*************************************/
void Date::dateFormatOne()
{
	cout << month << "/" << day << "/" << year << endl;
}


/*************************************
*			Date::dateFormatTwo		 *
* Function that displays the first 	 *
* format with the user's data		 *
*************************************/
void Date::dateFormatTwo()
{
	cout << getMonthName() << " " << day << ", " << year << endl;
}

/*************************************
*			Date::dateFormatThree	 *
* Function that displays the first 	 *
* format with the user's data		 *
*************************************/
void Date::dateFormatThree()
{
	cout << day << " " << getMonthName() << " " << year << endl;
}

/*************************************
* Date Destructor					 *
*************************************/
Date::~Date(){}


int main()
{
	//LOCAL VARIABLES
	int day;		//INTEGER: Day
	int month;		//INTEGER: Month
	int year;		//INTEGER: Year
	Date newDate;	//NEW CLASS: newDate


	//GET USER INPUT
	//Month
	cout << "Please enter a month between 1 and 12: ";
	cin >> month;

	//Day
	cout << "Please enter a day between 1 and 31: ";
	cin >> day;

	//Year
	cout << "Please enter a year between 1950 and 2020: ";
	cin >> year;

	//CALL setDate WITH USER DATA
	newDate.setDate(day, month, year);


	newDate.dateFormatOne();
	newDate.dateFormatTwo();
	newDate.dateFormatThree();

	system("PAUSE");

	return 0;

}