#include <iostream>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define out1(a) cout << a << endl;

int N, acc[50001] = {0};
int sum = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int temp;

  in1(N);
  reap(i, 0, N){
	  in1(temp);
	  sum += temp;
	  acc[i+1] = sum;
  }

  int s = 0, e = 1, res = 0;

  while(e < N){
	  int l = acc[e] - acc[s];
	  int min_l = min(l, sum - l);
	  res = max(res, min_l);

	
	  if(l > sum / 2) s++;
	  else e++;
  }
  
  out1(res);

  return 0;
}
