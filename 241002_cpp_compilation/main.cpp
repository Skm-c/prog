#include <iostream>
using namespace std;

int main() {
    int a[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = size(a) - 1; i > 0; --i) {
        if (a[i] >= a[i-1] and i % 2 != 0){
            swap(a[i], a[i-1]);
        } else if (a[i] <= a[i-1] and i % 2 == 0){
            swap(a[i], a[i-1]);
        } 
    }
    for (int i = 0; i < size(a); ++i) {
        cout << a[i] << " ";
    }
}
