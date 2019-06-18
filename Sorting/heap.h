#ifndef HEAP_H
#define HEAP_H

//Index-based implementation, start from 0

template <typename t>
class Heap {
    protected:
        t *A;
        int size;
        void checkheapPos(int heapPos) {
            if(heapPos < 0 || heapPos >= size) {
                throw "Index out of number of out of heap size";
            }
        }
    public:
    Heap(t *array, int arraySize) {
        A = array;
        size = arraySize;
    }
    int parent(int index) {
        int heapPos = (index - 1) / 2;
        return heapPos; 
    }

    int left(int index) {
        int heapPos = 2 * index + 1;
        return heapPos;
    }

    int right(int index) {
        int heapPos = 2 * index + 2;
        return heapPos;
    }
};

template <typename t>
class MaxHeap: public Heap<t> {
    //using Heap<T>::checkheapPos;
    using Heap<t>::checkheapPos;
    using Heap<t>::parent;
    using Heap<t>::left;
    using Heap<t>::right;
    using Heap<t>::A;
    using Heap<t>::size;
    public:
        MaxHeap(t *array, int arraySize): Heap<t>(array, arraySize) {

        }
        void maxHeaptify(int index) {
            if(index < 0 or index > size) {
                return;
            }
            int l = left(index);
            int r = right(index);
            //Comparing current node with left
            int largest = (l < size && A[l] > A[index]) ? l : index;

            //Comparing current node with right
            largest =  (r < size && A[r] > A[largest]) ? r : largest;
            if (index != largest)
            {
                t temp = A[largest];
                A[largest] = A[index];
                A[index] = temp;
                //If exchange happen, we continuously proceeed to next
                maxHeaptify(largest);
            }
        }

        void buildMaxHeap() {
            for(int i = (size/2)-1; i >= 0; i--) {
                maxHeaptify(i);
            }
        }

        void increasingHeapsort() {
            buildMaxHeap();
            int originalSize = size;
            for(int i = size-1; i > 0; i--) {
                t temp = A[0];
                A[0] = A[i];
                A[i] = temp;
                size -= 1;
                maxHeaptify(0);
            }
            size = originalSize;
        }
};

template <typename t>
class MinHeap: public Heap<t> {
    //using Heap<T>::checkheapPos;
    using Heap<t>::checkheapPos;
    using Heap<t>::parent;
    using Heap<t>::left;
    using Heap<t>::right;
    using Heap<t>::A;
    using Heap<t>::size;
    public:
        MinHeap(t *array, int arraySize): Heap<t>(array, arraySize) {

        }
        void minHeaptify(int index) {
            if(index < 0 or index > size) {
                return;
            }
            int l = left(index);
            int r = right(index);
            //Comparing current node with left
            int minimum = (l < size && A[l] < A[index]) ? l : index;

            //Comparing current node with right
            minimum =  (r < size && A[r] < A[minimum]) ? r : minimum;
            if (index != minimum)
            {
                t temp = A[minimum];
                A[minimum] = A[index];
                A[index] = temp;
                //If exchange happen, we continuously proceeed to next
                minHeaptify(minimum);
            }
        }

        void buildMinHeap() {
            for(int i = (size/2)-1; i >= 0; i--) {
                minHeaptify(i);
            }
        }

        void decreasingHeapsort() {
            buildMinHeap();
            int originalSize = size;
            for(int i = size-1; i > 0; i--) {
                t temp = A[0];
                A[0] = A[i];
                A[i] = temp;
                size -= 1;
                minHeaptify(0);
            }
            size = originalSize;
        }
};

#endif
