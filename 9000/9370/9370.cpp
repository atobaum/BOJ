#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> data_t;

int T, n, m, t, s, g, h;

vector<int> ret, dest_candidates;
vector<pair<int, int>> adj[2001];

void dijkstra(int start, int *dist) {
  priority_queue<data_t, vector<data_t>, greater<data_t>> q;
  q.push(make_pair(0, start));

  while (!q.empty()) {
    int here, cost;
    cost = q.top().first;
    here = q.top().second;
    q.pop();

    if (dist[here] < cost)
      continue;

    for (int i = 0; i < adj[here].size(); ++i) {
      int there, nextCost;
      there = adj[here][i].first;
      nextCost = adj[here][i].second;

      if (cost + nextCost < dist[there]) {
        dist[there] = cost + nextCost;
        q.push(make_pair(cost + nextCost, there));
      }
    }
  }
}

void solve() {
  int dist[2001];
  fill_n(dist, 2001, 50000 * 2 * 1000 + 2);
  dist[s] = 0;

  dijkstra(s, dist);

  for (int i = 0; i < dest_candidates.size(); i++) {
    int dest = dest_candidates[i];

    if (dist[dest] % 2 == 1)
      ret.push_back(dest);
  }

  sort(ret.begin(), ret.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for (int j = 0; j < m; ++j) {
      int a, d, b;
      cin >> a >> b >> d;

      d *= 2;
      if ((a == g && b == h) || (b == g && a == h)) {
        d -= 1;
      }
      adj[a].push_back(make_pair(b, d));
      adj[b].push_back(make_pair(a, d));
    }

    for (int j = 0; j < t; ++j) {
      int x;
      cin >> x;
      dest_candidates.push_back(x);
    }

    solve();

    // print
    for (int j = 0; j < ret.size(); ++j) {
      cout << ret[j] << " ";
    }
    cout << endl;

    // reset
    dest_candidates.clear();
    ret.clear();
    for (int i = 0; i < 2001; i++) {
      adj[i].clear();
    }
  }
  return 0;
}
