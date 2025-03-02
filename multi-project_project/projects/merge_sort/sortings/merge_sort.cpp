#include "merge_sort.hpp"
#include "merge.hpp"
#include <iostream>

void biv::merge_sort(std::vector<int>& A, int p, int r){
    if (p < r){
        int q = (p + r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        biv::mer::merge(A, p, q, r);
        
    }
}