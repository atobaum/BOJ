#include <algorithm> //sort
#include <cmath>
#include <cstring>    //memset
#include <functional> //greater
#include <iostream>
#include <queue>
#include <utility> //pair
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long min, max;
  int nums[1000001];
  memset(nums, 0, sizeof(nums));

  cin >> min >> max;

  for (long long x = 2; x * x <= max; x++) {
    long long squre = x * x;
    for (long long i = (min / squre); squre * i <= max; i++) {
      if (i * squre - min >= 0)
        nums[i * squre - min] = 1;
    }
  }

  int count = 0;
  for (int i = 0; i <= max - min; i++) {
    if (nums[i] == 0)
      count++;
  }

  cout << count << endl;

  return 0;
}