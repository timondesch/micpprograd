#include "Value.h"

Value::Value(double d) {
	data = d;
}

Value::Value(double d, std::set<Value> others) : Value::Value(d) {
	prev = std::set<Value>(others);
}

Value Value::operator*(const Value& v) {
	std::set<Value> s({ *this, v });
	return Value(data * v.data, s);
}

Value Value::operator+(const Value& v) {
	std::set<Value> s({ *this, v });
	return Value(data + v.data, s);
}

bool Value::operator<(const Value& v) const{
	return data < v.data ? true : false;
}

std::ostream& operator<<(std::ostream& out, const Value& v)
{
	out << "Value(" << v.data << ")" << std::endl;
	return out;
}