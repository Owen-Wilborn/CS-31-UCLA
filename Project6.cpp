#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

//Functions
//Part 1B (Completed)
void findDisorder(int arr[], int n, int* &p)
{
	for (int k = 1; k < n; k++)
	{
		if (arr[k] < arr[k - 1])
		{
			p = arr + k;
			return;
		}
	}
	p = nullptr;
}

//Part 1C (Completed)
void hypotenuse(double leg1, double leg2, double* resultPtr)
{
	*resultPtr = sqrt(leg1 * leg1 + leg2 * leg2);
}

//Part 1D (Completed)
bool match(const char str1[],const char str2[])
{
	while (*str1 != 0 && *str2 != 0)  // zero bytes at ends
	{
		if (*str1 != *str2)  // compare corresponding characters
			return false;
		str1++;
		str2++;   // advance to the next character
	}
	return *str1 == *str2; // both ended at same time?
}

//Part 1E (Completed)
int* computeSquares(int& n)
{
	int arr[10];
	n = 10;
	for (int k = 0; k < n; k++)
	{
		arr[k] = (k + 1) * (k + 1);
		cout << arr[k]<<" ";
	}
	cout << endl;
		return arr;
}

//Part 2
int* computeSquares2(int& n, int arr[])
{
	n = 10;
	for (int k = 0; k < n; k++)
		arr[k] = (k + 1) * (k + 1);
	return arr;
}
 //Part 2
void f()
{
	int junk[100];
	for (int k = 0; k < 100; k++)
		junk[k] = 123400000 + k;
}
//Part 3A
double computeAverage(const double* scores, int nScores)
{
	int i = 0;
	const double* ptr = scores;
	double tot = 0;
	while (i< nScores)
	{
		tot += *(ptr+i);
		i++;
	}
	return tot / nScores;
}
//Part 3B
const char* findTheChar(const char* str, char chr)
{
	for (int k = 0; *(str + k) != 0; k++)
	{
		if (*(str + k) == chr)
			return str + k;
	}
	return nullptr;
}

//Part 3C
const char* findTheChar2(const char* str, char chr)
{
	while (*str != 0)
	{
		if (*(str) == chr)
			return str;
		str++;
	}
	return nullptr;
}

//Part 4
int* minimart(int* a, int* b)
{
	if (*a < *b)
		return a;
	else
		return b;
}

//Part 4
void swap1(int* a, int* b)
{
	int* temp = a;
	a = b;
	b = temp;
}

//Part 4
void swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Part 5
void deleteG(char* msg)
{
	char* local = msg;	//One additional local variable of pointer type
	while (*msg != 0)
	{
		if (*(msg) == 'g' || *(msg) == 'G')
		{
			local = msg;
			while (*(local+1) != 0)
			{
				*local = *(local+1);
				local++;
			}
			*(local) = '\0';	
		}
		else
		{
			msg++;
		}
	}
	return;
}

