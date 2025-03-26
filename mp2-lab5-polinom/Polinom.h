#pragma once

#include"TList.h"
#include<string>
#include<sstream>
#include<iostream>

struct Monom {
	double coeff;
	int x, y, z;

	bool operator>(const Monom& m) const {
		return (x * 100 + y * 10 + z) > (m.x * 100 + m.y * 10 + m.z);
	}
	bool operator>=(const Monom& m) const {
		return (x * 100 + y * 10 + z) >= (m.x * 100 + m.y * 10 + m.z);
	}
	bool operator<(const Monom& m) const {
		return (x * 100 + y * 10 + z) < (m.x * 100 + m.y * 10 + m.z);
	}
	bool operator<=(const Monom& m) const {
		return (x * 100 + y * 10 + z) <= (m.x * 100 + m.y * 10 + m.z);
	}
	bool operator==(const Monom& m) const {
		return (x * 100 + y * 10 + z) == (m.x * 100 + m.y * 10 + m.z);
	}
	bool operator!=(const Monom& m) const {
		return (x * 100 + y * 10 + z) != (m.x * 100 + m.y * 10 + m.z);
	}

	Monom& operator*=(const Monom& m) {
		coeff *= m.coeff;
		x += m.x;
		y += m.y;
		z += m.z;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Monom m) {
		out << m.coeff << "x^" << m.x << "y^" << m.y << "z^" << m.z;
		return out;
	}

	std::string getString() {
		std::ostringstream out;
		out << this;
		return out.str();
	}
};

class Polinom : public TList<Monom> {
public:
	Polinom();
	Polinom(Monom* p, int size);

	Polinom& operator+=(Monom m);
	Polinom& operator+=(Polinom& p);
	Polinom& operator-=(Monom m);
	Polinom& operator-=(Polinom p);
	Polinom& operator*=(double c);
	Polinom& operator*=(Monom m);
	Polinom operator* (Monom m);
	Polinom& operator*=(Polinom& p);

	friend std::ostream& operator<<(std::ostream& out, Polinom& p);
	std::string getString();
};