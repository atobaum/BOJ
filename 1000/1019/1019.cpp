#include<stdio.h>

/*
 풀이1
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
*/

// 풀이2
void solve(int num, int *answer){
	int p = 1;
	do{
		int quotient = num/(p*10);
		int digit = (num/p)%10;
		// for 0
		answer[0] += quotient * p;
		if(p != 1 && digit == 0)
			answer[0] -= p - 1 - num % p;

		// other digits
		for(int n = 1; n < 10; ++n){
			answer[n] += (quotient+1) * p;
			if(p == 1 && num < n)
				answer[n] -= 1;
			else if(digit < n)
				answer[n] -= p;
			else if (digit == n)
				answer[n] -= p - 1 - num % p;
		}

		p *= 10;
	} while(num / p != 0);
}

int main(){
	int n;
	int answer[10] = {0};
	scanf("%d", &n);

	solve(n, answer);
	for(int i = 0; i < 10; ++i)
		printf("%d ", answer[i]);
	printf("\n");
	return 0;
}
