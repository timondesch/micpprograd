#include "Value.h"

// Constructors

Value::Value(double d) : Value::Value(d, '#', ' ', std::pair<Value*, Value*>()) {}

Value::Value(double d, char l) : Value::Value(d, l, ' ', std::pair<Value*, Value*>()) {}

Value::Value(double d, char l, std::pair<Value*, Value*> others) : Value::Value(d, l, ' ', others) {}

Value::Value(double d, char l, char op, std::pair<Value*, Value*> others) : data(d), label(l), prev(others), operation(op), gradient(0) {}


// Operator overloading

Value Value::operator*(Value& v) {
	std::pair<Value*, Value*> p({ this, &v });
	return Value(data * v.data, '#', '*', p);
}

Value Value::operator+(Value& v) {
	std::pair<Value*, Value*> p({ this, &v });
	return Value(data + v.data, '#', '+', p);
}

bool Value::operator<(const Value& v) const{
	return data < v.data ? true : false;
}

std::ostream& operator<<(std::ostream& out, const Value& v)
{
	out << "Value(" << v.label << " | data= " << v.data << " | gradient =" << v.gradient << ")";
	return out;
}