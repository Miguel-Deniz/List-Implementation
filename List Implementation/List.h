#pragma once

#include <exception>

#include <stdexcept>

int addOne(int x)
{

	return x;
}

template<class Elem> struct Link
{
	Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0)
		:_prev(p), _succ(s), _val(v)
	{}

	Link* _prev;
	Link* _succ;
	Elem  _val;
};

template<class T> class List
{
public:
	List()
	{
		_firstLink = new Link<T>();
		_lastLink = new Link<T>();

		_firstLink->_prev = 0;
		_firstLink->_succ = _lastLink;

		_lastLink->_prev = _firstLink;
		_lastLink->_succ = 0;
		_size = 0;
	}

	List(const List<T>& l)
	{
		_firstLink = new Link<T>();
		_lastLink = new Link<T>();

		_firstLink->_prev = 0;
		_firstLink->_succ = _lastLink;

		_lastLink->_prev = _firstLink;
		_lastLink->_succ = 0;
		_size = 0;

		for (Link<T>* ptr = l._firstLink; ptr != 0; ptr = ptr->_succ)
			push_back(ptr->_val);
	}
	
	// Member type: iterator
	class iterator;

	iterator begin()	// iterator to first element
	{
		return iterator(_firstLink->_succ);
	}

	iterator end()		// iterator to one beyond last element
	{
		return iterator(_lastLink);
	}
	
	void push_back(const T& v)
	{
		Link<T>* newLink = new Link<T>;
		newLink->_prev = 0;
		newLink->_succ = 0;
		newLink->_val = v;

		if (_firstLink == 0)
		{
			_lastLink = new Link<T>;

			// Insert into empty List
			_firstLink = newLink;
			_firstLink->_succ = _lastLink;

			_lastLink->_prev = _firstLink;
			_lastLink->_succ = 0;
		}
		else
		{
			// Insert into a List containing at least 1 element
			_lastLink->_prev->_succ = newLink;

			newLink->_prev = _lastLink->_prev;
			newLink->_succ = _lastLink;

			_lastLink->_prev = newLink;
		}

		_size = _size + 1;
	}
	
	void push_front(const T& v)
	{
		if (_size == 0)
		{
			push_back(v);
			return;
		}
		else
		{
			Link<T>* ptr = new Link<T>(v, 0, _firstLink->_succ);
			//_firstLink->_prev = ptr;
			_firstLink->_succ = ptr;
		}

		_size = _size + 1;
	}

	void pop_front()
	{
		if (_size == 0)
			throw std::out_of_range("Cannot pop on an empty list");

		Link<T>* tmp = _firstLink;
		_firstLink = _firstLink->_succ;
		
		delete tmp;
		_size = _size - 1;
	}

	void pop_back()
	{
		if (_size == 0)
			throw std::out_of_range("Cannont pop on an empty list");

		if (_lastLink == _firstLink) return;
		_lastLink = _lastLink->_prev;
		_size = _size - 1;
	}

	// Returns the value of the element at the front of the list
	// Throws std::out_of_range exception if the list is empty
	T& front()
	{
		if (_size == 0)
			throw std::out_of_range("Cannot pop on an empty list");

		return _firstLink->_succ->_val;
	}

	// Returns the value of the element at the back of the list
	// Throws std::out_of_range exception if the list is empty
	T& back()
	{
		if (_size == 0)
			throw std::out_of_range("Cannot pop on an empty list");

		return _lastLink->_prev->_val;
	}

	size_t size() const { return _size; }
private:
	Link<T>* _firstLink;
	Link<T>* _lastLink;
	size_t	 _size;			// Number of elements in list
};

template<class Elem> class List<Elem>::iterator
{
public:
	iterator(Link<Elem>* p)
		:_curr(p)
	{}

	iterator& operator++()
	{
		_curr = _curr->_succ;
		return *this;
	}

	iterator& operator--()
	{
		_curr = _curr->_prev;
		return *this;
	}

	Elem& operator*()
	{
		return _curr->_val;
	}

	bool operator==(const iterator& b) const
	{
		return _curr == b._curr;
	}

	bool operator!=(const iterator& b) const
	{
		return _curr != b._curr;
	}

private:
	Link<Elem>* _curr;
};