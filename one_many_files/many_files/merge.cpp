#include "merge.hpp"
#include <iostream>
void biv::mer::merge(std::vector<int>& A, int p, int q, int r){
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