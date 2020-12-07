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