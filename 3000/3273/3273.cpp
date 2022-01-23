#include <algorithm> //sort
#include <iostream>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define out1(a) cout << a << endl;

int n, a[100000], x;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  in1(n);
  reap(i, 0, n){
	  in1(a[i]);
  }
  in1(x);
  sort(a, a+n);

  int s = 0, e = n - 1, ans = 0;

  while(s < e){
	  int sum = a[s] + a[e];

	  if(sum > x) --e;
	  else if(sum < x) ++s;
	  else{
		++ans;
		++s;
		--e;
	  }
  }

  out1(ans);

  return 0;
}
