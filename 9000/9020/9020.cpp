#include <iostream>
#include <cstring>
using namespace std;

#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define out2(a, b) cout << a << " " << b << endl;

int p[10001];

void solve(int n){
	for(int i = n / 2; i >= 1; --i){
		if(p[i] != 0 && p[n - i] != 0) {
			out2(i, n-i);
			return;
		}
	}
}

int main() {
  int t, n;
  memset(p, 1, sizeof(p));

  for (int i = 2; i * 2 <= 5000; ++i) {
	for (int j = 2; i * j <= 10000; ++j) {
		p[i * j] = 0;
	}
  }

  in1(t);

  for(int i = 0; i < t; ++i){
	in1(n);
	solve(n);
  }

  return 0;
}
