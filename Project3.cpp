//Owen Wilborn
//Code processes a string order, checks order of valid syntax, if syntax correct reports the order number for the state code input 
//Main used for testing purposes

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

//Function declarations, all function writen after the main
bool hasValidSyntax(string); //function to test if valid stringorder, returns a bool
int countCases(string, char, int&); //Gives the total cases for the status given, for vaild inputs
bool isValidUppercaseStateCode(string); //Test if the state code is vaild, input must be all uppercase, returns a bool
int ReportStatenumber(string, int); //Reports the number after the statecode, returns an int

//Main function to test the code by hand 
int main()
{
	//declare variables to use in the main
	int caseCount = 0;
	string statushold = "A";
	char status = '0';
	int returnnumber = -1;

	//For loop to keep testing the the functions
	for (;;)
	{
		//Ask for the stringorder input
		cout << "Enter the order: ";
		string orders;
		getline(cin, orders);
		//If the order is quit exit the for loop
		if (orders == "quit")
		{
			break;
		}
		//Ask for the status to be tested
		cout << "Enter the status: ";
		getline(cin, statushold);
		status = statushold[0];
		cout << "---" << endl;
		//output the output from the functions tested
		//First check if the stringorder is vaild and return if it is or not
		if (hasValidSyntax(orders))
		{
			cout << "Is vaild order: True" << endl;
		}
		else
		{
			cout << "Is vaild order: False" << endl;
		}
		cout << "---" << endl;
		//Next find the number of cases for that status
		returnnumber = countCases(orders, status, caseCount);
		//output the number the function returns, the status and the casecount for that status
		cout << "Return number: " << returnnumber << endl;
		cout << "For status: "<< status << endl;
		cout << "Case count: " << caseCount << endl;
		cout << endl << endl;
	}
	return 0;
}

//*************************************
//  countCases
//*************************************
// Return 1 if not an ordered string, 2 if at least one state order specifies zero masks, 3 if status parameter not + or -
//Return 0 if none of three cases occur, and sets caseCount to total number for the state orders
int countCases(string orders, char status, int& caseCount)
{
	//If not vaild string return 1
	if (!hasValidSyntax(orders))
	{
		return 1;
	}
	//If any statecase has a zero report 2
	bool hasZero = false;
	int number = -1;
	int n = 0;
	int testCheck = 0;
	//Start a zero in the state order and interate to each number
	while (n < size(orders))
	{
		//If a digit and that number has not been test find the number the digit is part of
		if (isdigit(orders[n]) && testCheck==0)
		{
			number = ReportStatenumber(orders, n);
			//change testcheck to one now that that stateorder number has been test
			testCheck = 1;
			//Check if the number is zero or not for the stateorder
			if (number == 0)
			{
				hasZero = true;
			}
		}
		//once get to end of the number reset to find the next number in the next statecode
		else if (orders[n]=='-' || orders[n] == '+')
		{
		testCheck = 0;
		}
		//Move to next character in the orderstring
		n++;
	}
	//if any zero found return 2
	if (hasZero==true)
		{
			return 2;
		}

	//If parameter status not allowed report 3
	if (!(status == '+' || status == '-'))
	{
		return 3;
	}

	//Else return zero and the number of mask for the specific status input
	int totalnumber = 0;
	n = 0;
	testCheck = 0;
	//use whileloop to iterate through the orderstring
	while (n < size(orders))
	{
		//If is digit and number not tested yet
		if (isdigit(orders[n]) && testCheck == 0)
		{
			//get the number and state the number now has been found
			number = ReportStatenumber(orders, n);
			testCheck = 1;
		}
		//Else if at end of the stateorder reset testcheck to test next stateorder number
		else if (orders[n] == '-' || orders[n] == '+')
		{
			testCheck = 0;
			//if the status at the end matchs the input status add number to the total
			if (orders[n] == status)
			{
				totalnumber = totalnumber + number;
			}
		}
		//Move to next character in the string
		n++;
	}
	//set casecout to the total
	caseCount = totalnumber;
	//return zero when return the new casecount
	return 0;
}

//*************************************
//  ReportStatenumber
//*************************************
//Only use function for vaild order strings, reports the number in the string that occurs at number position given
int ReportStatenumber(string orders, int numberPosition)
{
	int number = 0;
	string currentNumberstring = "";
	//start at the first digit in stateorder and interate through it until find the first non digit
	for (int n = numberPosition; n < size(orders); n++)
	{
		//If the character is a digit add the digit to string of all digits
		if (isdigit(orders[n]))
		{
			currentNumberstring = currentNumberstring + orders[n];
		}
		//Else at end of the number so turn the string of numbers into an int
		else
		{
			stringstream store(currentNumberstring);
			store >> number;
			//return the int of the number, exit function
			return number;
		}
	}
	//If no number was made(This shouldn't happen if valid order string was sent in) the return number of zero
	return number;
}

//*************************************
//  hasVaildSyntax
//*************************************
// Return true if the argument is a is a string order, or
// false otherwise.
bool hasValidSyntax(string orders)
{
	//Set retrun variable to true to start
	bool Vaild = true;
	//Initialize variables to use in function
	string statecode = "AB";
	int numberofdigits = 0;
	int statecodestart = 0;
	int tracker = 2;
	//First Captialize all the letters in the string order string
	for (int k = 0; k < size(orders); k++)
	{
		//If letter and lower in the string make it uppercase
		if (isalpha(orders[k]) && islower(orders[k]))
		{
			orders[k] = toupper(orders[k]);
		}
	}
	//Use while loop to test all state orders in order
	while (statecodestart < size(orders))
	{
		numberofdigits = 0;
		tracker = 2;
		//If statecode less than 4 characters return false
		if (size(orders) < (statecodestart + 4))
		{
			Vaild = false;
			//cout << "Lacks string size at end" << endl;
		}
		else //Has at least 4 characters left test if it is a state order
		{
			//First find what that state code is
			statecode[0] = orders[statecodestart];
			statecode[1] = orders[statecodestart + 1];
			//Test if is a vaild state code and has a number after the state code
			if (!isValidUppercaseStateCode(statecode) || (!isdigit(orders[statecodestart + 2])))
			{
			Vaild = false;
			//cout << "Wrong state code or no number next" << endl; //used for testing purposes
			}
			//Find the number of numbers after the state code
			while (size(orders) > (statecodestart + tracker) && isdigit(orders[statecodestart + tracker]))
			{
			numberofdigits++;
			tracker++;
			}
			//Test if after the numbers an order statues exist
			if (size(orders) == (statecodestart + 2 + numberofdigits) || !(orders[statecodestart + 2 + numberofdigits] == '+' || orders[statecodestart + 2 + numberofdigits] == '-'))
			{
				Vaild = false;
				//cout<<"No order status" << endl; //used for testing purposes
			}
		}
		//Move to start of next state order
		statecodestart = statecodestart + numberofdigits + 3;
	}
	//reutnr the bool
	return Vaild;
}

//Function Below written by UCLA Professor Smallberg
//*************************************
//  isValidUppercaseStateCode
//*************************************
// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.

bool isValidUppercaseStateCode(string stateCode)
{
	const string codes =
		"AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.GU.HI.ID.IL.IN.IA.KS."
		"KY.LA.ME.MD.MA.MI.MN.MS.MO.MP.MT.NE.NV.NH.NJ.NM.NY.NC."
		"ND.OH.OK.OR.PA.PR.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
	return (stateCode.size() == 2 &&
		stateCode.find('.') == string::npos &&  // no '.' in stateCode
		codes.find(stateCode) != string::npos);  // match found
}
