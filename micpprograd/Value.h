#include <set>
#include <iostream>

class Value
{
public:
	double data;
	std::set<Value> prev;
	//char operation;

	Value(double);
	Value(double, std::set<Value>);

	Value operator*(const Value&);
	Value operator+(const Value&);
	bool operator<(const Value&) const;
	
	friend std::ostream& operator<<(std::ostream&, const Value&);
};