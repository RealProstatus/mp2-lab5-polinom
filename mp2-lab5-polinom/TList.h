#pragma once

template<class T>
struct Node {
	T val;
	Node* pNext;
};

template<class T>
class TList {
protected:
	Node<T>* pFirst, * pLast;
	int size;
public:
	TList() {
		pFirst = pLast = nullptr;
		size = 0;
	}

	TList(const TList<T>& l) {
		size = l.size;

		Node<T> stmp = l.pFirst;
		if (stmp != nullptr) {
			pFirst = new Node<T>;
			pFirst->val = stmp->val;
			pFirst->pNext = nullptr;

			stmp = stmp.pNext;

			Node<T>* prev = pFirst;
			while (stmp != nullptr) {
				Node<T> newnode = new Node<T>;

				newnode->val = stmp->val;
				newnode->pNext - nullptr;

				prev->pNext = newnode;

				stmp = stmp->pNext;
				prev = prev->pNext;
			}

			pLast = prev;
		}
		else {
			pFirst = pLast = nullptr;
		}
	}

	~TList() {
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
};