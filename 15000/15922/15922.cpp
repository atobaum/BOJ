#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)

int N, a, b;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N;
  int ans = 0, s, e;

  cin>>s>>e;
  FOR(i, 1, N){
    cin>>a>>b;
    if(e >= a) {
      e = max(e, b);
    } else {
      ans += e - s;
      s = a;
      e = b;
    }
  }
  ans += e - s;
  cout<<ans<<"\n";
  return 0;
}
