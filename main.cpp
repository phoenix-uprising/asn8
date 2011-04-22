/*************************************************************************
 * AUTHOR		 : Chris Hayes
 * STUDENT ID	 : 656960
 * ASSIGNMENT #8 : Loops & Boolean Expressions
 * CLASS		 : CS1A
 * SECTION		 : MW4:30
 * DUE DATE		 : 05-03-11
 *************************************************************************/

//TEST CHANGE

// Preprocessor Directives
#include <iostream>
#include <iomanip>
using namespace std;

/**************************************************************************
 * 	Loops & Boolean Expressions
 *
 * ________________________________________________________________________
 * This program receives the gender, height, and weight and outputs whether
 * 	the applicant was accepted or denied due to the height, weight, or both
 * 	as well as the total number accepted and percentage.
 *
 * ________________________________________________________________________
 * INPUTS:		gender			: Gender of the applicant
 * 				weight			: Weight of the applicant
 * 				height			: Height of the applicant
 *
 * OUTPUTS:		Accepted		: Total number of accepted candidates
 * 				percentAccepted	: Percentage of accepted applicants
 *
 *************************************************************************/

int main()
{
	/*********************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------
	 * PROGRAMMER 	: Programmer's Name
	 * CLASS 	 	: Student's Course
	 * SECTION	 	: Class Days and Times
	 * ASN_NUM	 	: Assignment Number (specific to this lab)
	 * ASN_NAME 	: Title of the Assignment
	 *********************************************************************/

	const char PROGRAMMER[30] = "Chris Hayes";
	const char CLASS[5] = "CS1A";
	const char SECTION[25] = "MW: 4:30p - 6:00p";
	const int ASN_NUM = 8;
	const char ASN_NAME[28] = "Loops & Boolean Expressions";

	//VARIABLES

	char gender;			//Gender of applicant
	int height;				//Height of applicant
	int minHeight;			//Minimum height accepted
	int maxHeight;			//Maximum height accepted
	int weight;				//Weight of applicant
	int minWeight;			//Minimum weight accepted
	int maxWeight;			//Maximum weight accepted
	int accepted;			//Number accepted
	int totApplied;			//Total applied
	bool heightOk;			//Applicant meets height requirement
	bool weightOk;			//Applicant meets weight requirement
	bool validInput;		//Check for valid input

	//OUTPUT - Class Heading
	cout << left;
	cout << "******************************************************";
	cout << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n*  " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n*  " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n*  Assignment #" << setw(2) << ASN_NUM << ": " << ASN_NAME;
	cout << "\n******************************************************\n\n";
	cout << right;

	//Initialize counters
	totApplied = 0;
	accepted = 0;

	//PROMPT - begin entering candidate's information
	cout << "Please enter the candidateÕs information ";
	cout << "(enter ÔXÕ to exit). \n";

	//INPUT - gender (LCV)
	do
	{
		validInput = true;

		cout << "Gender: ";
		cin.get(gender);
		cin.ignore(100,'\n');

		//OUTPUT - error if not a valid gender
		if(gender != 'M' && gender != 'm' &&
			gender != 'F' && gender != 'f' &&
			gender != 'X' && gender != 'x')
		{
			cout << "***** Invalid gender; please enter M or F *****";
			cout << endl;
			validInput = false;
		}
	}while(!validInput);

	while(gender != 'X' && gender != 'x')
	{
		//count number applied
		totApplied = totApplied + 1;

		//set min and max for height and weight based on gender
		if(gender == 'M' || gender == 'm')
		{
			minHeight = 62;
			maxHeight = 78;
			minWeight = 130;
			maxWeight = 250;
		}
		else
		{
			minHeight = 60;
			maxHeight = 72;
			minWeight = 110;
			maxWeight = 185;
		}

		//get height
		do
		{
			validInput = true;

			cout << "Height: ";
			cin >> height;
			cin.ignore(100, '\n');

			//output error if not within range
			if(height < 24 || height > 110)
			{
				cout << "***** Invalid height; please enter a height ";
				cout << "in inches between 24 and 110. ***** \n";
				validInput = false;
			}
		}while(!validInput);

		//check height
		heightOk = (height >= minHeight && height <= maxHeight);

		//get weight
		do
		{
			validInput = true;

			cout << "Weight: ";
			cin >> weight;
			cin.ignore(100, '\n');

			//output error if not within range
			if(weight < 50 || weight > 1400)
			{
				cout << "***** Invalid weight; please enter a weight";
				cout << " in lbs between 50 and 1400. *****\n";
				validInput = false;
			}
		}while(!validInput);

		//get weight
		weightOk = (weight >= minWeight && weight <= maxWeight);

		//spacing
		cout << endl;

		//candidate accepted
		if(heightOk && weightOk)
		{
			accepted = accepted + 1;
			cout << "This Candidate has been accepted.";

		}
		else
		{
			//weight rejected
			if(heightOk)
			{
				cout << "This candidate has been rejected based on";
				cout << " the weight requirement.";
			}
			else
			{
				//height rejected
				if(weightOk)
				{
					cout << "This candidate has been rejected based ";
					cout << "on the height requirement.";
				}
				//both rejected
				else
				{
					cout << "This candidate has been rejected based ";
					cout << "on the height and weight requirement";
				}
			}
		}
		cout << endl << endl << endl;

		//PROMPT - begin entering candidate's information
		cout << "Please enter the candidateÕs information ";
		cout << "(enter ÔXÕ to exit). \n";

		//change LCV
		do
		{
			validInput = true;

			cout << "Gender: ";
			cin.get(gender);
			cin.ignore(100,'\n');

			//OUTPUT - error if not a valid gender
			if(gender != 'M' && gender != 'm' &&
					gender != 'F' && gender != 'f' &&
					gender != 'X' && gender != 'x')
			{
				cout << "***** Invalid gender; please enter M or F *****";
				cout << endl;
				validInput = false;
			}
		}while(!validInput);
	}

	//error checking totApplied for 0
	if(totApplied != 0)
	{
		cout << endl << accepted << " candidates accepted!";
		cout << setprecision(2) << fixed;
		cout << endl << "That's " << (accepted / float(totApplied)) * 100;
		cout << "%!";
	}

	return 0;
}
