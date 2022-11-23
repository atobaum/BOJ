#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)

struct pt{
 int x;
 int y;
 int z;
};

int M, N, H, m[100][100][100], ans = 0, remain = 0;
int dd[6][3] = {{1, 0, 0},{-1, 0, 0},{0, 1, 0},{0, -1, 0},{0, 0, 1},{0, 0, -1}};
queue<pt> q;


int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>M>>N>>H;
  FOR(k, 0, H) FOR(j, 0, N) FOR(i, 0, M){
    cin>>m[i][j][k];
    if(m[i][j][k] == 1) q.push((pt){i, j, k});
    else if(m[i][j][k] == 0) ++remain;
  }

  while(!q.empty() && remain){
    auto t = q.front();
    q.pop();

    for(auto d: dd){
      int x=t.x+d[0], y=t.y+d[1], z=t.z+d[2];
      if(x<0||x>=M||y<0||y>=N||z<0||z>=H) continue;
      if(m[x][y][z] != 0) continue;

      m[x][y][z] = (ans = m[t.x][t.y][t.z]) + 1;
      q.push((pt){x, y, z});
      --remain;
    }
  }

  if(remain) ans = -1;
  cout<<ans;

  return 0;
}
