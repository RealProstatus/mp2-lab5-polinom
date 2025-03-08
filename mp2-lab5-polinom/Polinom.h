#pragma once

#include"TList.h"

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
	}
};

class Polinom : public TList<Monom> {
public:
	//for debug and tests only
	Polinom();
	Polinom(Monom* p, int size);

	Polinom& operator=(const Polinom& p);

	Polinom& operator+=(Monom m);
	Polinom& operator+=(Polinom& p);
	Polinom& operator*=(double c);
	Polinom& operator*=(Monom m);
	Polinom operator* (Monom m);
	Polinom& operator*=(Polinom& p);
};