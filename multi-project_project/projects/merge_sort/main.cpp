#include "merge.hpp"
#include "merge_sort.hpp"
#include <iostream>

int main(){
    std::cout << "Enter length of your array: " << std::endl;
    int n;
    std::cin >> n;
	
    std::cout << "Enter numbers of your array: " << std::endl;
	std::vector<int> A;
    for (size_t i = 0; i < n; ++i){
        int x;
        std::cin >> x;
        A.push_back(x);
    }
	
	int p = 0;
	int r = n-1;
	biv::merge_sort(A, p, r);
	
	std::cout << "Your sorted array: " << std::endl;
	const char format = ' ';
	for (size_t i = 0; i < n; ++i){
        std::cout << A[i] << format;
    }
	
}