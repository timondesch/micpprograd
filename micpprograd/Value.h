#include <set>
#include <iostream>

class Value
{
public:
	double data;
	//std::set<Value&> prev;
	//char operation;

	Value(double d) : data(d) {};

	Value& operator*(const Value&);
	Value& operator+(const Value&);
	
	friend std::ostream& operator<<(std::ostream&, const Value&);
};