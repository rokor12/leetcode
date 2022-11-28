#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int main(){

	return 0;
}

int hammingDistance(int x, int y){
	return countBits(x^y);
}

int countBits(int num){
	int ans = 0;
	while(num){
		if(num&1){
			ans+=1;
		}
		num>>=1;
	}
	return ans;
}
