#include"Polinom.h"

Polinom::Polinom(Monom* p, int size) {
	for (int i = 0; i < size; i++)
		insertLast(p[i]);
}

void Polinom::operator+=(Monom m) {
	if (size == 0) {
		insertLast(m);
	}
	else {
		//If the monom is less than the last one, add to the end
		if (m < pLast->val) {
			insertLast(m);
			return;
		}
		//If the monom is larger than the first one, add to the beginning
		if (m > pFirst->val) {
			insertFirst(m);
			return;
		}

		//Placeholder for main loop
		//TODO after releasing iterator for list
	}
}