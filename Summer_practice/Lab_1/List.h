#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
using namespace std;

template <class Type>
class List;

template <class Type>
class Node {
private:
	Type _value;
	Node* _next;
	Node* _previous;
public:
	Node(const Type& value) : _value(value), _next(0), _previous(0) {}
	Node<Type>* next() const { return _next; }
	Node<Type>* pervious() const { return _previous; }
	Type value() const { return _value; }
	void set_value(Type value) { _value = value; }
	template <class Type1> friend class List;
};


template <class Type>
using pnode = Node<Type>*;


template <class Type>
class List {
private:
	pnode<Type> _first;
	pnode<Type> _last;
	int _size;
public:
	List() : _first(0), _last(0), _size(0) {}
	~List();

	// ������� ������ ������
	int size() { return _size; }

	// �������� ������ �� �������.
	bool is_empty() const { return _first == 0; }
	// ���������� �������� ������� �������� � ������.
	pnode<Type> front() { return _first; }
	// ���������� �������� ���������� �������� � ������.
	pnode<Type> back() { return _last; }

	// ��������� ������� � ����� ������.
	void push_back(const Type&);
	// ��������� ������� � ������ ������.
	void push_front(const Type&);

	// ������� ������� ������ ������� �� ���������� ������.
	void remove_first();
	// ������� ������� ��������� ������� �� ���������� ������.
	void remove_last();

	// ������� ������� � ��������� ������ �� �������.
	Type at(const int idx) const;

	// ������ ������ � �������.
	void print();
	// ������ ������ � ����.
	void fprint(ofstream&);
};

template <class Type>
List<Type>::~List() {
	pnode<Type> curr = _first;
	while (curr != 0) {
		pnode<Type> temp = curr->_next;
		delete curr;
		curr = temp;
	}
}

// ��������� ������� � ����� ������.
template <class Type>
void List<Type>::push_back(const Type& value) {
	pnode<Type> new_el = new Node<Type>{ value };
	if (is_empty()) {
		_first = new_el;
		_last = new_el;
		_size++;
		return;
	}
	_last->_next = new_el;
	new_el->_previous = _last;
	_last = new_el;
	_size++;
}

// ��������� ������� � ������ ������.
template <class Type>
void List<Type>::push_front(const Type& value) {
	if (is_empty()) {
		push_back(value);
		_size++;
		return;
	}
	pnode<Type> new_el = new Node<Type>{ value };
	new_el->_next = _first;
	_first->_previous = new_el;
	_first = new_el;
	_size++;
}

// ������� ������� ������ ������� �� ���������� ������.
template <class Type>
void List<Type>::remove_first() {
	// � ������ �������� ������ ������� ����� �� �������� ������.
	if (is_empty()) return;
	if (_last == _first) {
		delete _first;
		_first = _last = 0;
		_size = 0;
		return;
	}
	pnode<Type> curr = _first;
	_first = curr->_next;
	_first->_previous = 0;
	delete curr;
	_size--;
}

// ������� ������� ��������� ������� �� ���������� ������.
template <class Type>
void List<Type>::remove_last() {
	// � ������ �������� ������ ������� ����� �� �������� ������.
	if (is_empty()) return;
	if (_last == _first) {
		delete _last;
		_first = _last = 0;
		_size = 0;
		return;
	}
	pnode<Type> curr = _last;
	_last = _last->_previous;
	_last->_next = 0;
	delete curr;
	_size--;
}

// ������� ������� � ��������� ������ �� �������.
template <class Type>
Type List<Type>::at(const int idx) const {
	int pos = 0;
	pnode<Type> curr = _first;
	if (is_empty() == true) throw 1;
	while (curr && pos < idx) {
		curr = curr->_next;
		pos++;
	}
	if (idx > pos || idx < 0) throw 1;
	if (idx == pos && !curr) throw 1;
	return curr->_value;
}

// ������ ������ � �������.
template <class Type>
void List<Type>::print() {
	pnode<Type> curr = _first;
	while (curr) {
		cout << curr->_value << ' ';
		curr = curr->_next;
	}
	cout << endl;
}

// ������ ������ � ����.
template <class Type>
void List<Type>::fprint(ofstream& fout) {
	pnode<Type> curr = _first;
	while (curr) {
		fout << curr->_value << ' ';
		curr = curr->_next;
	}
	fout << endl;
}

#endif // !LIST_H
