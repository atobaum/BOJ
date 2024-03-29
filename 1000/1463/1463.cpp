#include <bits/stdc++.h>
using namespace std;

int dp[1000001] = {0};

int solve(int n){
	if(n==1) return 0;
	if(dp[n]) return dp[n];

	int res = solve(n-1)+1;
	if(n % 3 == 0) res = min(res, solve(n/3)+1);
	if(n % 2 == 0) res = min(res, solve(n/2)+1);

	return dp[n]=res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n;
  cin >> n;

  cout << solve(n);

  return 0;
}
