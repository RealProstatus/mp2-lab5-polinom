#pragma once

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
};