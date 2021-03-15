#include "listSimply.h"
#include <iostream>
template <typename T>
void listSimply<T>::push_front(T value) {
	Node<T>* current = new Node<T>;
	current->data = value;
	current->next = front;
	front = current;
}
template<typename T>
void listSimply<T>::push_back(T value) {
	Node<T>* last = front;
	Node<T>* current = new Node<T>;
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
template<typename T>
void listSimply<T>::delete_list() {
	Node<T>* first = front;
	if (front != nullptr) { //For more then 0 element
		if (front->next != nullptr) { //For more then 1 element
			Node<T>* second = front->next;
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
template<typename T>
void listSimply<T>::pop_front() {
	if (front != nullptr) {
		Node<T>* temp = front;
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
template<typename T>
void listSimply<T>::pop_back() {
	if (front != nullptr) {
		Node<T>* temp = front;
		Node<T>* current{ nullptr };
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
template<typename T>
void listSimply<T>::delete_elem(int position) {
	if (front == nullptr || position < 1)
		throw std::exception("ERROR: A non-existent position is specified");
	Node<T>* temp = front;
	Node<T>* current = new Node<T>;
	for (int i{ 1 }; i < position; ++i) {
		if (temp->next == nullptr)
			throw std::exception("ERROR: A non-existent position is specified");
		temp = temp->next;
	}
	current = temp->next;
	temp->next = current->next;
	delete current;
}
template<typename T>
void listSimply<T>::insert_to_position(int position, T value) {
	Node<T>* temp = front;
	if (position < 1)
		throw std::exception("ERROR: A non-existent position is specified");
	Node<T>* insert = new Node<T>;
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
template<typename T>
listSimply<T>::Node<T>* listSimply<T>::insert_array(T* array, int size) {
	Node<T>* current{ nullptr };
	Node<T>* arr{ nullptr };
	Node<T>* last{ nullptr };
	for (int i{ 0 }; i < size; ++i) {
		current = new Node<T>;
		current->data = array[i];
		current->next = nullptr;
		if (i == 0) {
			arr = current;
			current = new Node<T>;
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
template<typename T>
void listSimply<T>::nodeOut() { //Output
	for (Node<T>* current{ front }; current != nullptr; current = current->next)
		std::cout << current->data << " ";
}
template<typename T>
listSimply<T>::Node<T>* listSimply<T>::GetFront() {
	return  front;
}
