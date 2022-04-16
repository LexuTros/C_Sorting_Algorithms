#include <stdio.h>

// Definition of Variables:
// A = Array thats to be sortet
// n = number of elements inside the array
// l = index of leftmost element (generally 0)
// r = index of rightmost element

void Exchange(int A[], int idx_ele_1, int idx_ele_2){
    int temp = A[idx_ele_1];
    A[idx_ele_1] = A[idx_ele_2];
    A[idx_ele_2] = temp;
}

int LomutoPartition(int A[], int l, int r){
    int x = A[r];
    int i = l-1;

    for(int j = l; j < r; j++){
        if(A[j] <= x){
            i++;
            Exchange(A, i, j);
        }
    }
    Exchange(A, i+1, r);
    return i+1;
}

int HoarePartition(int A[], int l, int r){
    int x = A[r];
    int i = l;
    int j = r;

    while(1){
        while(A[j] > x){j--;}
        while(A[i] < x){i++;}
        if(i<j){Exchange(A, i, j);}
        else{return i;}
    }
}


void QuickSort(int A[], int l, int r){
    if(l < r){
        int m = HoarePartition(A, l, r);
        QuickSort(A, l, m-1);
        QuickSort(A, m, r);
    }
}


int main(){
    int A[10] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7};
    int n = 10, l = 0, r = 9;

    // Print original Array
    for(int i=0; i<n; i++) {printf("%d ", A[i]);}
    printf("\n");

    QuickSort(A, l, r);
       
    // Print sorted array
    for(int i=0; i<n; i++) {printf("%d ", A[i]);}

    return 0;
}