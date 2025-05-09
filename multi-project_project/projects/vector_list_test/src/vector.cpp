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
	for (size_t i = size - 1; i >= 0; i--){
		arr[i].~T();
	}
	
	operator delete(arr);
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
		
		T* new_arr = static_cast<T*>(operator new(capacity * sizeof(T)));
		for (size_t i = 0; i < position; ++i) {
            new (new_arr + i) T(std::move(arr[i]));
            arr[i].~T();
        }
		
		new (new_arr + position) T(value);
		
		for (size_t i = position; i < size; i++) {
			new (new_arr + i + 1) T(std::move(arr[i]));
			arr[i].~T();
		}
		
		operator delete(arr);
		arr = new_arr;
	} else {
		for (size_t i = position + 1; i < size; ++i) {
            new (arr + i) T(std::move(arr[i - 1]));
            arr[i - 1].~T();
        }
		new (arr + position) T(value);
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
		
		T* new_arr = static_cast<T*>(operator new(capacity * sizeof(T)));
		for (size_t i = 0; i < size; ++i) {
            new (new_arr + i) T(std::move(arr[i]));
            arr[i].~T();
        }
		
		operator delete(arr);
		arr = new_arr;
	}
	new (arr + size) T(value);
	size++;
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
	size_t position = 0;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value){
			position = i;

			for (size_t i = 0; i < position; ++i) {
				new (arr + i) T(std::move(arr[i]));
				arr[i].~T();
			}
			
			arr[size - 1].~T();
			size--;
			
			for (size_t i = position; i < size; ++i) {
				new (arr + i) T(std::move(arr[i]));
				arr[i].~T();
			}
			
			return true;
		}
	}
	return false;
	
}
