#include "vector.hpp"

#include <iostream>

using biv::Vector;

template<typename T>
const std::size_t Vector<T>::START_CAPACITY = 16;

template<typename T>
Vector<T>::Vector() {
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (size + 1 > capacity) {
		if (capacity == 0){
		  capacity = 1;
		} else {      
		  capacity *= 2;
		}
		
		T* new_arr = new T[capacity];
		for (size_t i = 0; i < position; ++i) {
			new_arr[i] = arr[i];
		}
		
		new_arr[position] = value;
		
		for (size_t i = position + 1; i < size; i++) {
			new_arr[i] = arr[i - 1];
		}
		
		delete[] arr;
		arr = new_arr;
	} else {
		for (size_t i = position + 1; i < size; ++i) {
			arr[i] = arr[i - 1];
		}
		arr[position] = value;
	}
	size++;
	return true;
}    
  
template<typename T>
void Vector<T>::print() const noexcept {
	for (size_t i = 0; i < size; i++) { 
		std::cout << arr[i] << ' ';
	}
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	if (size + 1 > capacity) {
		if (capacity == 0){
		  capacity = 1;
		} else {      
		  capacity *= 2;
		}
		
		T* new_arr = new T[capacity];
		for (size_t i = 0; i < size; ++i) {
			new_arr[i] = arr[i];
		}
		
		delete[] arr;
		arr = new_arr;
	}
	arr[size] = value;
	size++;
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {	
	size_t position = 0;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value){
			position = i;
		
			// Укорачивание хвоста при некотором условии
			if (capacity - size - 1 > 1000) {
				capacity = size + 500;
			}
			T* new_arr = new T[capacity];
			for (size_t i = 0; i < position; ++i) {
				new_arr[i] = arr[i];
			}
	
			size--;
			
			for (size_t i = position; i < size; ++i) {
				new_arr[i] = arr[i + 1];
			}
			
			delete[] arr;
			arr = new_arr;
			return true;
		}
	}
	return false; 
}
	
