#ifndef LISTSIMLY_H
#define LISTSIMLY_H
#include <iostream>
class listSimply
{
private:
	struct Node {
		int data;
		Node* next;
	};
public:
	Node* front;
	void push_front(int value);
	void push_back(int value);
	void delete_list();
	void pop_front();
	void pop_back();
	void delete_elem(int position);
	void insert_to_position(int position, int value);
	Node* insert_array(int* array, int size);
	void nodeOut();
};
#endif // !LISTSIMLY_H