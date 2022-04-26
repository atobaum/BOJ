#include <bits/stdc++.h>
using namespace std;

int N, S, arr[40];
vector<int> v1, v2;

void go(int i, int last, int sum, vector<int> &x) {
    if (i == last) {
        x.push_back(sum);
        return;
    }
    go(i + 1, last, sum + arr[i], x);
    go(i + 1, last, sum, x);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin >> N >> S;

  for(int i=0;i<N;++i){
	cin>>arr[i];
  }

  long long res = 0;

  go(0, N/2+1, 0, v1);
  go(N/2+1,N, 0, v2);

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  /*
   * 투포인터로 하는 경우
   * v1: 0 0, v2: 0 0 인경우 3개만 카운트된다.
   *
  int i=0, j=v2.size() - 1;
  while(i<v1.size() && j >= 0){
	  int s = v1[i] + v2[j];

	  if(s==S) {
		  res++;
		  if(j>0) j--;
		  else i++;
	  }else if(s < S){
		  i++;
	  }else{
		  j--;
	  }
  }
  */

  for (int a: v1) {
    auto l = lower_bound(v2.begin(), v2.end(), S - a);
    auto u = upper_bound(v2.begin(), v2.end(), S - a);
    res += u - l;
  }
  if (S == 0) res--;
  cout << res << "\n";

  return 0;
}
