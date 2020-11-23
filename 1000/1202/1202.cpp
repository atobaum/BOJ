#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K, M, V, C;
  vector<pair<int, int> > gems;
  multiset<int> packs;

  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> M >> V;
    gems.push_back(make_pair(V, M));
  }

  for (int i = 0; i < K; ++i) {
    cin >> C;
    packs.insert(C);
  }

  long long result = 0;

  sort(gems.begin(), gems.end(), greater<pair<int, int> >());

  for (int i = 0; i < N; ++i) {
    pair<int, int> gem = gems[i];

    // 보석이 들어갈 수 있는 가방 찾기
    // gem.second 보다 큰 것 중 제일 작은 것
    multiset<int>::iterator iter = packs.upper_bound(gem.second - 1);
    if (iter != packs.end()) {
      result += gem.first;
      packs.erase(iter);
    }

    if (packs.empty())
      break;
  }

  cout << result << endl;
  return 0;
}
