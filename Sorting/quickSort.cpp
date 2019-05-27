#include <iostream>
#include <vector>
using namespace std;

//index-based
int partition(int *A, int p, int q) {
    int pivot = A[p];
    int i = p;
    int temp = 0;
    for(int j = i+1; j <= q; j++) {
        if(A[j] < pivot) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp; 
        }
    }
    //If i is not pivot, mean we swap thing in array
    if(i > p) {
        A[p] = A[i];
        A[i] = pivot;
    }
    return i;
}
//Index-based
void quicksort(int *A, int p, int q) {
    if (p < q) {
        int r = partition(A, p ,q);
        //Sort left-subarray
        quicksort(A, p, r-1);
        //Sort right-subarray
        quicksort(A, r+1, q);
    }
}
int main() 
{ 
  int a[8]{6,10,13,5,8,3,2,11};
  quicksort(a, 0, 7);
  for(int i = 0; i < 8; i++) {
      cout << a[i] << endl;
  }
  return 0;
} 