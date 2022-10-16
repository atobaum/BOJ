#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

int N, M, Q, B[2001];
vector<pii> W[2001];

void cal(){
  int t;
  ll ans = 0;
  FOR(i, 1, N+1){
    cin>>t;
    ans += t*B[i];
  }

  ans += B[2000]; // bias
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  memset(B, 0, sizeof(B));
  cin>>N>>M>>Q;

  FOR(i, 1, M+1){
    int c, t, p[2000], w[1000];
    cin>>c;
    FOR(j, 0, c) cin>>p[j];
    FOR(j, 0, c) cin>>w[j];
    FOR(j, 0, c) {
      W[i].push_back(mp(p[j], w[j]));
    }
    // bias
    cin>>t;
    W[i].push_back(mp(2000, t));
  }

  // output layer
  FOR(i, 1, M+1){
    int w;
    cin>>w;
    for(pii t: W[i]){
      B[t.X] += w * t.Y;
    }
  }
  // output bias
  int t;
  cin>>t;
  B[2000] += t;

  FOR(i, 0, Q) cal();

  return 0;
}
