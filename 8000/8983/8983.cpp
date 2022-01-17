#include <algorithm> //sort
#include <iostream>
#include <utility> //pair
#include <vector>
using namespace std;

typedef pair<int, int> pii;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define out1(a) cout << a << endl;

#define MAX (1000000001)

int M, N, L, gun[1000000];
vector<pii> range;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  in3(M, N, L);
  reap(i, 0, M) in1(gun[i]);

  reap(i, 0, N){
	int x, y;
	in2(x, y);
	if(L < y) continue;
	range.push_back(make_pair(x - (L - y), x + (L - y)));
  }

  sort(gun, gun + M);
  sort(range.begin(), range.end());

  int j = 0;
  int res = 0;

  reap(i, 0, M){
	int x = gun[i];
	while(true){
		if(j >= range.size()) break;
		
		if(range[j].second < x) ++j;
		else if(range[j].first <= x){
			++res;
			++j;
		}else {
			break;
		}
	}
  }

  out1(res);

  return 0;
}
