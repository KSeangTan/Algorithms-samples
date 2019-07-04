void countingSort(int *A, int *B, int n, int K){
    //Initializa counting array
    int C[K+1];
    for (int i = 0;i <= K; i++) {
        C[i] = 0;
    }

    //Placing number of occurance in A into C
    for (int i = 0;i < n; i++) {
        C[A[i]] += 1;
    }

    //making C contains number less than i
    for (int i = 1;i <= K; i++) {
        C[i] += C[i-1];
    }

    //Sorting based on C
    for (int i = n-1;i >= 0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]] -= 1;
    }
}