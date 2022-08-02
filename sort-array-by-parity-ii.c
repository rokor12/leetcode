// leetcode.com/problems/sort-array-by-parity-ii/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize);

int compare(int* a, int *b);

int main(){
    int const numsSize = 4;
    int arr[4] = {4,2,5,7};
    int* nums = (int*)malloc(numsSize*sizeof(int));
    memcpy(nums,arr,numsSize*sizeof(int));
    int* ans;
    int* returnSize = malloc(sizeof(int));
    sortArrayByParityII(nums, numsSize, returnSize);
    //for(int i=0;i<numsSize;i++){
    //    printf("%d ",nums[i]);
    //}
    printf("END\n");
    return 0;
}

int compare(int* a, int *b){
    return *a%2;
}

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    qsort(nums,numsSize,sizeof(int), &compare);
    *returnSize = numsSize;
    int* ans = (int*)malloc(numsSize*sizeof(int));
    int i,j,aux;
    for(i=0;i<numsSize;i++){
        if((i%2 != nums[i]%2)){
            for(j=i+1;j<numsSize;j++){
                if (i%2 == nums[j]%2){
                    aux = nums[i];
                    nums[i] = nums[j];
                    nums[j] = aux;
                }
            }
        }
        ans[i] = nums[i];
    }
    return ans;
}
