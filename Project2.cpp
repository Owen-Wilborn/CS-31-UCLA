//Owen Wilborn
//Calculates total tax owed by a person based on taxable income, occupation, and number of children input.
//Tax calculated based on a model using different tax rates for different income amounts and employment sector and uses varying child deductible amounts

#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*Collect all inputs*/
	//Name Input
	cout << "Name: ";
	string personsName;
	getline(cin, personsName);

	//Taxable Income Input
	cout << "Taxable income: ";
	double taxincome;
	cin >> taxincome;
	cin.ignore(10000, '\n');

	//Occupation Input
	cout << "Occupation: ";
	string occupation;
	getline(cin, occupation);

	//Childern Input
	cout << "Number of children: ";
	double childern;
	cin >> childern;
	cin.ignore(10000, '\n');
	cout <<"---"<< endl;

	/*Check for all errors*/
	//Check if name slot is empty
	if (personsName == "")
	{
		cout << "You must enter a name" << endl;
		return 0;
	}
	//Check is income is negative
	else if (taxincome < 0)
	{
		cout << "The taxable income must be nonnegative" << endl;
		return 0;
	}
	//Check if occupation is empty
	else if (occupation == "")
	{
		cout << "You must enter an occupation" << endl;
		return 0;
	}
	//Check if number of childern is negative
	else if (childern < 0)
	{
		cout << "The number of children must be nonnegative" << endl;
		return 0;
	}

	/*All valid inputs calculate the tax*/
	double tax=0;
	//First find child deduction amount
	if (taxincome < 120000)
	{
		tax = -200 * childern;
	}

	//Next remove tax for first tax bracket
	const double taxrate1 = 0.04;
	if (taxincome <= 50000)
	{
		tax = taxincome * taxrate1 + tax;
		taxincome = 0;
	}
	else
	{
		tax = 50000 * taxrate1 + tax;
		taxincome = taxincome - 50000;
	}

	//Next remove tax for the second tax bracket
	double taxrate2 = 0;
	//Find the tax rate in the second bracket based on occupation
	if (occupation == "engineer" || occupation == "scientist")
	{
		taxrate2 = 0.05;
	}
	else
	{
		taxrate2 = 0.06;
	}
	//Find the amount of tax based on the salary in the second bracket
	if (taxincome <= 70000)
	{
		tax = taxincome * taxrate2 + tax;
		taxincome = 0;
	}
	else
	{
			tax = 70000 * taxrate2 + tax;
			taxincome = taxincome - 70000;
	}

	//Find tax in the third bracket
	const double taxrate3 = 0.09;
	if (taxincome > 0)
	{
		tax = taxincome * taxrate3 + tax;
	}

	//If the final tax is negative set to zero
	if (tax<0)
	{
		tax = 0;
	}

	//Print the output to 2 decimal places in the money number
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << personsName << " would pay $" << tax << endl;

	//End Code
	return 0;
}
