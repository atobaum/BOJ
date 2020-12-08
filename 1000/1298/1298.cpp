// 이분매칭
#include <cstring> //memset
#include <iostream>
#include <vector>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in2(a, b) cin >> a >> b;
#define out1(a) cout << a << endl;

int N, M, cnt = 0;

// B[i]: i'th 노트북의 주인
int chk[101], B[101];
vector<int> preference[101];

int solve(int s);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(B, 0, sizeof(B));

  in2(N, M);
  reap(i, 0, M) {
    int a, b;
    in2(a, b);
    preference[a].push_back(b);
  }

  reap(i, 1, N + 1) {
    memset(chk, 0, sizeof(chk));
    cnt += solve(i);
  }

  out1(cnt);
  return 0;
}

int solve(int s) {
  for (int l : preference[s]) {
    if (chk[l])
      continue;
    chk[l] = 1;

    if (!B[l] || solve(B[l])) {
      B[l] = s;
      return 1;
    }
  }
  return 0;
}