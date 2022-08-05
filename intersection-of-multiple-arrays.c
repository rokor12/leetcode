#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int* intersection(int **nums, int numsSize, int *numsColSize, int *returnSize);

int main(){
    int numsSize = 3;
    int numsColSize[3]={5,4,4};
    int **nums = (int**)malloc(numsSize*sizeof(int*));
    int i,j;
    int *aux;
    int numsA[3][10] = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    for(i=0;i<numsSize;i++){
        aux = (int*)malloc(numsColSize[i]*sizeof(int));
        memcpy(aux,numsA[i],numsColSize[i]*sizeof(int));
        nums[i] = aux;
    }
    int *returnSize = malloc(sizeof(int));
    int *ans = intersection(nums, numsSize, numsColSize, returnSize);
    for(int i=0;i<*returnSize;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}

int compare(int *a, int *b){
    return *a - *b;
}

int* intersection(int **nums, int numsSize, int *numsColSize, int *returnSize){
    if(numsSize==1){
        *returnSize = numsColSize[0];
        qsort(nums[0], numsColSize[0], sizeof(int), &compare);
    }

    int *ans = (int*)malloc(sizeof(int));
    int i,j,k,c,size=0;
    int aux;
    for(i=0;i<numsColSize[0];i++){
        aux = nums[0][i];
        c=1;
        for(j=1;j<numsSize;j++){
            for(k=0;k<numsColSize[j];k++){
                if(aux == nums[j][k]){
                    c++;
                }
            }
            if(c == numsSize){
                size++;
                ans = realloc(ans,size*sizeof(int));
                ans[size-1] = aux;
            }
        }
    }
    *returnSize = size;
    qsort(ans,size,sizeof(int),&compare);
    return ans;
}
