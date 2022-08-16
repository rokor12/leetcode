#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <math.h>

int arithmeticTriplets(int* nums, int numsSize, int diff);
int compare(int *a, int *b);
int main(){
    int numsSize = 6;
    int diff = 3;
    int aux[6] = {0,1,4,6,7,10};
    int *nums = (int*)malloc(numsSize*sizeof(int));
    memcpy(nums, aux, numsSize*sizeof(int));
    int res = arithmeticTriplets(nums, numsSize, diff);
    printf("%d\n",res);
    return 0;
}

int compare(int *a, int *b){
    return *a - *b;
}

int arithmeticTriplets(int* nums, int numsSize, int diff){
    //qsort(nums, numsSize, sizeof(int), &compare);
    int i,j,k,res=0;
    for(i=0;i<numsSize-2;i++){
        for(j=i+1;j<numsSize-1;j++){
            for(k=j+1;k<numsSize;k++){
                if(nums[j]-nums[i]==diff && nums[k]-nums[j]==diff){
                    res++;
                }
            }
        }
    }
    return res;
}
