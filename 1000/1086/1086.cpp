#include <algorithm>  //sort
#include <cstring>    //memset
#include <functional> //greater
#include <iostream>
#include <queue>
#include <utility> //pair
#include <vector>
using namespace std;

int N, K;
long long dp[1 << 16][101];
string nums[15];
int nums_residue[15];
// tenth_residue[i]는 10^i % K
int tenth_residue[51];

long long gcd(long long a, long long b) {
  while (b) {
    long long r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int bit_count(int bitmask) {
  int c = 0;
  while (bitmask != 0) {
    c += bitmask & 1;
    bitmask >>= 1;
  }

  return c;
}

long long solve(int bitmask, int r) {
  //   cout << "solve" << bitmask << " " << r << endl;
  if (bit_count(bitmask) == N) {
    if (r == 0)
      return 1;
    else
      return 0;
  }

  long long result = 0;
  if (dp[bitmask][r] != -1)
    return dp[bitmask][r];

  for (int i = 0; i < N; i++) {
    if ((bitmask & (1 << i)) == 0) {
      int next_r = (r * tenth_residue[nums[i].length()] + nums_residue[i]) % K;
      result += solve(bitmask | (1 << i), next_r);
    }
  }

  return dp[bitmask][r] = result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> nums[i];
  cin >> K;

  // 전처리
  tenth_residue[0] = 1;
  for (int i = 1; i <= 50; i++) {
    tenth_residue[i] = (tenth_residue[i - 1] * 10) % K;
  }

  for (int i = 0; i < N; i++) {
    string num = nums[i];
    int residue = 0;

    for (int j = 0; j < num.length(); j++) {
      residue = (residue * 10 + (num[j] - '0')) % K;
    }
    nums_residue[i] = residue;
  }

  long long numerator = solve(0, 0);
  long long denumerator = 1;

  if (numerator == 0) {
    cout << "0/1" << endl;
  } else {
    long long denumerator = 1;
    for (int i = 1; i <= N; i++) {
      denumerator *= i;
    }
    long long g = gcd(denumerator, numerator);
    cout << numerator / g << "/" << denumerator / g << endl;
  }

  return 0;
}