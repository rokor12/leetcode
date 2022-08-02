// leetcode.com/problems/sort-array-by-parity-ii/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compare(int *a, int *b);
int kthSamllest(int **matrix, int matrixSize, int *matrixColSize, int k);
int* newPointer(int* arr, int size);

int main(){
    
    int matrixSize = 3;
    int *matrixColSize = (int*)malloc(matrixSize*sizeof(int));
    int **matrix = (int**)malloc(matrixSize*sizeof(int*));
    int arr1[3] = {1,5,9}, arr2[3] = {10,11,13}, arr3[3] = {12,13,15};
    int *arr;
    int k=8;

    arr = newPointer(arr,matrixSize);
    memcpy(arr,arr1,3*sizeof(int));
    matrix[0] = arr;
    matrixColSize[0] = 3;
    arr = newPointer(arr, matrixSize);
    memcpy(arr,arr2,3*sizeof(int));
    matrix[1] = arr;
    matrixColSize[1] = 3;
    arr = newPointer(arr, matrixSize);
    memcpy(arr,arr3,3*sizeof(int));
    matrix[2] = arr;
    matrixColSize[2] = 3;
    int ans = kthSamllest(matrix, matrixSize, matrixColSize, k);
    printf("%d\n",ans);
    return 0;
}

int* newPointer(int *arr, int size){
    arr = (int*)malloc(size*sizeof(int));
    return arr;
}

int compare(int *a, int *b){
    return *a - *b;
}

int kthSamllest(int **matrix, int matrixSize, int *matrixColSize, int k){
    int size = matrixSize * matrixColSize[0];
    int *arr = (int*)malloc(size*sizeof(int));
    int i,j;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            arr[(i*matrixSize)+j]=matrix[i][j];
        }
    }
    qsort(arr,size,sizeof(int),&compare);
    return arr[k-1];
}
