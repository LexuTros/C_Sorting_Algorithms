#include <stdio.h>

// Definition of Variables:
// A = Array thats to be sortet
// n = number of elements in A


void Heapify(int A[], int idx_parent, int size){
    int idx_max = idx_parent;
    int left_child = 2*idx_parent+1;
    int right_child = 2*idx_parent+2;

    if(left_child <= size && A[left_child] > A[idx_max]) {idx_max = left_child;} // Ascending >
    if(right_child <= size && A[right_child] > A[idx_max]) {idx_max = right_child;} // Decending <
    
    if(idx_max != idx_parent){
        int temp = A[idx_parent];
        A[idx_parent] = A[idx_max];
        A[idx_max] = temp;

        Heapify(A, idx_max, size);
    }
}

void BuildHeap(int A[], int n){
    for(int i = (n/2)-1; i >= 0; i--){
        Heapify(A, i, n-1);
    }
}


void HeapSort(int A[], int n){
    int size = n-1; // idx of last element
    BuildHeap(A, n);
    for(int i = n-1; i >= 1; i--){
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        size = size-1;
        Heapify(A, 0, size);
    }
}


int main(){
    int A[10] = {46, 77, 55, 38, 41, 85};
    int n = 6;

    // Print original Array
    for(int i=0; i<n; i++) {printf("%d ", A[i]);}
    printf("\n");

    HeapSort(A, n);
       
    // Print sorted array
    for(int i=0; i<n; i++) {printf("%d ", A[i]);}

    return 0;
}