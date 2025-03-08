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
	Node<T>* pCurrentNode, * pPreviousNode;
	int size;
public:
	TList() {
		pFirst = pLast = pCurrentNode = pPreviousNode = nullptr;
		size = 0;
	}

	TList(const TList<T>& l) {
		size = l.size;

		pCurrentNode = pPreviousNode = nullptr;

		Node<T>* stmp = l.pFirst;
		if (stmp != nullptr) {
			pFirst = new Node<T>;
			pFirst->val = stmp->val;
			pFirst->pNext = nullptr;

			stmp = stmp->pNext;

			Node<T>* prev = pFirst;
			while (stmp != nullptr) {
				Node<T>* newnode = new Node<T>;

				newnode->val = stmp->val;
				newnode->pNext = nullptr;

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

	TList<T>& operator=(const TList<T>& l) {
		if (this == &l) {
			return *this;
		}

		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		pFirst = pLast = pCurrentNode = pPreviousNode = nullptr;
		size = 0;

		Node<T>* stmp = l.pFirst;
		if (stmp != nullptr) {
			pFirst = new Node<T>;
			pFirst->val = stmp->val;
			pFirst->pNext = nullptr;

			stmp = stmp->pNext;

			Node<T>* prev = pFirst;
			while (stmp != nullptr) {
				Node<T>* newnode = new Node<T>;

				newnode->val = stmp->val;
				newnode->pNext = nullptr;

				prev->pNext = newnode;

				stmp = stmp->pNext;
				prev = prev->pNext;
			}
			pLast = prev;
			size = l.size;
		}
		
		return *this;
	}

	~TList() {
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}

	//-------------------------------------------------------------------

	int getSize() const {
		return size;
	}

	void clear() {
		while (pFirst != nullptr) {
			Node<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		pFirst = pLast = nullptr;
		pCurrentNode = pPreviousNode = nullptr;
		size = 0;
	}

	void insertFirst(T element) {
		Node<T>* newnode = new Node<T>;
		newnode->val = element;
		newnode->pNext = pFirst;

		if (pFirst == nullptr)
			pLast = newnode;

		pFirst = newnode;

		size++;
	}

	void deleteFirst() {
		if (size == 0) return;

		Node<T>* tmp = pFirst;
		pFirst = tmp->pNext;

		if (tmp == pCurrentNode || tmp == pPreviousNode) {
			pCurrentNode = pFirst;
			pPreviousNode = nullptr;
		}

		delete tmp;

		if (pFirst == nullptr)
			pLast = nullptr;

		size--;
	}

	void insertCurrent(T elem) {
		if (pCurrentNode == pFirst) {
			insertFirst(elem);
			pPreviousNode = pFirst; 
			return;
		}
		if (pPreviousNode == pLast) {
			insertLast(elem);
			pPreviousNode = pLast;
			return;
		}

		Node<T>* newnode = new Node<T>{ elem,pCurrentNode };
		pPreviousNode->pNext = newnode;
		pPreviousNode = pPreviousNode->pNext;
		size++;
	}

	T getCurrentValue() {
		if (pCurrentNode != nullptr) {
			return pCurrentNode->val;
		}
	}

	void deleteCurrent() {
		if (pCurrentNode == pFirst) {
			deleteFirst();
			pCurrentNode = pFirst;
			return;
		}
		if (pCurrentNode != nullptr) {
			Node<T>* tmp = pCurrentNode;
			pCurrentNode = pCurrentNode->pNext;
			delete tmp;

			pPreviousNode->pNext = pCurrentNode;
			if (pCurrentNode == nullptr)
				pLast = pPreviousNode;
			
			size--;
		}
	}

	void insertLast(T element) { 
		Node<T>* newnode = new Node<T>{element, nullptr};

		if (pLast != nullptr)
			pLast->pNext = newnode;
		else
			pFirst = newnode;
		
		pLast = newnode;
		size++;
	}

	void deleteLast() {
		if (size == 0) return;

		if (size == 1) {
			delete pFirst;
			pFirst = pLast = nullptr;
			pPreviousNode = pCurrentNode = nullptr;
		}
		else {
			Node<T>* cur = pFirst;
			while (cur->pNext != pLast) 
				cur = cur->pNext;
			
			delete cur->pNext;
			cur->pNext = nullptr;
			pLast = cur;
			if (pPreviousNode == pLast) pCurrentNode = nullptr;
		}
		size--;
	}

	//-------------------------------------------------------------------

	void reset() {
		pPreviousNode = nullptr;
		pCurrentNode = pFirst;
	}

	bool isEnd() const {
		return pCurrentNode == nullptr;
	}

	void goNext() {
		if (pCurrentNode != nullptr) {
			pPreviousNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pNext;
		}
		else return;
	}
};