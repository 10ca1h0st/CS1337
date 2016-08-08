//******************************************************************
// LoneStar Shipping Application
// Programmer: Ian Olsen
// Completed : 7/7/2016
// Status    : Complete
// Description
// This program accepts package dimensions
// and calculates a price based on their weight. 
//******************************************************************


#include <iostream>		// input/output declarations
#include <iomanip>		// i/o manipulator declarations
#include <string>		//usage of string declaration

using namespace std;

//Constant Array Values
const int weight[] = { 1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50 };
const double shippingCost[] = { 1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.40, 27.30, 31.90, 38.50, 43.50, 44.80, 47.40, 55.20 };

//Function Prototypes
int calcLarge(int, int, int);
int getGirth(int, int, int, int);
string getStatus(int, int);
void displayData(int, string, int, double);
void displayAcceptance(int, int);
int searchWeight(const int[], int);


int main()
{
	int length;				//length of package
	int width;				//width of package
	int height;				//height of package
	double packageWeight;	//overall weight of package
	int   transNum = 0;		//amount of transactions
	int largeSide;			//largest side of package
	int girth;				//girth of package
	string packageStatus;	//Accepted or Rejected package
	int badPackage = 0;		//bad package counter
	int goodPackage = 0;	//good package counter
	double packageCost;		//cost of package
	int getPosition;		//search array placer

//Begin main loop to get package information
	cout << "For each transaction, enter package weight and 3 dimensions." << endl;
	cout << "Enter -1 to quit." << endl;

	while(true) {  	
		cout << "Enter package weight and 3 dimensions: ";
		cin >> packageWeight; 

		//When -1 is entered break the loop
		if (packageWeight == -1) {
			break;
		}

		//Get the sides of package
		cin >> length >> width >> height;

		//Input Validation: prevent 0 or negative numbers.
		if ((packageWeight <= 0) || (length <= 0) || (height <= 0) || (width <= 0)) {
			cout << "\nError - package weight and dimensions must be larger than 0" << endl;
			cout << "Please re-enter transaction\n" << endl;
			//Break program if -1 is entered.
			if (packageWeight == -1) {
				break;
			}
			//Continue on to the loop
			continue;
		}

		//Collect amount of times loop runs through user input.
		transNum++;

		//Call calcLarge to get the package's largest side
		largeSide = calcLarge(length, width, height);

		//Call getGirth to get the package's girth
		girth = getGirth(length, width, height, largeSide);

		//Call packageStatus to get status of package
		packageStatus = getStatus(girth, packageWeight);


		//Calculate number of accepted and rejected packages
		if (packageStatus == "Rejected") {
			//Accumulate number of rejected packages
			badPackage++;
			//Placement for hypen in displayData
			packageCost = 1;

		}
		else{
			//Accumulate number of accepted packages
			goodPackage++;

			//Search and retrieve weight vs the array placement
			getPosition = searchWeight(weight, packageWeight);

			//Retrieve placement from shipping array for calculating the cost
			packageCost = shippingCost[getPosition];
		}

		//Call function displayData to output the table of data
		displayData(transNum, packageStatus, packageWeight, packageCost);
	}
	//Call displayAcceptance to output final number of accepted and rejected packages
	displayAcceptance(goodPackage, badPackage);
	return 0;
}

//Function calcLarge
//Purpose: calculate largest side of the package
int calcLarge(int side1, int side2, int side3)
{
	
	int large = 0; //Set variable to be returned
	
	//Calculate which side is largest
	//Side 1 is largest
	if (side1 > side2 && side1 > side3) {
		large = side1;
	}
	//Side 2 is largest
	else if (side2 > side1 && side2 > side3) {
		large = side2;
	}
	//Side 3 is largest
	else if (side3 > side1 && side3 > side2) {
		large = side3;
	}

	//return largest side
	return large;
}

//Function getGirth
//Calculate and return the girth of the package
int getGirth(int l, int w, int h, int large)
{
	int girth; //Set the girth to be returned
	
	//Caluclate final girth of each package
	girth = 2 * ((l + w + h) - large);

	//Return the girth
	return girth;
}

//Function getStatus
//Purpose: Determine if a package is acceptable or rejected.
string getStatus(int girth, int packageWeight)
{
	string status; //set the status to be returned

	//If girth is greater than 60 inches and weight is greater than 50 lbs, reject the package
	if ((girth > 60) || (packageWeight > 50)) {
		status = "Rejected";
	}
	//Package is good otherwise
	else {
		status = "Accepted";
	}
	
	//Return the status of each package
	return status;
}

//Function displayData
//Purpose: Output the data from our loop to the user for each transaction
void displayData(int transNum, string status, int packageWeight, double packageCost)
{
	//Output our data from the loop
	cout << endl;
	cout << left << setw(11) << "Transaction" << ":" << right << setw(10) << transNum << endl;
	cout << left << setw(11) << "Status" << ":" << right << setw(10) << status << endl;
	cout << left << setw(11) << "Weight" << ":" << right << setw(10) << packageWeight << endl;
	//If the package cost is rejected a hypen is entered for the cost
	if (packageCost == 1)
		cout << left << setw(11) << "Cost " << ":" << right << setw(10) << "-" << endl;
	else
		cout << left << setw(11) << "Cost " << ":" << right << setw(10) << fixed << setprecision(2) << packageCost << endl;
	cout << endl;
}


//Function displayAcceptance
//Purpose: display amount of packages accepted and amount rejected
void displayAcceptance(int goodPackage, int badPackage)
{

	cout << endl;
	//Output the accepted packages and then the rejected packages
	cout << "Number of Accepted packages: " << goodPackage << endl;
	cout << "Number of Rejected packages: " << badPackage << endl;
}

//Function searchWeight
//Purpose: search the weight array for corressponding package cost
//and return amount that is rounded up.
int searchWeight(const int weight[], int packageWeight)
{

	int arrayPosition = 0;		//holder variable for the index location of weight compared to shipping charge

	//Loop through our array that has 15 values
	for (int i = 0; i < 15; i++) {

		//If the packageWeight is equal to weight, retrieve the value
		if (packageWeight == weight[i]) {
			arrayPosition = i;
			break;
		}

		//If packageWeight is less than position of our array, continue the for loop
		if (packageWeight > weight[i]) {
			continue;
		}

		//Else set the packkageWeight equal to the weight position and return that value
		else {
			packageWeight = weight[i];
			arrayPosition = i;
			break;
		}	
	}

	//Return the shippingCost array position that matches the weight aray position
	return arrayPosition;
}
