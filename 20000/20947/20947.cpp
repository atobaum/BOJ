#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

// 0: empty, 1: bomb, 2: house, 3: debris
int N, m[2000][2000];
vector<pii> houses;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  memset(m, 0, sizeof(m));

  cin>>N;
  FOR(i, 0, N) FOR(j, 0, N){
    char t;
    cin>>t;
    switch(t){
      case '.':
        m[i][j] = 1;
        break;
      case 'O':
        m[i][j] = 2;
        houses.push_back(mp(i, j));
        break;
      default:
        m[i][j] = 3;
    }
  }

  for(auto h: houses){
    for(int x=h.X-1; x >= 0 && m[x][h.Y] <= 1; --x) m[x][h.Y] = 0;
    for(int x=h.X+1; x < N && m[x][h.Y] <= 1; ++x) m[x][h.Y] = 0;
    for(int y=h.Y-1; y >= 0 && m[h.X][y] <= 1; --y) m[h.X][y] = 0;
    for(int y=h.Y+1; y < N && m[h.X][y] <= 1; ++y) m[h.X][y] = 0;
  }

  FOR(i, 0, N) {
    FOR(j, 0, N){
      switch(m[i][j]){
        case 0:
          cout<<'.';
          break;
        case 1:
          cout<<'B';
          break;
        case 2:
          cout<<'O';
          break;
        case 3:
          cout<<'X';
          break;
      }
    }
    cout<<"\n";
  }

  return 0;
}
