#include<stdio.h>

// 0의 개수
int number_of_zero(int num){
	// current power
	int p = 1, sum = 0;
	do{
		sum += (num/(p*10)) * p;
		if(p != 1 && (num/p)%10 == 0)
			sum -= p - 1 - num % p;
		p *= 10;
	} while(num / p != 0);
	return sum;
}

// [1, num]을 10진법으로 나열했을 때 n의 개수
int number_of_n(int num, int n){
	int p = 1, sum = 0;
	do{
		sum += (num/(p*10)+1) * p;
		if(p==1 && num < n)
			sum -= 1;
		else if((num/p)%10 < n)
			sum -= p;
		else if ((num/p)%10 == n)
			sum -= p - 1 - num % p;
		p *= 10;
	} while(num / p != 0);
	return sum;
}

int main(){
	int n;
	scanf("%d", &n);

	printf("%d ", number_of_zero(n));
	for(int i = 1; i < 10; ++i)
		printf("%d ", number_of_n(n, i));
	printf("\n");
	return 0;
}

