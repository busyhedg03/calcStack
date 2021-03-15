#include "listSimply.h"
#include <iostream>
#ifndef STACK_H
#define STACK_H
template <typename T>
class Stack {
	listSimply<T>* top;
public:
	Stack();
	/// <summary>
	/// Уничтожить стек
	/// </summary>
	void destroy_stack();
	/// <summary>
	/// Пуст ли стек
	/// </summary>
	/// <returns></returns>
	bool is_empty();
	/// <summary>
	/// Поместить элемент в стек
	/// </summary>
	/// <param name="newItem"></param>
	void push(T newItem);
	/// <summary>
	/// Удалить элемент из стека
	/// </summary>
	void pop();
	/// <summary>
	/// Вывести стек полностью
	/// </summary>
	void stack_out();
	/// <summary>
	/// Геттер вершины
	/// </summary>
	T GetTop();
	/// <summary>
	/// Сеттер вершины
	/// </summary>
	void SetTop(T value);
};
/// <summary>
/// Протестировать работу стека
/// </summary>
void test();
#endif