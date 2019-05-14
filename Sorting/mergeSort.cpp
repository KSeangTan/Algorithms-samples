void merge(int *A, int p, int q, int r) {
    //Starting from 1, not zero
    //p is starting number of left window not index
    //q is the end of left window not index
    //r is the end of right window
    int left_end = q - p + 1; 
    int right_end = r - q;

    int left[left_end];
    int right[right_end];

    for (int i = 0;i<left_end;i++) {
        left[i] = A[p-1+i]; //-1 because p is starting number of array not index
    }
    for (int i = 0;i<right_end;i++) {
        right[i] = A[q+i];
    }
    int i = 0; // position for left sorted array
    int j = 0; // position for right sorted array
    for(int k = p-1; k < r; k++) {
        //IF i or j is ended
        if(i >= left_end) {
            A[k] = right[j];
            j++;
            continue;
        } else if(j >= right_end) {
            A[k] = left[i];
            i++;
            continue;
        }
        //Ascending
        if(left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
    }
}

void mergeSort(int *A, int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}