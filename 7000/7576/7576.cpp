#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

int m[1000][1000], N, M, remain=0, ans;
queue<pii> q;
int dd[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>M>>N;
  FOR(j, 0, N) FOR(i, 0, M) {
    cin>>m[i][j];
    switch(m[i][j]){
      case 1:
        q.push(mp(i, j));
        break;
      case 0:
        ++remain;
    }
  }

  while(remain && !q.empty()){
    pii t = q.front();
    q.pop();

    for(auto d: dd){
      int x=t.X+d[0], y=t.Y+d[1];
      if(x<0 || x>=M || y<0 || y>=N) continue;
      if(m[x][y] != 0) continue;
      m[x][y] = (ans = m[t.X][t.Y])+1;
      q.push(mp(x, y));
      --remain;
    }
  }
  if(remain) ans = -1;

  cout<<ans;

  return 0;
}
