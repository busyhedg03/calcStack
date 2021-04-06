#include <iostream>
#include "listSimply.h"
#include "stack.h"
#include "listSimply.cpp"
using namespace std;
template<typename T>
Stack<T>::Stack() { //Конструктор класса
	top = new listSimply<T>;
	top->front = nullptr;
}
template<typename T>
void Stack<T>::destroy_stack() {
	top->delete_list();
}
template<typename T>
bool Stack<T>::is_empty() { //определяет, пуст ли стек
	if (top->front == nullptr) {
		return 1;
	}
	return 0;
}
template<typename T>
void Stack<T>::push(T newItem) {
	try
	{
		top->push_front(newItem);
	}
	catch (int e)
	{
		cerr << e;
	}
}
template<typename T>
void Stack<T>::pop() {
	// Добавляет элемент new_item на вершину стека.// Если вставку выполнить невозможно,// генерирует исключительную ситуацию StackException, 
	
	try {
		top->pop_front();
	}
	catch (int e) {
		cerr << -1;
	}
	//Удаляет вершину стека; иными словами, удаляет элемент, 
	//вставленный последним. Если удаление выполнить невозможно,
	//генерирует исключительную ситуацию StackException.
}
template<typename T>
void Stack<T>::stack_out() {
	top->nodeOut();
}
template<typename T>
T Stack<T>::GetTop() {
	if (top->front == nullptr)
		throw - 1;
		return top->front->data;
}
template<typename T>
void Stack<T>::SetTop(T value) {
	top = value;
}
void test()
{
	Stack<std::string>* stack = new Stack<std::string>();
	stack->push("8");
	stack->push("9");
	stack->pop();
	std::cout << stack->is_empty() << " ";
	std::cout << stack->GetTop() << " ";
	stack->stack_out();
	stack->destroy_stack();
	std::cout << stack->is_empty() << " ";
}
