#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

int minimumOperations(int* nums, int numsSize);

int main(){
    int nums[5] = {1,5,0,3,5};
    int numsSize = 5;
    printf("%d\n",minimumOperations(&nums, numsSize));
    return 0;
}

int minimumOperations(int* nums, int numsSize){
    int *aux = (int*)malloc(numsSize*sizeof(int));
    memcpy(aux, nums, numsSize*sizeof(int));
    bool flag = true,flag2;
    int i,mini,c=0;
    while(flag){
        flag = false;
        mini = aux[0];
        for(i=0;i<numsSize;i++){
            if(aux[i]!=0){
                flag = true;
                if(mini==0 || aux[i]<mini){
                    mini = aux[i];
                }
            }
        }
        if(flag){
            c++;
            for(i=0;i<numsSize;i++){
                if(aux[i]!=0){
                    aux[i]-=mini;
                }
            }
        }
    }
    return c;
}

