#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <iostream>
#include<cmath>
#include<string>
using namespace std;

template <class Type>
//Узел двоичного дерева
class bin_tree_node {
private:
	Type _value;
	int _height;
	bin_tree_node<Type>* _left;
	bin_tree_node<Type>* _right;
	bin_tree_node<Type>* _parent;
public:
	//Конструктор
	bin_tree_node(Type value = Type()) : _value(value), _height(1), 
	_left(0), _right(0), _parent(0) {}

	//Деструктор
	~bin_tree_node() {}

	//Фуекция, проверяющая является ли узел листом
	bool is_leaf() { return _left == 0 && _right == 0; }

	template <class Type1> 
	friend class bin_tree;
};

template <class Type>
//Структура двоиного дерева
class bin_tree {
public:
	bin_tree() : _root(0) {}

	~bin_tree() { destroy(_root); }

	//ОБЁРТКИ ФУНКЦИЙ

	bin_tree_node<Type>* find(const Type& val) const { return find(_root, val); }

	Type find_max() const { return find_max(_root); }

	Type find_min() const { return find_min(_root); }

	int count_height() { return count_height(_root); }

	int count_elements() { return count_elements(_root); };

	void add_node(const Type val) { _root = add_node(_root, val); }

	void balance_remove(const Type val) { _root = balance_remove(_root, val); }

	void print() const { print(_root, 0); }

	void print_leafs() const { print_leafs(_root); }

	void print_fork() const { print_fork(_root); }

	void print_branch() const { print_branch(_root); }

	void print_ascending() const { print_ascending(_root); }

	void print_reverse() const { print_reverse(_root); }


private:
	bin_tree_node<Type>* _root;

	//Поиск значения
	bin_tree_node<Type>* find(bin_tree_node<Type>* pos, const Type& value) const {
		if (!pos) return 0;
		if (pos->_value == value) return pos;
		if (pos->_value < value) return find(pos->_right, value);
		return find(pos->_left, value);
	}

	//Добавление нового значения в двоичное дерево
	bin_tree_node<Type>* add_node(bin_tree_node<Type>* pos, const Type value) {
		// Если место свободно, то вставляем туда узел.
		if (!pos) return new bin_tree_node<Type>(value);
		//Иначе проверяем значения
		//Если новое значение больше, то вставляем вправо
		if (pos->_value < value) pos->_right = add_node(pos->_right, value);
		//Если новое значение меньше, то вставляем влево
		else if (pos->_value > value) pos->_left = add_node(pos->_left, value);
		return balance(pos);
	}

	//Правый поворот двоичного дерева вокруг pos
	bin_tree_node<Type>* rotate_right(bin_tree_node<Type>* pos){
		bin_tree_node<Type>* tmp = pos->_left;
		pos->_left = tmp->_right;
		tmp->_right = pos;
		fix_height(pos);
		fix_height(tmp);
		return tmp;
	}

	//Левый поворот двоичного дерева вокруг pos
	bin_tree_node<Type>* rotate_left(bin_tree_node<Type>* pos){
		bin_tree_node<Type>* tmp = pos->_right;
		pos->_right = tmp->_left;
		tmp->_left = pos;
		fix_height(pos);
		fix_height(tmp);
		return tmp;
	}

	//Балансировка pos
	bin_tree_node<Type>* balance(bin_tree_node<Type>* pos){
		fix_height(pos);
		//Баланс положительный => высота правого поддерева больше левого => 
		// => нужен поворот налево вокруг pos.
		if (balance_factor(pos) == 2){
			if (balance_factor(pos->_right) < 0)
				pos->_right = rotate_right(pos->_right);
			return rotate_left(pos);
		}
		//Баланс отрицательный => высота левого поддерева больше правого => 
		// => нужен поворот направо вокруг pos.
		if (balance_factor(pos) == -2){
			if (balance_factor(pos->_left) > 0)
				pos->_left = rotate_left(pos->_left);
			return rotate_right(pos);
		}
		return pos;
	}

	//Поиск позиции минимального элемента
	bin_tree_node<Type>* find_pos_min(bin_tree_node<Type>* pos) const {
		if (!pos) throw string("ERROR: binary tree is empty!\n");
		if (pos->_left) return find_pos_min(pos->_left);
		return pos;
	}

	//Поиск максимума
	Type find_max(bin_tree_node<Type>* pos) const {
		if (!pos) throw string("Error: binary tree is empty\n");
		while (!pos->_right)
			pos = pos->_right;
		return pos->_value;
	}

	//Поиск минимума
	Type find_min(bin_tree_node<Type>* pos) const {
		if (!pos) throw string("Error: binary tree is empty\n");
		while (!pos->_left)
			pos = pos->_left;
		return pos->_value;
	}

	//Подсчёт высоты дерева
	int count_height(bin_tree_node<Type>* pos) {
		if (pos == 0) return 0;
		int left, right;
		left = count_height(pos->_left);
		right = count_height(pos->_right);
		if (left > right) return left + 1;
		return right + 1;
	}

	//Обёртка для поля высоты
	int get_height(bin_tree_node<Type>* pos) {
		if (!pos) return 0;
		else return pos->height;
	}

	//Вычисление баланса заданного узла
	int balance_factor(bin_tree_node<Type>* pos) const { 
		if (!pos) return 0;
		return get_height(pos->_right) - get_height(pos->_left); 
	}

