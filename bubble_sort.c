#include <stdio.h>

int main(){
    int i,j,temp;
    int n = 6;
    int A[6] = {3,2,-5,1,4,6};
    
    //Sort the Array (Bubble Sort): Biggest to the right
    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++){
            if (A[j]>A[j+1]){
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }
    }
    //Print the Array
    for(i=0; i<n; i++){
        printf("%d",A[i]);
    }

    return 0;
}