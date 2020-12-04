#include <algorithm> //sort
#include <climits>
#include <cstring>    //memset
#include <functional> //greater
#include <iostream>
#include <queue>
#include <utility> //pair
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;

int V, max_length, vertex;
int visited[100001];
vector<pii> adj[100001];

// s에서 가장 먼 vertex와 length에 길이 저장. l은 현재까지 길이
void dfs(int s, int l);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  in1(V);
  reap(i, 0, V) {
    int v, a, b;
    in1(v);
    while (true) {
      in1(a);
      if (a == -1)
        break;
      in1(b);

      adj[v].push_back(make_pair(a, b));
    }
  }

  max_length = 0;
  memset(visited, 0, sizeof(visited));
  dfs(1, 0);

  max_length = 0;
  memset(visited, 0, sizeof(visited));
  dfs(vertex, 0);
  out1(max_length);

  return 0;
}

void dfs(int s, int l) {
  visited[s] = 1;
  if (l > max_length) {
    vertex = s;
    max_length = l;
  }

  reap(i, 0, adj[s].size()) {
    if (!visited[adj[s][i].first]) {
      dfs(adj[s][i].first, l + adj[s][i].second);
    }
  }
}