#include <utility>
#include <iostream>

class Value
{
public:
	double data;
	std::pair<Value*, Value*> prev;
	char operation;
	char label;
	double gradient;

	Value();
	Value(double);
	Value(double, char);
	Value(double, char, std::pair<Value*, Value*>);
	Value(double, char, char, std::pair<Value*, Value*>);

	Value operator*(Value& v);
	Value operator+(Value& v);
	bool operator<(const Value&) const;
	
	friend std::ostream& operator<<(std::ostream&, const Value&);
};