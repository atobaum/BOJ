#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

int N, ans=0;
ll bias = 1000000000;
vector<pii> pts;
unordered_set<ll> s;

ll toLL(ll x, ll y){
  return (x+bias)*2*bias + y+bias;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N;
  FOR(i, 0, N){
    int x, y;
    cin>>x>>y;
    pts.push_back(mp(x, y));
    s.insert(toLL(x, y));
  }

  sort(pts.begin(), pts.end());

  FOR(i, 0, N) FOR(j, i+1, N){
    pii a = pts[i], b = pts[j];
    if(a.X >= b.X || a.Y >= b.Y) continue;
    if(s.find(toLL(a.X, b.Y)) != s.end() && s.find(toLL(b.X, a.Y)) != s.end()){
      ++ans;
    }
  }

  cout<<ans;

  return 0;
}
