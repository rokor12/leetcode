#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int islandPerimeter(int** grid, int gridSize, int* gridColSize);

int main(){
    for(int i=0;i<=5;i++){
        printf("%d\n",i/5);
    }
    return 0;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i,j,ans;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1){
                if(i == 0){ //top side
                    if(j==0){ //top-left corner
                        ans += 4 - (grid[i+1][j]+grid[i][j+1]);
                    }
                    else if(j==gridColSize[i]-1){ //top-right side
                        ans += 4 - (grid[i+1][j]+grid[i][j-1]);
                    }
                    else{
                        ans += 4 - (grid[i+1][j]+grid[i][j+1]+grid[i][j-1]);
                    }
                }
                else if(i == gridSize-1){ //bottom side
                    if(j==0){ //bottom-left side
                        ans += 4 - (grid[i-1][j]+grid[i][j+1]);
                    }
                    else if(j == gridColSize[i]-1){ //bottom-right side
                        ans += 4 - (grid[i-1][j]+grid[i][j-1]);
                    }
                    else{
                        ans += 4 - (grid[i-1][j]+grid[i][j+1]+grid[i][j-1]);
                    }
                }
                else if(j == 0){ //left side
                    ans += 4 - (grid[i+1][j]+grid[i-1][j]+grid[i][j+1]);
                }
                else if(j == gridColSize[i]-1){ //right side
                    ans += 4 - (grid[i+1][j]+grid[i-1][j]+grid[i][j-1]);
                }
                else{
                    ans += 4 - (grid[i][j-1]+grid[i][j+1]+grid[i+1][j]+grid[i-1][j]);
                }
            }
        }
    }
    return ans;
}
