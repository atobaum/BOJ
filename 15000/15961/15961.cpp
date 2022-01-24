#include <iostream>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define out1(a) cout << a << endl;

int N, d, k, c, cur_sushi[3001] = {0}, belt[3000000];
int kinds = 0, ans = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> d >> k >> c;
  reap(i, 0, k) {
	  int cur;
	  cin >> cur;

	  belt[i] = cur;
	  if(!cur_sushi[cur]) ++kinds;
	  ++cur_sushi[cur];
  }

  ans = kinds + (cur_sushi[c] ? 0 : 1);

  // 먹기 시작하는 점
  reap(i, 0, N-k) {
	  int cur;
	  cin >> cur;

	  belt[i+k] = cur;

	  --cur_sushi[belt[i]];
	  if(!cur_sushi[belt[i]]) --kinds;
	  if(!cur_sushi[cur]) ++kinds;
	  ++cur_sushi[cur];

	  ans = max(ans, kinds + (cur_sushi[c] ? 0 : 1));
  }

  reap(i, N-k, N){
	  --cur_sushi[belt[i]];
	  if(!cur_sushi[belt[i]]) --kinds;
	  if(!cur_sushi[belt[i-N+k]]) ++kinds;
	  ++cur_sushi[belt[i-N+k]];

	  ans = max(ans, kinds + (cur_sushi[c] ? 0 : 1));
  }

  out1(ans);

  return 0;
}
