#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> piii;
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

int t, n, dp[10081];
vector<piii> v;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  FOR(i, 0, t){
    int ans = 0, max_end = 0;
    v.clear();
    memset(dp, 0, sizeof(dp));

    cin >> n;
    FOR(j, 0, n){
      int s, d, p;
      cin>>s>>d>>p;
      v.push_back(mp(mp(s, s+d), p));
      max_end = max(max_end, s+d);
    }

    sort(v.begin(), v.end());

    for(auto a: v){
      int c = max(dp[a.X.Y], dp[a.X.X]+a.Y);
      FOR(k, a.X.Y, max_end){
        dp[k] = max(dp[k], c);
      }
      ans = max(ans, dp[a.X.Y]);
    }

    cout<<ans<<"\n";
  }

  return 0;
}
