#include <bits/stdc++.h>
using namespace std;

int N, K, mod=1000000000, dp[400][201]={0,};

int c(int n, int m){
  if(n/2<m) m = n-m;
  if(m == 0) return 1;
  if(dp[n][m]) return dp[n][m];

  return dp[n][m] = (c(n-1, m)+c(n-1, m-1)) % mod;
}

// _kH_n = combination(N+K-1, N)
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N>>K;
  cout<<c(N+K-1, N);
  return 0;
}
