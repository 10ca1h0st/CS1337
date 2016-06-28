//******************************************************************
// Monkey Food
// Programmer: Ian Olsen
// Completed : 6/27/2016
// Status    : Complete
// Description
// This program will help track and run some calculations 
// on the amount of food that monkeys eat at the zoo.
//******************************************************************

#include <iostream> // in/out declarations
#include <iomanip>  // in/out manipulator declarations 
#include <string>   // string declarations

using namespace std;

//Global constants for array size
const int MONKEYS = 3; //row
const int DAYS = 7;    //column

//Function prototypes
void getFood(float [][DAYS]);
float getAverage(float [][DAYS]);
float getMin(float [][DAYS]);
float getMax(float [][DAYS]);
void displayOutput(float[][DAYS], float, float, float);

int main()
{
	float foodAte[MONKEYS][DAYS];  //array for passing monkey data
	float average;				   //average of all monkey food
	float least;				   //least monkey food eaten
	float most;					   //most monkey food eaten

//call function to loop for the user to input food eaten by each monkey
	getFood(foodAte);

//call respective function and set the variables to be used in our output
	average = getAverage(foodAte);
	least = getMin(foodAte);
	most = getMax(foodAte);

//display the final data for our monkey feedings
	displayOutput(foodAte, average, least, most);
	system("PAUSE");
	return 0;

}//end main function


//Function getFood
//Purpose: Get the food eaten by the three monkeys for each day of the week

void getFood (float dailyFood[][DAYS])
{
	//rename DAYS subscript data
	string name[DAYS] = { "Sun", "Mon","Tue","Wed","Thu","Fri","Sat" };   //set DAYS to names of weekdays

	//row iterate
	for (int monkey = 0; monkey < MONKEYS; monkey++){

	//column iterate
		for (int day = 0; day < DAYS; day++){

			//get the input from user to be stored
			do {

				//loop through each monkey and each day of the week and get input for both
				cout << "Enter pounds of food eaten by monkey " << monkey + 1 << " on " << name[day] << ": ";
				cin >> dailyFood[monkey][day];

				//input validation check incase input is less than 0
				if (dailyFood[monkey][day] < 0) {
					cout << "Negative numbers are not accepted. Please enter a positive number\n" << endl;
				 }

				//display menu until the array has completed each row and column
			   } while (dailyFood[monkey][day] < 0); 

		}//end the column iterate
	}//end the row iterate
}//end of the getFood function


//Function getAverage
//Calculate average food eaten per day by all monkeys

float getAverage(float dailyFood[][DAYS])
{

	float average = 0;		//initialize a average 
	float food = 0;			//set a food accumulator 
	int totalFeedings = 21; //total number of feedings

	//row iterate
	for ( int monkey = 0; monkey < MONKEYS; monkey++){	

		//column iterate
		for ( int day = 0; day < DAYS; day++){

			//get total amount of food eaten by all the monkeys and find the average
			food = food + dailyFood[monkey][day];
			average = food / totalFeedings;

		}//end of column iterate
	}//end of row iterate

	//return the average amount of food eaten
	return average;  
}//end of the getAverage function



//Function getMin
//Retrieve least amount of food eaten out of all the monkeys

float getMin( float dailyFood[][DAYS])
{
	//copy first values of dailyFood to min for comparing
	float min = dailyFood[0][0]; 
	
	//row iterate
	for (int monkey = 0; monkey < MONKEYS; monkey++) {
	
		//column iterate
		for (int day = 0; day < DAYS; day++) {

			//compare remaining values and retrieve the smallest 
			if (dailyFood[monkey][day] < min)
				min = dailyFood[monkey][day];

		}//end of column iterate
	}//end of row iterate

	//return the least amount of food eaten by a monkey
	return min;
}//end of the getMin function


//Function getMax
//Retrieve the largest amount of food eaten out of all the monkeys

float getMax(float dailyFood[][DAYS])
{
	//copy first values of dailyFood to max for comparing
	float max = dailyFood[0][0]; 

	//row iterate
	for (int monkey = 0; monkey < MONKEYS; monkey++) {

		//column iterate
		for(int day = 0; day < DAYS; day++) {

			//compare reminaing values and retrieve the largest
			if (dailyFood[monkey][day] > max)
				max = dailyFood[monkey][day];

		}//end of column iterate
	}//end of row iterate

	//return the most amount of food eaten by a monkey
	return max;
}//end of the getMax function


//Function displayOutput
//Display our dataset as a table to the users screen
void displayOutput(float dailyFood[][DAYS], float average, float max, float min)
{
	//set fixed point to a precision of 1 decimal place
	cout << fixed << showpoint << setprecision(1);

	//Display table for output to be used with
	cout << "Pounds of Food Eaten by Monkey and Day of Week\n" << endl;
	cout << "Monkey" << setw(6) << "Sun" << setw(7) << "Mon" << setw(7) << "Tue" << setw(7) << "Wed" 
		 << setw(7) << "Thu" << setw(7) << "Fri" << setw(7) << "Sat";

	//row iterate
	for (int monkey = 0; monkey < MONKEYS; monkey++) {

		//output number of monkeys to table
		cout << endl << right << setw(6) << monkey + 1;

		//column iterate
		for (int day = 0; day < DAYS; day++) {

			//output user input into table
			cout << setw(6) << right << dailyFood[monkey][day] << " ";

			} //end of column iterate
		} //end of row iterate
	cout << endl;
	//Output Average, Min, and Max after our table.
	cout << "\nThe average food eaten per day by all monkeys : " << average << " pounds" << endl;
	cout << "The least amount of food eaten by any monkey  : " << min << " pounds" << endl;
	cout << "The largest amount of food eaten by any monkey: " << max << " pounds" << endl;

} //end of displayOutput function
