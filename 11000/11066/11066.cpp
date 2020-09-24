#include<iostream>

using namespace std;

inline int min(int x, int y){
	return x > y ? y : x;
}

// [i, j)까지 합치는데의 최소 비용
int DP(int i, int j, int (*memo)[501], int *sum){
	int res = INT_MAX;
	if(j - i <= 1) return 0;
	if(memo[i][j] != 0) return memo[i][j];
	
	for(int k = i+1; k < j; ++k){
		int can = DP(i, k, memo, sum) + DP(k, j, memo, sum) + sum[j] - sum[i];
		res = min(res, can);
	}
	memo[i][j] = res;
	return res;
}

int solve(int n, int *data){
	int sum[501] = {0};
	int memo[501][501] = {0};
	int tmp = 0;

	for(int i = 0; i < n; ++i){
		tmp += data[i];
		// sum[i] = sum[0...i)
		sum[i+1] = tmp;
	}

	int res = DP(0, n, memo, sum);
	return res;
}

int main(){
	int T, K, data[500];
	int tmp;

	cin >> T;
	for(int i = 0; i < T; ++i){
		cin >> K;
		for(int j = 0; j < K; ++j){
			cin >> tmp;
			data[j] = tmp;
		}

		cout << solve(K, data) << endl;
	}
	return 0;
}
