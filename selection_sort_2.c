#include <stdio.h>

int main(){
    
    int i,j,k,temp;
    int n = 6; //lenght Array
    int A[6] = {3,2,-5,1,4,6};
    
    //Sort the Array(Selection Sort): Biggest to the right
    for(i=n; i>=0; i--){
        k=i;
        for(j=i-1; j>=0; j--){
            if(A[j]>A[k]) {k=j;}
        }
        temp=A[i];
        A[i]=A[k];
        A[k]=temp;
    }

    //Print the Array
    for(i=0; i<n; i++){
        printf("%d",A[i]);
    }

    return 0;
}