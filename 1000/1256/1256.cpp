#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b);

#define rep(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;

int MAX = 1000000005;

int dp[201][101];

int n, m, k;

int combi(int n, int m){
	if(n<0 || m<0) return 0;
	if(2*m > n) m = n - m;
	if(m==0) return 1;
	if(m==1) return n;
	if(dp[n][m] != -1) return dp[n][m];

	int a =  dp[n][m] = min(MAX, combi(n-1, m-1)+combi(n-1, m));
	return dp[n][m] = min(MAX, combi(n-1, m-1)+combi(n-1, m));
}

void solve(int n, int m, int k){
 //out4("solve", n, m, k);
	if(n*m<0) {
		return;
	}
	if(k==1){
		if(n>0){
			cout<<"a";
			return solve(n-1, m, 1);
		}else if(m>0){
			cout<<"z";
			return solve(n, m-1, 1);
		}else{
			return;
		}
	}
	int a__ = combi(n-1+m, m);

	if(a__ >= k){
		cout<<"a";
		return solve(n-1, m, k);
	} else{
		cout<<"z";
		return solve(n, m-1, k - a__);
	}
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  memset(dp, -1, sizeof(dp));

  cin>>n>>m>>k;

  if(combi(n+m, n) < k) {
	  cout << -1 << "\n";
	  return 0;
  }

  solve(n, m, k);

  cout<<"\n";
  return 0;
}
