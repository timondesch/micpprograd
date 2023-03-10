#include <utility>
#include <iostream>
#include <functional>

class Value
{
public:
	double data;
	std::pair<Value*, Value*> prev;
	char operation;
	char label;
	double* gradient;
	std::function<void()> backward;

	Value();
	Value(double);
	Value(double, char);
	Value(double, char, std::pair<Value*, Value*>);
	Value(double, char, char, std::pair<Value*, Value*>);

	Value operator*(Value& v);
	Value operator+(Value& v);
	bool operator<(const Value&) const;

	Value relu();

	friend std::ostream& operator<<(std::ostream&, const Value&);
};