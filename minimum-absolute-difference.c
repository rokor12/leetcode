// leetcode.com/problems/minimum-absolute-difference
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int** minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes);
int compare (int *a, int *b);

int main(){
    int const arrSize = 4;
    int *arr = (int*)malloc(arrSize*sizeof(int));
    int aux[4] = {4,2,1,3};
    memcpy(arr,aux,arrSize*sizeof(int));
    int *returnSize = malloc(sizeof(int));
    int **returnColumnSizes;
    int **ans;
    ans = minimumAbsDifference(arr, arrSize, returnSize, returnColumnSizes);
    printf("TEST: [%d,%d]\n",ans[0][0],ans[0][1]);
    int i,j;
    for(i=0;i<*returnSize;i++){
        for(j=0;j<2;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int compare (int *a, int *b){
    return *a - *b;
}

int** minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes){
    qsort(arr,arrSize,sizeof(int),&compare);
    int minAbsDif = arr[1] - arr[0];
    int i,j,ansSize=0;
    int **ans = (int**)malloc(sizeof(int*));
    int *aux;
    for(i=0;i<arrSize-1;i++){
        for(j=i+1;j<arrSize;j++){
            if(arr[j]-arr[i] == minAbsDif){
                aux = (int*)malloc(2*sizeof(int));
                aux[0] = arr[i];
                aux[1] = arr[j];
                ans[ansSize] = aux;
                ansSize++;
                ans = (int**)realloc(ans,ansSize);
                printf("[%d,%d]\n",ans[ansSize-1][0],ans[ansSize-1][1]);
            }
        }
    }
    *returnSize = ansSize;
    *returnColumnSizes = malloc(ansSize*sizeof(int*));
    for(i=0;i<ansSize;i++){
        *((*returnColumnSizes)+i) = 2;
    }
    return ans;
}