	//Подсчёт количества элементов
	int count_elements(bin_tree_node<Type>* pos) {
		if (pos == 0) return 0;
		return count_elements(pos->_left) + count_elements(pos->_right) + 1;
	}

	//Восстановление значения высоты заданного узла
	void fix_height(bin_tree_node<Type>* pos) { 
		if (!pos) return;
		pos->_height = max(get_height(pos->_left), get_height(pos->_right)) + 1; 
	}

	//УДАЛЕНИЕ

	//Удаление, не сохраняющее сбалансированность дерева
	void remove_leaf(bin_tree_node<Type>* pos) {
		if (!pos->_parent) _root = nullptr;
		else if (pos->_parent->_left == pos) pos->_parent->_left = nullptr;
		else pos->_parent->_right = nullptr;
		delete pos;
	}
	void remove_left_null(bin_tree_node<Type>* pos) {
		pos->_right->_parent = pos->_parent;
		if (pos == _root) _root = pos->_right;
		else if (pos->_parent->_left == pos) pos->_parent->_left = pos->_right;
		else pos->_parent->_right = pos->_right;
		delete pos;
	}
	void remove_right_null(bin_tree_node<Type>* pos) {
		pos->_left->_parent = pos->_parent;
		if (pos == _root) _root = pos->_left;
		else if (pos->_parent->_left == pos) pos->_parent->_left = pos->_left;
		else pos->_parent->_right = pos->_left;
		delete pos;
	}
	void remove(bin_tree_node<Type>* pos) {
		if (!pos) return;
		if (pos->_left == nullptr && pos->_right == nullptr) remove_leaf(pos);
		else if (pos->_left == nullptr) remove_left_null(pos);
		else if (pos->_right == nullptr) remove_right_null(pos);
		else {
			bin_tree_node<Type>* repl = max(pos->_left);
			pos->_value = repl->_value;
			remove(repl);
		}
	}
	void remove(const Type val) {
		bin_tree_node<Type>* pos = find(val);
		if (!pos) return;
		remove(pos);
	}

	//Удаление, сохраняющее сбалансированность дерева
	bin_tree_node<Type>* balance_remove(bin_tree_node<Type>* pos, const Type val) {
		if (!pos) return pos;
		if (val < pos->_value)
			pos->_left = balance_remove(pos->_left, val);
		else if (val > pos->_value)
			pos->_right = balance_remove(pos->_right, val);
		else if (pos->_right && pos->_left) {
			pos->_value = find_pos_min(pos->_right)->_key;
			pos->_right = balance_remove(pos->_right, pos->_value);
		}
		else
			if (pos->_left) {
				pos->_value = pos->_left->_value;
				delete pos->_left;
				pos->_left = 0;
			}
			else if (pos->_right) {
				pos->_value = pos->_right->_value;
				delete pos->_right;
				pos->_right = 0;
			}
			else {
				delete pos;
				pos = 0;
			}
		return balance(pos);
	}

	//Функция удаления дерева
	void destroy(bin_tree_node<Type>* pos) {
		if (!pos) return;
		destroy(pos->_left);
		destroy(pos->_right);
		delete pos;
	}

	//ВЫВОД

	//Вывод листьев двоичного дерева
	void print_leafs(bin_tree_node<Type>* pos) const {
		if (pos == nullptr) return;
		print_leafs(pos->_left);
		if (pos->_left == nullptr && pos->_right == nullptr)
			cout << pos->_value << endl;
		print_leafs(pos->_right);
	}

	//Вывод вершин, имеющих по два ребёнка
	void print_fork(bin_tree_node<Type>* pos) const {
		if (pos->_left) print_fork(pos->_left);
		if ((pos->_left) && (pos->_right)) cout << pos->_value << endl;
		if (pos->_right) print_fork(pos->_right);
	}

	//Вывод вершин, имеющих только одного ребёнка
	void print_branch(bin_tree_node<Type>* pos) const {
		if (pos->_left) print_branch(pos->_left);
		if (((pos->_left != 0) && (pos->_right == 0)) ||
			((pos->_left == 0) && (pos->_right != 0)))
			cout << pos->_value << endl;
		if (pos->_right) print_branch(pos->_right);
	}

	//Обход по возрастанию
	void print_ascending(bin_tree_node<Type>* pos) const {
		if (!pos) return;
		if (pos->_left) print_ascending(pos->_left);
		cout << pos->_value << endl;
		if (pos->_right) print_ascending(pos->_right);
	}

	//Обратный обход
	void print_reverse(bin_tree_node<Type>* pos) const {
		if (!pos) return;
		if (pos->_left) print_reverse(pos->_left);
		if (pos->_right) print_reverse(pos->_right);
		cout << pos->_value << endl;
	}

	//Вывод двоичного дерева
	//Вывод дерева в строку
	void print(bin_tree_node<Type>* pos) const {
		if (!pos) return;
		print(pos->_right);
		cout << pos->_value << ' ';
		print(pos->_left);
	}
	//Вывод дерева с отступами и сдвигами
	void print(bin_tree_node<Type>* pos, int level) const {
		if (!pos) return;
		print(pos->_right, level + 1);
		for (int i = 0; i < level; i++)
			cout << ' ';
		cout << pos->_value << endl;
		print(pos->_left, level + 1);
	}
};

#endif // BIN_TREE_H