#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)
int N, Q;
unordered_map<ll, ll> s, e;
unordered_set<ll> t;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin >> N;
  FOR(i, 0, N){
    ll l, r;
    cin>>l>>r;
    t.insert(l*1000000+r);

    auto ss = s.find(l);
    if(ss == s.end())
      s.insert(mp(l, r));
    else
      ss->Y = max(ss->Y, r);

    auto ee = e.find(r);
    if(ee == e.end())
      e.insert(mp(r, l));
    else
      ee->Y = min(ee->Y, l);
  }

  cin >> Q;
  FOR(i, 0, Q){
    ll l, r;
    cin >> l >> r;
    if(t.find(l*1000000+r) != t.end())
      cout<<"1\n";
    else if(s.find(l) != s.end() && s.find(l)->Y >= r &&
        e.find(r) != e.end() && e.find(r)->Y <= l)
      cout<<"2\n";
    else
      cout<<"-1\n";
  }

  return 0;
}
