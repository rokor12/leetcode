#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum {false, true} bool;

char* newPointer(int size);
int countWords(char **words1, int words1Size, char **words2, int words2Size);
int countWordInWords(char **words,int wordsSize,char *word);

int main(){
    int words1Size = 5;
    int words2Size = 3;
    char **words1 = (char**)malloc(words1Size*sizeof(char*));
    char **words2 = (char**)malloc(words2Size*sizeof(char*));
    char aux1[5][100] = {"leetcode", "is", "amazing", "as", "is"};
    char aux2[3][100] = {"amazing", "leetcode", "is"};
    char *aux;
    int w;

    for(w=0;w<words1Size;w++){
        aux = newPointer(strlen(aux1[w]));
        memcpy(aux,aux1[w], sizeof(char)*strlen(aux1[w]));
        words1[w] = aux;
        //printf("%s\n",words1[w]);
    }
    printf("\n");
    for(w=0;w<words2Size;w++){
        aux = newPointer(strlen(aux2[w]));
        memcpy(aux,aux2[w], sizeof(char)*strlen(aux2[w]));
        words2[w] = aux;
        //printf("%s\n",words2[w]);
    }
    int ans = countWords(words1, words1Size, words2, words2Size);
    printf("%d\n",ans);
    return 0;
}

char* newPointer(int size){
    return (char*)malloc(size*sizeof(char));
}

int countWordInWords(char **words,int wordsSize,char *word){
    int c=0;
    for(int i=0;i<wordsSize;i++){
        if(strcmp(words[i], word)==0){
            c++;
        }
    }
    return c;
}

int countWords(char **words1, int words1Size, char **words2, int words2Size){
    int ans = 0;
    int i;
    for(i=0;i<words1Size;i++){
        if(countWordInWords(words1, words1Size, words1[i]) == 1 && countWordInWords(words2, words2Size, words1[i]) == 1){
            ans++;
        }
    }
    return ans;
}
