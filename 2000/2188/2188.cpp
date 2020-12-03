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

#define MAX_MAP_SIZE 100 + 200 + 200

int flow[MAX_MAP_SIZE][MAX_MAP_SIZE], capacity[MAX_MAP_SIZE][MAX_MAP_SIZE];
int N, M;

int cow_offset = 2, house_offset;
int map_size;

int solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(flow, 0, sizeof(flow));
  memset(capacity, 0, sizeof(capacity));

  in2(N, M);
  house_offset = 2 + N;
  map_size = 2 + N + M;
  reap(i, 0, N) {
    // source to cow
    capacity[0][cow_offset + i] = 1;

    // cow to house
    int S, temp;
    in1(S);
    reap(j, 0, S) {
      in1(temp);
      capacity[cow_offset + i][house_offset + temp - 1] = 1;
    }
  }

  // house to sink
  reap(i, 0, M) { capacity[house_offset + i][1] = 1; }

  int answer = solve();
  out1(answer);

  return 0;
}

// 0 -> 1 길 찾기
bool bfs(int *parent) {
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    reap(i, 0, map_size + 1) {
      if (parent[i] == -1 && capacity[cur][i] > flow[cur][i]) {
        parent[i] = cur;

        if (i == 1)
          return true;
        q.push(i);
      }
    }
  }

  return false;
}

// 0 -> 1 최대 유량 구하기
int solve() {
  int res = 0;
  int parent[MAX_MAP_SIZE];

  while (true) {
    memset(parent, -1, sizeof(parent));
    if (!bfs(parent))
      break;

    // 유량 구하기
    int max_flow = INT_MAX;
    for (int cur = 1; cur != 0; cur = parent[cur]) {
      int p = parent[cur];
      max_flow = min(max_flow, capacity[p][cur] - flow[p][cur]);
    }

    // update
    for (int cur = 1; cur != 0; cur = parent[cur]) {
      int p = parent[cur];
      flow[p][cur] += max_flow;
      flow[cur][p] -= max_flow;
    }

    res += max_flow;
  }
  return res;
}