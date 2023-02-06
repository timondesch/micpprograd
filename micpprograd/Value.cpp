#include "Value.h"

// Constructors

Value::Value(double d) : Value::Value(d, std::pair<Value*, Value*>(), ' ') {}

Value::Value(double d, std::pair<Value*, Value*> others) : Value::Value(d, others, ' ') {}

Value::Value(double d, std::pair<Value*, Value*> others, char op) : data(d), prev(others), operation(op) {}


// Operator overloading

Value Value::operator*(Value& v) {
	std::pair<Value*, Value*> p({ this, &v });
	return Value(data * v.data, p, '*');
}

Value Value::operator+(Value& v) {
	std::pair<Value*, Value*> p({ this, &v });
	return Value(data + v.data, p, '+');
}

bool Value::operator<(const Value& v) const{
	return data < v.data ? true : false;
}

std::ostream& operator<<(std::ostream& out, const Value& v)
{
	out << "Value(" << v.data << ")";
	return out;
}