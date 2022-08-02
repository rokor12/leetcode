#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int findInArray(int *arr, int arrSize, int num);

int main(){
    int nums1Size=3;
    int nums2Size=4;
    
    int *nums1 = (int*)malloc(nums1Size*sizeof(int));
    int *nums2 = (int*)malloc(nums2Size*sizeof(int));
    int *returnSize = malloc(sizeof(int));
    *returnSize =0;

    int arr1[3] = {4,1,2}, arr2[4] = {1,3,4,2};
    
    memcpy(nums1,arr1,nums1Size*sizeof(int));
    memcpy(nums2,arr2,nums2Size*sizeof(int));

    int *ans;
    ans = nextGreaterElement(nums1, nums1Size, nums2, nums2Size, returnSize);
    
    for(int i=0;i<*returnSize;i++){
        printf("%d ",ans[i]);
    }
    
    printf("\nEND\n");
    return 0;
}

int findInArray(int *arr, int arrSize, int num){
    for(int i=0;i<arrSize;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size;
    int *ans = (int*)malloc(nums1Size*sizeof(int));
    int i,j;
    for(i=0;i<nums1Size;i++){
        ans[i] = -1;
        j = findInArray(nums2, nums2Size,nums1[i]);
        for(j=j;j<nums2Size;j++){
            if(nums1[i]<nums2[j] && ans[i]==-1){
                ans[i] = nums2[j];
            }
        }
    }
    return ans;
}
