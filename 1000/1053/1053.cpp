#include <algorithm>
#include <cstring>    //memset
#include <iostream>

using namespace std;

char str[51];
int dp[51][51];

int sol(int s, int e){
	int& res = dp[s][e];

	if(s >= e) return 0;
	if(res != -1) return res;

	res = 1 << 30;

	if(str[s] == str[e]){
		return res = sol(s + 1, e - 1);
	}


	// 뒤에 추가
	res = min(res, sol(s + 1, e) + 1);
	// 앞에 추가 
	res = min(res, sol(s, e - 1) + 1);
	// 한글자 변경
	res = min(res, sol(s + 1, e - 1) + 1);
    
	return res;
}

int main() {
  memset(dp, -1, sizeof(dp));

  cin >> str;

  int l = strlen(str);
  int res = sol(0, l - 1);

  for(int i = 0; i < l; ++i) for(int j = i + 1; j < l; ++j) {
	swap(str[i], str[j]);

	memset(dp, -1, sizeof(dp));

	res = min(res, sol(0, l - 1) + 1);
    
	swap(str[i], str[j]);
  }


  cout << res;

  return 0;
}

