#include <stdio.h>

// Definition of Variables:
// A = Array thats to be sortet
// l = first index of the Array (generally 0)
// r = last index of the Array

// Subfunction
int Merge(int A[], int l, int r, int m){
    int B[r+5];
    int i, j, k;
    
    // Create new array from sorted halfs
    for(i=l; i<=m; i++) {B[i] = A[i];} // Copie first half of A into B
    for(i=m+1; i<=r; i++) {B[r+m-i+1] = A[i];} // Copie second half of Array into B in reverse Order
    
    // Copie in a sorted fashion back into old array
    i = l; j = r; 
    for(k=l; k<=r; k++){
        if(B[i] < B[j]) {A[k] = B[i]; i++;} // Ascending < , Decending >
        else {A[k] = B[j]; j--;}
    }
}

// Mergesort: Sorted Array in ascending order
int MergeSort(int A[], int l, int r){
    int m = 0;

    if(l<r){
        m = (l+r)/2; //floor division (find last index of left half)
        MergeSort(A, l, m); // Sort left half
        MergeSort(A, m+1, r); // Sort right half
        Merge(A, l, r, m);
    }
}


int main(){
    int A[12] = {3,4,1,15,2,28,22,23,32,1,8,12};
    int l = 0, r = 11;

    // Print original Array
    for(int i=0; i<12; i++) {printf("%d ", A[i]);}
    printf("\n");

    MergeSort(A, l, r);
       
    // Print sorted array
    for(int i=0; i<12; i++) {printf("%d ", A[i]);}

    return 0;
}