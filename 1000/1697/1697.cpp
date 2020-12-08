#include <cstring> //memset
#include <iostream>
#include <queue>
#include <utility> //pair
using namespace std;

typedef pair<int, int> pii;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in2(a, b) cin >> a >> b;
#define out1(a) cout << a << endl;

#define MAX 100000

int N, K;
bool chk[MAX + 1];
queue<pii> q;

bool push_queue(int cost, int pos) {
  if (pos == K)
    return true;

  if (pos < 1 || pos > MAX)
    return false;
  if (chk[pos])
    return false;

  chk[pos] = true;
  q.push(make_pair(cost + 1, pos));
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(chk, 0, sizeof(chk));

  in2(N, K);
  q.push(make_pair(0, N));

  if (N == K) {
    out1(0);
    return 0;
  }

  int ans;
  while (true) {
    pii cur = q.front();
    q.pop();

    int pos, cost;
    pos = cur.second;
    cost = cur.first;
    ans = cost + 1;

    if (push_queue(cost, pos + 1))
      break;
    if (push_queue(cost, pos - 1))
      break;
    if (push_queue(cost, 2 * pos))
      break;
  }

  out1(ans);
  return 0;
}