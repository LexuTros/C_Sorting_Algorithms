#include <stdio.h>

// n = elements in A
int InsertionSort(int A[], int n){
    int i, j, temp;

    for(i=1; i<n; i++){
        temp = A[i];
        for(j=i-1; j>=0 && temp>A[j]; j--){ // decending: temp>A, ascending: temp<A 
            A[j+1] = A[j];}
        A[j+1] = temp;
    }

    return 0;
}

int main(){
    int n = 6;
    int A[6] = {0,5,3,6,4,2};

    InsertionSort(A, n);

    //Print the Array
    for(int i=0; i<n; i++){
        printf("%d",A[i]);
    }

    return 0;
}