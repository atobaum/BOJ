#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;

int N;
vector<int> n;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin >> N;
  FOR(i, 0, N){
    int t;
    cin>>t;
    n.push_back(t);
  }

  sort(n.begin(), n.end());

  int ans[3];
  ll min_abs = 3000000001;

  FOR(i, 0, N-2) {
    int a=i+1, b=N-1;
    while(a<b){
      ll s = (ll)n[i] + n[a] + n[b];
      if(abs(s) < min_abs){
        min_abs = abs(s);
        ans[0] = i;
        ans[1] = a;
        ans[2] = b;
      }

      if(s > 0) --b;
      else ++a;
    }
  }

  out3(n[ans[0]], n[ans[1]], n[ans[2]]);

  return 0;
}
