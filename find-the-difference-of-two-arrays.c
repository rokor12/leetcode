#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int main(){

    return 0;
}

bool isInArr(int *arr,arrSize,n){
    for(int i=0;i<arrSize;i++){
        if(arr[i]==n){return true}
    }
    return false;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
    *returnSize = 2;
    int i,aux1Size = 0;
    int *aux1 = (int*)malloc(sizeof(int));
    for(i=0;i<nums1Size;i++){
        if(isInArr(nums2, nums2Size, nums1[i])){
            aux1Size++;
            aux1 = realloc(aux1,aux1Size*sizeof(int));
            aux1[aux1Size-1] = nums1[i];
        }
    }
    int aux2Size = 0;
    int *aux2 = (int*)malloc(sizeof(int));
    for(i=0;i<nums2Size;i++){
        if(!isInArr(aux1, aux1Size, nums2[i])){
            aux2Size++;
            aux2 = realloc(aux2,aux2Size*sizeof(int));
            aux2[aux2Size-1] = nums2[i];
        }
    }
    returnColumnSizes = (int**)malloc(2*sizeof(int*));
    *returnColumnSizes[0] = aux1Size;
    *returnColumnSizes[1] = aux2Size;
    int **ans = (int**)malloc(2*sizeof(int*));
    ans[0] = aux1;
    ans[1] = aux2;
    return ans;
}
