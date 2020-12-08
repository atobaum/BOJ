#include <cstring> //memset
#include <iostream>
#include <queue>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define out1(a) cout << a << endl;

int T, N, M;
queue<int> q;
// priority_count[i]: 중요도 i인 문서의 개수
int priority_count[10], priority[101], cnt;

int solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  in1(T);
  reap(t, 0, T) {
    while (!q.empty())
      q.pop();
    memset(priority_count, 0, sizeof(priority_count));
    cnt = 0;

    in2(N, M);
    reap(i, 0, N) {
      int p;
      in1(p);

      priority[i] = p;
      priority_count[p]++;
      q.push(i);
    }

    solve();
    out1(cnt);
  }

  return 0;
}
int solve() {
  while (true) {
    int cur = q.front();
    q.pop();

    bool flag = false;
    reap(i, priority[cur] + 1, 10) {
      if (priority_count[i]) {
        flag = true;
        break;
      };
    }

    // 더 높은게 있으면 뒤어 넣기
    if (flag) {
      q.push(cur);
    } else {
      // 프린트하기
      cnt++;
      priority_count[priority[cur]]--;
      if (cur == M)
        return cnt;
    }
  }
}