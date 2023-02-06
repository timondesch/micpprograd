#include <utility>
#include <iostream>

class Value
{
public:
	double data;
	std::pair<Value*, Value*> prev;
	char operation;

	Value();
	Value(double);
	Value(double, std::pair<Value*, Value*>);
	Value(double, std::pair<Value*, Value*>, char);

	Value operator*(Value& v);
	Value operator+(Value& v);
	bool operator<(const Value&) const;
	
	friend std::ostream& operator<<(std::ostream&, const Value&);
};