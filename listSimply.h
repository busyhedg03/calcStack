#ifndef LISTSIMLY_H
#include <iostream>
#define LISTSIMLY_H
template <typename T>
class listSimply
{
private:
	template <typename T>
	struct Node {
		T data;
		Node* next;
	};
public:
	Node<T>* front{ nullptr };
	void push_front(T value);
	void push_back(T value);
	void delete_list();
	void pop_front();
	void pop_back();
	void delete_elem(int position);
	void insert_to_position(int position, T value);
	Node<T>* insert_array(T* array, int size);
	void nodeOut();
	Node<T>* GetFront();
};
#endif // !LISTSIMLY_H