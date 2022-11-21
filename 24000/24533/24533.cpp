#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = a; i < b; i++)
int N;
ll a, b, c, d, ans=0;

// energy generation satisfies commutivity and associativity
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N;
  cin>>a>>b;
  FOR(i, 1, N){
    cin>>c>>d;
    ans += a*d+b*c;
    a+=c;
    b+=d;
  }

  cout<<ans;

  return 0;
}
