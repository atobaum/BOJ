[문제](https://www.acmicpc.net/problem/1135)

## 풀이

루트에서 DFS를 한다.

1. 현재 노드가 잎사귀면 소식을 전할 사람이 없으므로 0
2. 모든 직속 부하에 대해 DFS를 재귀 호출해서 결과를 배열에 넣어놓는다.
3. 결과를 담은 배열을 내림차순으로 정렬한 후 순서대로 연락을 전한다.

- i번째 연락을 하는 사람은 i + 1분을 기다려야 하므로 걸리는 시간에 i + 1 더하기

4. 현재 노드가 직속부하한테 연락을 돌리는데 걸리는 시간(자식의 수)와 위에서 처리한 시간 중 최댓값을 리턴한다.

## 코드

```cpp
#include <algorithm>  //sort
#include <functional> //greater
#include <iostream>
#include <vector>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define out1(a) cout << a << endl;

int N;
vector<int> tree[50];

int dfs(int s);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  in1(N);

  int temp;
  reap(i, 0, N) {
    in1(temp);
    if (temp == -1)
      continue;
    tree[temp].push_back(i);
  }

  out1(dfs(0));
  return 0;
}

int dfs(int s) {
  vector<int> children = tree[s];
  vector<int> cost;

  int res = children.size();
  reap(i, 0, children.size()) { cost.push_back(dfs(children[i])); }
  sort(cost.begin(), cost.end(), greater<int>());

  reap(i, 0, cost.size()) { res = max(res, 1 + i + cost[i]); }
  return res;
}
```
