#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum { false, true } bool;

int main(){

	return 0;
}

int countPrimeSetBits(int left, int right){
	int ans = 0;
	for(left;left<=right;left++){
		if(isPrime(countBits(left))){
			ans+=1;
		}
	}
    return ans;
}
int isPrime(int num){
    if(num==1){
        return 0;
    }
	for(int i=2; i<=(int)sqrt(num);i++){
		if(!(num%i)){
			return 0;
		}
	}
	return 1;
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
