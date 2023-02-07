#include "Value.h"

// Constructors

Value::Value(double d) : Value::Value(d, '#', ' ', std::pair<Value*, Value*>()) {}

Value::Value(double d, char l) : Value::Value(d, l, ' ', std::pair<Value*, Value*>()) {}

Value::Value(double d, char l, std::pair<Value*, Value*> others) : Value::Value(d, l, ' ', others) {}

Value::Value(double d, char l, char op, std::pair<Value*, Value*> others) : data(d), label(l), prev(others), operation(op) {
	double tmp_grad = 0.0;
	gradient = &tmp_grad;
}


// Operator overloading

//Value Value::operator*(Value& v) {
//	std::pair<Value*, Value*> p({ this, &v });
//	Value out = Value(data * v.data, '#', '*', p);
//
//	std::function<void()> back = [this, v, out]() {
//		this->gradient = v.data * out.gradient;
//		v.gradient = this->data * out.gradient;
//	};
//
//	out.backward = back;
//
//	return out;
//}

Value Value::operator*(Value& v) {
	std::pair<Value*, Value*> p({ this, &v });
	Value out = Value(data * v.data, '#', '*', p);

	std::function<void()> back = [this, v, out]() {
		double tmp_grad = v.data * *out.gradient;
		this->gradient = &tmp_grad;
		*v.gradient = this->data * *out.gradient;
	};

	out.backward = back;

	return out;
}

Value Value::operator+(Value& v) {
	std::pair<Value*, Value*> p({ this, &v });
	Value out = Value(data + v.data, '#', '+', p);

	std::function<void()> back = [this, v, out]() {
		double tmp_grad = 1 * *out.gradient;
		this->gradient = &tmp_grad;
		*v.gradient = 1 * *out.gradient;
	};

	out.backward = back;

	return out;
}

bool Value::operator<(const Value& v) const{
	return data < v.data ? true : false;
}

Value Value:: relu() {
	std::pair<Value*, Value*> p({ this, nullptr });
	Value out = Value(this->data > 0 ? this->data : 0, '#', '/', p);

	std::function<void()> back = [this, out]() {
		*this->gradient = this->data > 0 ? 1 : 0;
	};

	out.backward = back;

	return out;
}

std::ostream& operator<<(std::ostream& out, const Value& v)
{
	out << "Value(" << v.label << " | data= " << v.data << " | gradient =" << *v.gradient << ")";
	return out;
}