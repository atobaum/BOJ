#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  vector<int> nbd[13];

  FOR(i, 0, 12){
    int x, y;
    cin>>x>>y;

    nbd[x].push_back(y);
    nbd[y].push_back(x);
  }

  FOR(i, 1, 13){
    if(nbd[i].size() == 3){
      // the sum degrees of neighborhood is 6
      int sum = 0;
      FOR(j, 0, 3) sum += nbd[nbd[i][j]].size();

      if(sum == 6){
        cout<<i<<"\n";
        break;
      }
    }
  }

  return 0;
}
