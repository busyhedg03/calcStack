#include "listSimply.h"
void listSimply::push_front(int value) {
	Node* current = new Node;
	current->data = value;
	current->next = front;
	front = current;
}
void listSimply::push_back(int value) {
	Node* last = front;
	Node* current = new Node;
	current->data = value;
	current->next = nullptr;
	if (last == nullptr) {
		front = current;
	}
	else {
		while (last->next != nullptr) {
			last = last->next;
		}
		last->next = current;
	}
}
void listSimply::delete_list() {
	Node* first = front;
	if (front != nullptr) { //For more then 0 element
		if (front->next != nullptr) { //For more then 1 element
			Node* second = front->next;
			while (second != nullptr) {
				delete first;
				first = second;
				second = second->next;
			}
		}
		delete first;
	}
	front = nullptr;
}
void listSimply::pop_front() {
	if (front != nullptr) {
		Node* temp = front;
		if (temp->next != nullptr) {
			temp = temp->next;
		}
		else
			temp = nullptr;
		delete front;
		front = temp;
	}
	else
		throw std::exception("ERROR: List is already empty");
}
void listSimply::pop_back() {
	if (front != nullptr) {
		Node* temp = front;
		Node* current{ nullptr };
		if (temp->next != nullptr) {
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			current = temp->next;
			delete current;
			temp->next = nullptr;
		}
		else {
			delete front;
			front = nullptr;
		}
	}
	else
		throw std::exception("ERROR: List is already empty");
}
void listSimply::delete_elem(int position) {
	if (front == nullptr || position < 1)
		throw std::exception("ERROR: A non-existent position is specified");
	Node* temp = front;
	Node* current = new Node;
	for (int i{ 1 }; i < position; ++i) {
		if (temp->next == nullptr)
			throw std::exception("ERROR: A non-existent position is specified");
		temp = temp->next;
	}
	current = temp->next;
	temp->next = current->next;
	delete current;
}
void listSimply::insert_to_position(int position, int value) {
	Node* temp = front;
	if (position < 1)
		throw std::exception("ERROR: A non-existent position is specified");
	Node* insert = new Node;
	insert->data = value;
	if (front != nullptr) { //For more then 0 element
		if (front->next != nullptr) { //For more then 1 element
			for (int i{ 2 }; i < position; ++i) {
				if (temp->next == nullptr) {
					throw std::exception("ERROR: A non-existent position is specified");
				}
				temp = temp->next;
			}
			insert->next = temp->next;
			temp->next = insert;
		}
	}
	else {
		front = insert;
		front->next = nullptr;
	}

}
listSimply::Node* listSimply::insert_array(int* array, int size) {
	Node* current{ nullptr };
	Node* arr{ nullptr };
	Node* last{ nullptr };
	for (int i{ 0 }; i < size; ++i) {
		current = new Node;
		current->data = array[i];
		current->next = nullptr;
		if (i == 0) {
			arr = current;
			current = new Node;
			arr->next = current;
			last = arr;
		}
		else {
			last->next = current;
			last = last->next;
		}
	}
	front = arr; //Write to external variable (optional)
	return arr;
}
void listSimply::nodeOut() { //Output
	for (Node* current{ front }; current != nullptr; current = current->next)
		std::cout << current->data << " ";
}

