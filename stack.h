#include <iostream>
#ifndef STACK_H
#define STACK_H
#include "listSimply.h"
class Stack {
	listSimply* top;
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
	void push(int newItem);
	/// <summary>
	/// Удалить элемент из стека
	/// </summary>
	void рор();
	/// <summary>
	/// Вывести стек полностью
	/// </summary>
	void stack_out();
};
/// <summary>
/// Протестировать работу стека
/// </summary>
void test();
#endif