#include <algorithm> //sort
#include <iostream>
#include <vector>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define out1(a) cout << a << endl;

int N, C;
int l, r;
vector<int> pos;

bool check(int m){
	int cnt = 1;
	int last = pos[0];

	reap(i, 0, N){
		if(pos[i] - last >= m){
			cnt++;
			last = pos[i];
		}
	}

	return cnt >= C;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int temp;

  in2(N, C);
  reap(i, 0, N){
	in1(temp);
	pos.push_back(temp);
  } 

  sort(pos.begin(), pos.end());

  l = 1;
  r = pos[N - 1] - pos[0] + 1;

  while(r - l > 1){
	  int m = (r + l) / 2;
	  if(check(m)) l = m;
	  else r = m;
  }

  out1(l);

  return 0;
}
