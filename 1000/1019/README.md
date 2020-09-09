# 1019 책페이지
[문제](https://www.acmicpc.net/problem/1019)

## 풀이
먼저 0의 개수를 구하자. 1의 자리에 나오는 0의 개수는 `N/10`개이다. 10의 자리수에 나오는 0의 개수는 우선 `(N/100)*10`개라고 하자. 근데 N의 10의 자리수가 0이면 더 추가하지 못했던 것을 빼주어야 한다(무슨말이지...). 즉 `10 - 1 - N/10`을...
```c
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
```

나머지 숫자도 비슷한 접근
```c
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

```
