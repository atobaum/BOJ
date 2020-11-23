#include <cstring>
#include <iostream>

using namespace std;

int N, P, cost[16][16], M[1 << 17];
string factory_status;

int count_bit(int bits) {
  int count = 0;
  while (bits != 0) {
    count += bits % 2;
    bits >>= 1;
  }

  return count;
}

// 적어도 하나는 켜져있다.
int solve(int status) {
  // 조건 만족
  if (count_bit(status) >= P)
    return 0;

  if (M[status] != -1)
    return M[status];

  int cur_cost = 2000;

  // 켜져있는거 찾기
  for (int on = 0; on < N; on++) {
    if (status & (1 << on)) {
      // 꺼져있는거 찾기
      for (int off = 0; off < N; off++) {
        if ((~status) & (1 << off)) {
          cur_cost = min(cur_cost, solve(status | (1 << off)) + cost[on][off]);
        }
      }
    }
  }

  return M[status] = cur_cost;
}

int main() {
  memset(M, -1, sizeof(M));

  cin >> N;
  for (int i = 0; i < N * N; i++) {
    cin >> cost[i / N][i % N];
  }

  int bitmask = 0;
  cin >> factory_status;
  for (int i = 0; i < factory_status.size(); i++) {
    if (factory_status[i] == 'Y') {
      bitmask |= 1 << i;
    }
  }
  cin >> P;

  // 다 꺼져있을 떄
  if (count_bit(bitmask) == 0) {
    if (P == 0) {
      cout << 0 << endl;
    } else {
      cout << -1 << endl;
    }

    return 0;
  }

  cout << solve(bitmask) << endl;

  return 0;
}