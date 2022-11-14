#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> piii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

int t, n, dp[10081];
vector<piii> v;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> t;
  FOR(i, 0, t){
    int max_end = 0;
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
      FOR(k, a.X.Y, max_end+1){
        if(dp[k] >= c) break;
        dp[k] = c;
      }
    }

    cout<<dp[max_end]<<"\n";
  }

  return 0;
}
