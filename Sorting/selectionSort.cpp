#include <iostream>

using namespace std;

void selectionSort(int *a, int n) {
    int min = 0;
    int temp = 0;
    for(int i = 0; i < n-1; i++) {
        min = i; // assumed i is smallest
        for(int j = i+1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        //if minimum position is not the current i position, we swap both of them
        if(min != i) {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp; 
        }
    }

    //Print out sorted numbers array
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

int main() 
{ 
  int numbers[6]{5,6,4,3,1,0};
  selectionSort(numbers, 6);
    
  return 0;
} 
