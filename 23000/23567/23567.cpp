#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;

int n, k, arr[10001], ans=20000;
map<int, int> p, pp;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>n>>k;
  for(int i=0;i<n;++i) {
	cin>>arr[i];
	++p[arr[i]];
  }

  int s=0,e=0;

  while(e < n && s <= e){
	  if(p.size()==k && pp.size()==k) ans = min(ans, e-s);

	  if(pp.size()==k) {
		++p[arr[s]];
		--pp[arr[s]];
		if(!pp[arr[s]]) pp.erase(arr[s]);
		s++;
	  } else {
		++pp[arr[e]];
		--p[arr[e]];
		if(!p[arr[e]]) p.erase(arr[e]);
		e++;
	  }
  }

  if(ans == 20000) ans = 0;
  cout<<ans<<"\n";
  return 0;
}
