#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

int N;
map<int, int> m;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>N;
  ll C = 0;

  m[0] = -1;
  m[N+1] = -1;

  int t;
  cin>>t;
  m[t] = 0;
  cout<<C<<"\n";

  FOR(i, 0, N-1){
    cin>>t;
    m[t] = max(
        prev(m.lower_bound(t),1)->Y,
        m.upper_bound(t)->Y
      ) + 1;

    C += m[t];
    cout<<C<<"\n";
  }

  return 0;
}
