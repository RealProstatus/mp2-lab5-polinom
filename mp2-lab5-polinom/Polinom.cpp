#include"Polinom.h"

Polinom::Polinom() { }

Polinom::Polinom(Monom* p, int size) {
	for (int i = 0; i < size; i++)
		insertLast(p[i]);
}

Polinom& Polinom::operator+=(Monom m) {
	if (size == 0) {
		insertLast(m);
	}
	else {
		//If the monom is less than the last one, add to the end
		if (m < pLast->val) {
			insertLast(m);
			return *this;
		}
		//If the monom is larger than the first one, add to the beginning
		if (m > pFirst->val) {
			insertFirst(m);
			return *this;
		}

		for (reset(); !(isEnd()); goNext()) {
			if (m >= pCurrentNode->val) {
				if (m != pCurrentNode->val) {
					Node<Monom>* tmp = new Node<Monom>{ m,pCurrentNode };
					pPreviousNode->pNext = tmp;
					size++;
					return *this;
				}
				else {
					pCurrentNode->val.coeff += m.coeff;
					
					if (pCurrentNode->val.coeff == 0) {
						if (pCurrentNode == pFirst) {
							Node<Monom>* tmp = pFirst;
							pFirst = pCurrentNode = pCurrentNode->pNext;
							delete tmp;
							size--;
							return *this;
						}

						pCurrentNode = pCurrentNode->pNext;
						delete pPreviousNode->pNext;
						pPreviousNode->pNext = pCurrentNode;
						size--;
						return *this;
					}
					else {
						return *this;
					}
				}
			}
		}
	}
}

Polinom& Polinom::operator+=(Polinom& p) {
	reset(); p.reset();

	while (!(isEnd()) && !(p.isEnd())) {
		if (pCurrentNode->val > p.pCurrentNode->val) {
			goNext();
		}
		else {
			if (pCurrentNode->val < p.pCurrentNode->val) {
				insertCurrent(p.pCurrentNode->val);
				p.goNext();
			}
			else {
				pCurrentNode->val.coeff += p.pCurrentNode->val.coeff;

				if (pCurrentNode->val.coeff == 0) {
					deleteCurrent();
					p.goNext();
				}
				else {
					p.goNext();
					goNext();
				}
			}
		}
	}
	while (!(p.isEnd())) {
		insertLast(p.pCurrentNode->val);
		p.goNext();
	}

	return *this;
}

Polinom& Polinom::operator-=(Monom m) {
	m.coeff *= -1;
	*this += m;

	return *this;
}

Polinom& Polinom::operator-=(Polinom p) {
	p *= -1;
	*this += p;

	return *this;
}

Polinom& Polinom::operator*=(double c) {
	if (c == 0) {
		clear();
		return *this;
	}

	if (c == 1)
		return *this;

	Node<Monom>* tmp = pCurrentNode;
	Node<Monom>* tmp1 = pPreviousNode;

	reset();
	while (!(isEnd())) {
		pCurrentNode->val.coeff *= c;
		goNext();
	}
	
	pCurrentNode = tmp;
	pPreviousNode = tmp1;
}

Polinom& Polinom::operator*=(Monom m) {
	if (m.coeff == 0) {
		clear();
		return *this;
	}

	Node<Monom>* tmp = pCurrentNode;
	Node<Monom>* tmp1 = pPreviousNode;

	reset();
	while (!(isEnd())) {
		pCurrentNode->val *= m;
		goNext();
	}

	pCurrentNode = tmp;
	pPreviousNode = tmp1;

	return *this;
}

Polinom Polinom::operator* (Monom m) {
	Polinom res(*this);

	res *= m;

	return res;
}

Polinom& Polinom::operator*=(Polinom& p) {
	Polinom tmp(*this);

	this->clear();
	p.reset();
	while (!(p.isEnd())) {
		Polinom tmpp = tmp * p.pCurrentNode->val;
		*this += tmpp;
		p.goNext();
	}

	return *this;
}

std::ostream& operator<<(std::ostream& out, Polinom& p) {
	Node<Monom>* tmp = p.pCurrentNode;
	Node<Monom>* tmp1 = p.pPreviousNode;

	p.reset();
	out << p.getCurrentValue();
	p.goNext();
	while (!(p.isEnd())) {
		out << " + " << p.getCurrentValue();
		p.goNext();
	}

	p.pCurrentNode = tmp;
	p.pPreviousNode = tmp1;

	return out;
}

std::string Polinom::getString() {
	std::ostringstream out;

	Node<Monom>* tmp = pCurrentNode;
	Node<Monom>* tmp1 = pPreviousNode;

	for (reset(); !(isEnd()); goNext()) {
		out << getCurrentValue();
	}

	pCurrentNode = tmp;
	pPreviousNode = tmp1;

	return out.str();
}
