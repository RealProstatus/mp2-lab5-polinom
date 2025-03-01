#include"Polinom.h"

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
				}
			}
		}
	}
}