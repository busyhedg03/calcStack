#include "listSimply.h"
#include "stack.h"
Stack::Stack() { //Конструктор класса
	top = new listSimply;
	top->front = nullptr;
}
void Stack::destroy_stack() {
	top->delete_list();
}
bool Stack::is_empty() { //определяет, пуст ли стек
	if (top->front == nullptr) {
		return 1;
	}
	return 0;
}
void Stack::push(int newItem) {
	top->push_front(newItem);
	//throw StackException;
}
// Добавляет элемент new_item на вершину стека.// Если вставку выполнить невозможно,// генерирует исключительную ситуацию StackException, 
void Stack::рор() {
	top->pop_front();
	//Удаляет вершину стека; иными словами, удаляет элемент, 
	//вставленный последним. Если удаление выполнить невозможно,
	//генерирует исключительную ситуацию StackException.
	//throw StackException;
}
void Stack::stack_out() {
	top->nodeOut();
}
void test()
{
	Stack* stack = new Stack();
	stack->push(8);
	stack->push(9);
	std::cout << stack->is_empty() << " ";
	stack->stack_out();
	stack->destroy_stack();
	std::cout << stack->is_empty() << " ";
}
