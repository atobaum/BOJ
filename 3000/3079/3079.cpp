#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;

ll N, M, T[100000], T_max=0;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N>>M;
  FOR(i, 0, N) {
    cin>>T[i];
	T_max = max(T_max, T[i]);
  }

  ll s=1, e=T_max*M, ans=0;

  while(s<=e){
	ll m = (s+e)/2, cap=0;

	FOR(i, 0, N) {
      cap += m/T[i];
	  if(cap >= M) break;
	}
	if(cap < M) s = m+1;
	else {
		e = m-1;
		ans = m;
	}
  }

  cout<<ans<<"\n";

  return 0;
}
