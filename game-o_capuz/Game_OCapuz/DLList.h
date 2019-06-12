#pragma once
#ifndef NULL
#define NULL 0x0
#endif

//Doubly Linked List template
template <class TYPE>
class DLList
{
private:

	template <class T> 
	class Element
	{
	private:
		Element<T>* _pNext;
		Element<T>* _pPrevious;
		T _Object;

		Element() { } 
	public:
		Element(T Objt) : _Object (Objt) 
		{ 
			_pNext = NULL; 
			_pPrevious = NULL;
		}
		~Element()
		{ 
			_pNext = NULL; 
			_pPrevious = NULL; 
		}

		void setpNext(Element<T>* pNext) { _pNext = pNext; }
		Element<T>* getpNext() const { return _pNext; }

		void setpPrev(Element<T>* pPrev) { _pPrevious = pPrev; }
		Element<T>* getpPrev() const { return _pPrevious; }

		void setObjt(const T& Objt) { _Object = &Objt; }
		T& getObjt() { return _Object; }
	};

	Element<TYPE>* _pTop;
	Element<TYPE>* _pEnd;
	unsigned int size;

public:
	// / / / / / / Iterator / / / / / / / /
	class iterator
	{
	public:
		friend class DLList<TYPE>;
		typedef TYPE& reference;
		typedef Element<TYPE>* pointer;

		iterator() : _elem(NULL)
		{
		}
		iterator(pointer ptr) : _elem(ptr)
		{
		}
		reference operator*()
		{
			return (_elem->getObjt());
		}
		reference operator->()
		{
			return (*(*this));
		}

		// iterator++;
		iterator& operator++()
		{
			if (_elem)
			{
				_elem = _elem->getpNext();
			}
			return (*this);
		}

		iterator operator++ (int)
		{
			iterator it = *this;
			++(*this);
			return it;
		}

		iterator& operator--()
		{
			if (_elem)
			{
				_elem = _elem->getpPrev();
			}
			return (*this);
		}

		iterator operator--(int)
		{
			iterator it = *this;
			--(*this);
			return it;
		}

		bool operator != (const iterator& iterator) const
		{
			return (_elem != iterator._elem);
		}

		bool operator == (const iterator& iterator) const
		{
			return (_elem == iterator._elem);
		}

	private:
		pointer _elem;
	};

	DLList() { _pTop = NULL; _pEnd = NULL; size = 0; }
	~DLList() { clear(); }

	void clear()
	{
		while (!empty())
			popFront();
		_pEnd = NULL;
	}

	void popFront()
	{
		if (!empty())
		{
			Element<TYPE>* pElAux = _pTop;
			_pTop = _pTop->getpNext();
			delete pElAux;
			if (size == 1)
				_pEnd = NULL;
			size--;
		}
	}

	void popBack()
	{
		if (!empty())
		{
			Element<TYPE>* pElAux = _pEnd;
			_pEnd = _pEnd->getpPrev();
			delete pElAux;
			if (size == 1)
				_pTop = NULL;
			size--;
		}
	}

	void pushFront(TYPE Objt)
	{
		if (empty())
		{
			_pTop = new Element<TYPE>(Objt);
			_pEnd = _pTop;
		}
		else
		{
			Element<TYPE>* pAux = _pTop;
			_pTop = new Element<TYPE>(Objt);
			_pTop->setpNext(pAux);
			pAux->setpPrev(_pTop);
		}
		size++;
	}

	void pushBack(TYPE Objt)
	{
		if (empty())
		{
			_pEnd = new Element<TYPE>(Objt);
			_pTop = _pEnd;
		}
		else
		{
			Element<TYPE>* pAux = _pEnd;
			_pEnd = new Element<TYPE>(Objt);
			_pEnd->setpPrev(pAux);
			pAux->setpNext(_pEnd);
		}
		size++;
	}

	iterator begin()
	{
		return iterator(_pTop);
	}

	const iterator begin() const
	{
		return iterator(_pTop);
	}

	iterator end()
	{
		return NULL;
	}

	const iterator end() const
	{
		return NULL;
	}

	void erase(iterator it)
	{
		if (it == begin())
		{
			popFront();
		}
		else if (it._elem == _pEnd)
		{
			popBack();
		}
		else
		{
			Element<TYPE>* pAux = it._elem;
			while (pAux->getObjt() != it._elem->getObjt())
			{
				pAux = pAux->getpNext();
			}
			pAux->getpPrev()->setpNext(pAux->getpNext());
			pAux->getpNext()->setpPrev(pAux->getpPrev());
			delete pAux;
			size--;
		}
	}

	bool remove(TYPE Objt)
	{
		for (iterator it = begin(); it != end(); it++)
		{
			if ((*it) == Objt)
			{
				erase(it);
				break;
			}
		}
	}

	unsigned int getSize() { return size; }
	bool empty() { if (size) return false; return true; }
};