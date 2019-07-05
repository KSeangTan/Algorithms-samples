//Index-based implementation
void insertionSort(int *A, int p, int q) {
    int temp = 0;
    int j = 0;
    for(int i = p+1; i <= q; i++) {
        j = i - 1;
        temp = A[i];
        while(j >= p && A[j] > temp) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}
void medianOfmedians(int *A, int N) {
    
}

int main() {
    int A[12] = {1,10,4,6,7,11,15,16,2,3,25,12};
    insertionSort(A, 0, 4);
    for(int i = 0; i < 12; i++){
        cout << A[i] << endl;
    }
}