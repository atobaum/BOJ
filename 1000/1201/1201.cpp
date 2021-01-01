#include <iostream>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in3(a, b, c) cin >> a >> b >> c;
#define out1(a) cout << a << endl;

// n-b+1 ... n 까지 출력
void print(int n, int b) {
  reap(i, n - b + 1, n + 1) { cout << i << ' '; }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // 증가, 감소
  int N, M, K;
  in3(N, M, K);

  if (M + K - 1 > N || M * K < N) {
    out1(-1);
    return 0;
  }

  print(N, M);
  N -= M;

  if (K == 1)
    return 0;

  int q = N / (K - 1);
  int r = N % (K - 1);

  reap(i, 0, K - 1) {
    int l = q + (i < r ? 1 : 0);
    print(N, l);
    N -= l;
  }

  return 0;
}