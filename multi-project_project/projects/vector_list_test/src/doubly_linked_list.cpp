#include "doubly_linked_list.hpp"

#include <iostream>

using biv::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node* current = begin;
	while (current) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	begin = nullptr;
	end = nullptr;
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	Node* current = begin;
	std::size_t size = 0;
	while (current) {
		current = current->next;
		size++;
	}
	return size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	Node* current = begin;
	while (current) {
		if (current->value == value) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	Node* current = begin;
	while (current) {
		std::cout << current->value;
		current = current->next;
	}
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* current = new Node(value);
	if (begin == nullptr) {
		begin = end = current;
	} else {		
		end->next = current;
		current->prev = end;
		end = current;
	}
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	Node* current = begin;
	while (current) {
		if (current->value == value) {
			if (current == begin) {
				begin = begin->next;
				if (!begin) {
					end = nullptr;
				} else if (begin == end) {
					begin->prev = nullptr;
					end->prev = nullptr;
				} else {
					begin->prev = nullptr;
				}
			} else if (current == end) {
				end = end->prev;
				if (end == begin) {
					end->next = nullptr;
					begin->next = nullptr;
				} else {
					end->next = nullptr;
				}
			} else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			delete current;
			return true;
		}
		current = current->next;
	}
	return false;
						
}