#include <iostream>
#include <vector>


void merge(std::vector<int>& A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> L(n1 + 2);
    std::vector<int> R(n2 + 2);
    for (int i = 1; i < n1 + 1; ++i){
        L[i] = A[p + i - 1];
    }
    for (int j = 1; j < n2 + 1; ++j){
        R[j] = A[q + j];
    }
    L[n1 + 1] = 1000000000;
    R[n2 + 1] = 1000000000;
    int i = 1;
    int j = 1;
    
    for (int k = p; k < r + 1; ++k){
        if (L[i] < R[j]){
            A[k] = L[i];
            ++i;
        } else{
            A[k] = R[j];
            ++j;    
        }
    }
}

void merge_sort(std::vector<int>& A, int p, int r){
    if (p < r){
        int q = (p + r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
        
    }
}
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
	merge_sort(A, p, r);
	std::cout << "Your sorted array: " << std::endl;
	const char format = ' ';
	for (size_t i = 0; i < n; ++i){
        std::cout << A[i] << format;
    }
}
