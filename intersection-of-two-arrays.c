#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
bool isInArr(int *arr, int arrSize,int n);

int main(){

    return 0;
}

bool isInArr(int *arr, int arrSize,int n){
    for(int i=0;i<arrSize;i++){
        if(arr[i]==n){
            return true;
        }
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *ans = (int*)malloc(0);
    int ansSize = 0;
    for(int i=0;i<nums1Size;i++){
        if(isInArr(nums2,nums2Size,nums1[i]) && !(isInArr(ans,ansSize,nums1[i]))){
            ansSize++;
            ans = realloc(ans,ansSize*sizeof(int));
            ans[ansSize-1] = nums1[i];
        }
    *returnSize = ansSize;
    return ans;
}
