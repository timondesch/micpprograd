#include "Value.h"
#include <set>

Value& Value::operator*(const Value& v) {
	return Value(data * v.data);
}

Value& Value::operator+(const Value& v) {
	return Value(data + v.data);
}

std::ostream& operator<<(std::ostream& out, const Value& v)
{
	out << "Value(" << v.data << ")" << std::endl;
	return out;
}