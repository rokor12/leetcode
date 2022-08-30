#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, int* items2ColSize, int* returnSize, int** returnColumnSizes);

int main(){
    //items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
    //[[1,6],[3,9],[4,5]]
    return 0;
}

int compare(int *a, int *b){
    return *a[0] - *b[0];
    qsort(void *base, size_t nmemb, size_t size, int (*comparator)(const void *, const void *));
}

int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, int* items2ColSize, int* returnSize, int** returnColumnSizes){
    int i,j;
    int ** ans = (int**)malloc(items1Size*sizeof(int*));
    int ansSize = items1Size;
    int *aux;
    int *col = (int*)malloc(items1Size*sizeof(int));
    bool flag;
    for(i=0;i<items1Size;i++){//cpy items1 to ans
        aux = malloc(2*sizeof(int));
        memcpy(aux,items1[i],2*sizeof(int));
        ans[i]=aux;
        col[i] = 2;
    }
    for(i=0;i<items2Size;i++){
        flag = true;
        for(j=0;j<ansSize && flag;j++){
            if(items2[i][0]==ans[j][0]){
                flag = false;
                ans[j][1]+=items2[i][1];
            }
        }
        if(flag){
            ansSize++;
            ans = realloc(ans,ansSize*sizeof(int*));
            aux = malloc(2*sizeof(int));
            ans[ansSize-1] = aux;
            memcpy(ans[ansSize-1],items2[i],2*sizeof(int));
            col = realloc(col,ansSize*sizeof(int));
            col[ansSize-1] = 2;
            
        }
    }
    qsort(ans,ansSize,sizeof(int*),compare);
    *returnSize = ansSize;
    *returnColumnSizes = col;
    return ans;
}
