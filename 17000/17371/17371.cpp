#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

// find the point which minimizes the maximum distance to other points.

int N;
vector<pii> pts;

int dist(pii a, pii b){
  return (a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N;
  FOR(i, 0, N){
    int a, b;
    cin>>a>>b;
    pts.push_back(mp(a, b));
  }
  
  int d=2000000000;
  pii ans;

  FOR(i, 0, N){
    int dd=0;
    FOR(j, 0, N){
      dd = max(dd, dist(pts[i], pts[j]));
    }

    if(dd < d) {
      ans = pts[i];
      d = dd;
    }
  }

  cout<<ans.X<<" "<<ans.Y<<"\n";

  return 0;
}
