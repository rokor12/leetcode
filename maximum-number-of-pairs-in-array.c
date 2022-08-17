#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>

int* numberOfPairs(int* nums, int numsSize, int* returnSize);
int notInArray(int num, int *arr, int arrSize);

int main(){
    //[1,3,2,1,3,2,2]
    int aux[7] = {1,3,2,1,3,2,2};
    int *nums;
    nums = aux;
    int numsSize = 7;
    int *returnSize = (int*)malloc(sizeof(int));
    int *res = numberOfPairs(nums, numsSize, returnSize);
    printf("[%d, %d] %d\n",res[0],res[1],*returnSize);
    return 0;
}

int notInArray(int num, int *arr, int arrSize){
    for(int i=0;i<arrSize;i++){
        if (arr[i]==num){
            return 0;
        }
    }
    return 1;
}

int* numberOfPairs(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int *res = (int*)malloc(2*sizeof(int));
    int *aux = (int*)malloc(sizeof(int));
    int i,j,c,auxSize=0, auxNumsSize = numsSize;
    
    res[0] = 0;
    res[1] = 1;

    for(i=0;i<numsSize;i++){
        c = 1;
        
        if(notInArray(nums[i],aux,auxSize)){
            for(j=i+1;j<numsSize;j++){
                if(nums[j]==nums[i]){
                    c++;
                }
            }
        }
        
        auxSize++;
        aux = realloc(aux,auxSize*sizeof(int));
        aux[auxSize-1] = nums[i];
        
        c = c/2;
        
        if(c>0){
            auxNumsSize -= c*2;
            res[0]++;
        }
    }
    res[1] = auxNumsSize;
    return res;
}