//Main function
int main()
{
	int done = 0;
	while (done == 0)
	{
		int Prob = 0;
		cout << "What problem to solve 1=1A, 2=1B, 3=1C, 4=1D, 5=1E, 6=2, 7=3A, 8=3B, 9=3C, 10=4, 11=5:  ";
		cin >> Prob;
		cout << "---" << endl;

		switch (Prob)
		{
		case 1: // Part 1A Completed
		{
			int arr[3] = { 5, 10, 15 };
			int* ptr = arr;
			*ptr = 10;          // set arr[0] to 10
			*(ptr + 1) = 20;      // set arr[1] to 20
			ptr += 2;
			ptr[0] = 30;        // set arr[2] to 30

			while (ptr >= arr)
			{
				cout << ' ' << *ptr;    // print values
				ptr--;
			}
			cout << endl;
			break;
		}
		case 2: //Part 1B Completed
		{
			int nums[6] = { 10, 20, 20, 40, 30, 50 };
			int* ptr=nullptr;

			findDisorder(nums, 6, ptr);
			if (ptr == nullptr)
				cout << "The array is ordered" << endl;
			else
			{
				cout << "The disorder is at address " << ptr << endl;
				cout << "It's at position " << ptr - nums << endl;
				cout << "The item's value is " << *ptr << endl;
			}
			break;
		}
		case 3: //Part 1C Completed
		{
			double p;
			hypotenuse(1.5, 2.0, &p);
			cout << "The hypotenuse is " << p << endl;
			break;
		}
		case 4: //Part 1D // return true if two C strings are equal
		{
			char a[10] = "pointa";
			char b[10] = "pointy";
			if (match(a, b))
				cout << "They're the same!\n";
			break;
		}
		case 5: //Part 1E
		{
			int m;
			int* ptr = computeSquares(m);
			f();
			for (int i = 0; i < m; i++)
				cout << ptr[i] << ' ';
			//Fixed version
			cout << endl;
			int m2;
			int arr[10];
			int* ptr2 = computeSquares2(m2, arr);
			f();
			for (int i = 0; i < m2; i++)
				cout << ptr2[i] << ' ';
			cout << endl;
			break;
		}
		case 6: //Part 2
		{
			string* fp; //A
			string fish[5]; //B
			fp = &fish[4]; //C
			*fp = "yellowtail";  //D
			*(fish + 3) = "salmon";//E
			fp -= 3;//F
			fp[1] = "basa";//G
			fp[0] = "sole"; //H
			bool d = (fp == fish); //i
			bool b = (*fp == *(fp + 1)); //j
			for (int i = 0; i < 5; i++)
			{
				cout << fish[i] << endl;
			}
			if (d)
				cout << "d is true" << endl;
			else
				cout << "d is false" << endl;
			if (b)
				cout << "b is true" << endl;
			else
				cout << "b is false" << endl;
			break;
		}
		case 7: //Part 3
		{
			double num[3] = { 4,5,6 };
			double avg = computeAverage(num, 3);
			cout << avg << endl;
			break;
		}
		case 8: //Part 3
		{
			char chr = 'h';
			char str[4] = {'j','h','i','\0'};
			char* H = &str[0];
			const char* A = findTheChar(H, chr);
			if (A == nullptr)
				cout << "Null" << endl;
			else
				cout << *A << endl;
			break;
		}
		case 9: //Part 3
		{
			char chr = 'r';
			char str[4] = { 'j','h','i','\0' };
			char* H = &str[0];
			const char* A = findTheChar2(H, chr);
			if (A == nullptr)
				cout << "Null" << endl;
			else
				cout << *A << endl;
			break;
		}
		case 10: //Part 4
		{
			int array[6] = { 5, 3, 4, 17, 22, 19 };

			int* ptr = minimart(array, &array[2]);
			ptr[1] = 9;
			ptr += 2;
			*ptr = -1;
			*(array + 1) = 79;
			
			cout << "diff=" << &array[5] - ptr << endl;

			swap1(&array[0], &array[1]);
			swap2(array, &array[2]);

			for (int i = 0; i < 6; i++)
				cout << array[i] << endl;
			break;
		}
		case 11: //Part 5
		{
			char msg[100] = "I recall the glass gate next to Gus in Lagos, near the gold bridge.";
			cout << msg << endl;
			cout << "I recall the lass ate next to us in Laos, near the old bride." << endl;
			deleteG(msg);
			cout << msg << endl;  // prints   I recall the lass ate next to us in Laos, near the old bride.
			char hey[100] = "ggheyGGgg";
			deleteG(hey);
			cout << hey << endl;
			break;
		}
		default:
		{
			cout << "Didn't enter a valid problem number" << endl;
		}
		}
		string Check;
		cout << "Enter 1 to run program again, or any key to close the program: ";
		cin.ignore(10000, '\n');
		getline(cin, Check);
		if (Check == "1")
		{
			done = 0;
			cout<<endl;
		}
		else
		{
			done = 1;
		}
	}
}