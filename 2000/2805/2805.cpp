#include <algorithm> //sort
#include <iostream>
using namespace std;

#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define out1(a) cout << a << endl;

int N, M, height[1000001];
int l, r;

bool check(int h){
	long long sum = 0;
	for(int i = N - 1; i >= 0 ; --i){
		if(height[i] < h) break;
		sum += height[i] - h;
		if(sum >= M) return true;
	}
	return sum >= M;
}

void solve(){
	while(r - l > 1){
		int m = l + (r - l) / 2;
		if(check(m)){
			l = m;
		} else{
			r = m;
		}
	}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  in2(N, M);
  for(int i = 0; i < N; ++i){
	  in1(height[i]);
  };
  sort(height, height + N);
  l = 0; r = height[N - 1] + 1;

  solve();
  out1(l);

  return 0;
}

