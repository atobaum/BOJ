#include <algorithm> //sort
#include <cstring>
#include <functional> //greater
#include <iostream>
#include <queue>
#include <utility> //pair
#include <vector>
using namespace std;

int N, T[15], P[15];
int M[15];

// day 부터 일할 때 얻는 최대 수익. 0부터 시작
int solve(int day) {
  if (M[day] != -1)
    return M[day];
  if (day >= N)
    return 0;

  return M[day] = max(solve(day + 1),
                      day + T[day] <= N ? solve(day + T[day]) + P[day] : 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(M, -1, sizeof(M));
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> T[i] >> P[i];
  }

  cout << solve(0) << endl;
  return 0;
}