#include <iostream>
#include "clock.h"

using namespace std;

void someFunction(const clock&);

// overloaded as free functions
bool operator== (clock, clock);
bool operator!= (clock, clock);


int main()
{
	clock pre(12, 30), post;
	
	post = pre;

	cout << ++pre << endl;	// 12:31
	cout << pre << endl;	// 12:31

	cout << post++ << endl;	// 12:30
	cout << post << endl;	// 12:31


	clock c(23, 15);
	clock startTimes[4] = { clock(12, 30), clock(16,45) , 20, clock(23, 15) };
	int arr[4] = { 3, 5, 1, -9 };

	for (int i = 0; i < 4; i++)
	{
		startTimes[i].printTime();
		cout << endl;
	}

	clock a(5, 45), b(3, 10), d;

	//d = a + b;

	//a += b;

	cout << "Enter a time: ";
	cin >> a;

	cout << a << endl;

	
	//a = b;	// byte-by-byte copy

	if (a != b)
		cout << "Not Equal";
	else
		cout << "Equal";

	if (a < b)
		cout << "clock a is before b" << endl;
	else
		cout << "clock a is after (or equal) b" << endl;




	c.addTime(95);

	c.printTime();
	cout << endl;

	someFunction(c);
	
	return EXIT_SUCCESS;
}

bool operator!= (clock lhs, clock rhs)
{
	return !(lhs == rhs);
}

bool operator== (clock lhs, clock rhs)
{
	return (lhs.getHour() == rhs.getHour() &&
		lhs.getMinute() == rhs.getMinute());
}

void someFunction(const clock& c)
{
	c.printTime();
	cout << endl;
}

/*
1:29 PM
1:29 PM
Press any key to continue . . .

*/
