void countingSort(int *A, int n, int exp) {
    int B[n] = {0};
    int C[10] = {0};

    //Placing number of occurance in A into C
    for (int i = 0;i < n; i++) {
        C[(A[i] / exp) % 10] += 1;
    }

    //making C contains number less than i
    for (int i = 1;i <= 9; i++) {
        C[i] += C[i-1];
    }

    //Sorting based on C
    for (int i = n-1;i >= 0; i--) {
        B[C[ (A[i] / exp) % 10] - 1] = A[i];
        C[ (A[i] / exp) % 10 ] -= 1;
    }

    for(int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

int getMax(int *A, int n) {
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }
    return max;
}
void radixSort(int *A, int n) {
    int d = getMax(A, n);
    for(int exp = 1; d/exp > 0 ; exp *= 10) {
        countingSort(A, n, exp);
    }
}