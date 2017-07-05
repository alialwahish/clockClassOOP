
#include <cassert>
#include <iostream>

using namespace std;

class clock
{
public:
	// constructor
	clock(int = 0, int = 0);  // default arguments

	// overloaded operators
	clock operator++();			// pre-fix
	clock operator++(int);		// post-fix


	bool operator<(const clock&);
	bool operator<=(const clock& rhs) { return totalMinutes() <= rhs.totalMinutes(); }
	bool operator>(const clock& rhs) { return totalMinutes() > rhs.totalMinutes(); }
	bool operator>=(const clock& rhs) { return totalMinutes() >= rhs.totalMinutes(); }

	clock operator+(const clock&);
	clock operator+(int);
	clock operator += (const clock&);

	// overloaded as "friend" functions
	friend ostream& operator<<(ostream&, const clock&);
	friend istream& operator>>(istream&, clock&);

	// set and get functions
	int getHour() { return hour; }
	int getMinute() { return minute;  }	// inline functions

	void setHour(int);
	void setMinute(int);

	void addTime(int m);	

	void printTime() const;

private:
	int hour;
	int minute;
	int totalMinutes() const { return hour * 60 + minute; }
};

clock clock::operator++(int)
{
	// increment clock but return the original
	clock temp;

	temp = *this;	// copy current clock

	addTime(1);

	return temp;
}

clock clock::operator++()
{
	// increment clock by one minute & return
	addTime(1);
	return *this;
}

istream& operator >> (istream& istr, clock& rhs)
{
	// clock come in format hh:mm
	int h, m;
	char temp;

	istr >> h >> temp >> m;

	rhs.setHour(h);
	rhs.setMinute(m);

	return istr;
}

ostream& operator<<(ostream& ostr, const clock& rhs)
{
	ostr << rhs.hour << ":" << rhs.minute;

	return ostr;
}


clock clock::operator+(int m)
{
	clock temp;

	temp = *this;		// copy lhs
	//temp.addTime(m);

	return temp;
}

clock clock::operator+=(const clock& rhs)
{
	// a += b;
	// a = a + b
	// "this" is a pointer to the calling object (or lhs)
	*this = *this + rhs;
	return *this;

	// or addTime(rhs.totalMinutes);
}

clock clock::operator+(const clock& rhs)
{
	// am I changing lhs?
	clock temp;		// 0:00 or 12:00 am

	temp.addTime(rhs.totalMinutes());	// or temp = rhs;
	temp.addTime(totalMinutes());

	return temp;
}


bool clock::operator<(const clock &rhs)
{
	// lhs is the object that is calling this function
	// hour, minute
	//int lhsMinutes = hour * 60 + minute;
	//int rhsMinutes = rhs.hour * 60 + rhs.minute;

	return (totalMinutes() < rhs.totalMinutes());
}

// class implementation
void clock::addTime(int m)
{
	// post - condition: clock will be m minutes in future
	minute += m;

	int xHours = minute / 60;

	minute %= 60;

	hour = (hour + xHours) % 24;
}

clock::clock(int h, int m)
{
	setHour(h);
	setMinute(m);
}

void clock::printTime() const
{
	if (hour == 0)
		cout << "12";
	else if (hour < 13)
		cout << hour;
	else
		cout << (hour - 12);

	cout << ":";

	if (minute < 10)
		cout << "0";
	cout << minute;

	if (hour >= 12)
		cout << " PM";
	else 
		cout << " AM";
}

// class implementation
void clock::setHour(int h)
{
	assert(h >= 0 && h <= 23);
	hour = h;
}

void clock::setMinute(int m)
{
	assert(m >= 0 && m <= 59);
	minute = m;
}
