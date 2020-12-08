#include <algorithm>  //sort
#include <cstring>    //memset
#include <functional> //greater
#include <iostream>
#include <queue>
#include <utility> //pair
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a
#define in2(a, b) cin >> a >> b
#define in3(a, b, c) cin >> a >> b >> c
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl
#define out2(a, b) cout << a << " " << b << endl
#define out3(a, b, c) cout << a << " " << b << " " << c << endl
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

int n, m, k;
vector<pii> adj[1000];
// tt[i]: 이때까지 찾은 i번째 도시까지 가는 경로 수
int tt[1000];
int max_cost = 0;
ll ans[1000];

void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(tt, 0, sizeof(tt));
  memset(ans, -1, sizeof(ans));

  in3(n, m, k);
  reap(i, 0, m) {
    int a, b, c;
    in3(a, b, c);
    max_cost = max(max_cost, c);
    adj[a - 1].push_back(make_pair(b - 1, c));
  }

  solve();

  reap(i, 0, n) out1(ans[i]);
  return 0;
}

void solve() {
  priority_queue<pli> q;

  q.push(make_pair(0, 0));

  while (!q.empty()) {
    int here = q.top().second;
    ll cost = q.top().first; // 음수
    q.pop();

    tt[here]++;
    if (tt[here] == k) {
      ans[here] = -cost;
    }

    if (tt[here] > k)
      continue;

    reap(i, 0, adj[here].size()) {
      int there = adj[here][i].first;
      int weight = adj[here][i].second;
      ll next_cost = cost - weight;
      if (tt[there] >= k)
        continue;

      q.push(make_pair(next_cost, there));
    }
  }
}
