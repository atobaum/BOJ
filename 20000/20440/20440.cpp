#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define mp(a, b) make_pair(a, b)

int n, i;
vector<pii> arr;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>n;
  for(i=0;i<n;++i){
	  int a, b;
	  cin>>a>>b;
	  // set end time for 1 since end time is exclusive.
	  arr.push_back(mp(a, 1));
	  arr.push_back(mp(b, 0));
  }
  sort(arr.begin(), arr.end());

  int ctn = 0, ans = 0, s = 0, e = 0;
  // Is in the first maximum interval?
  bool cur = false;

  for(pii a: arr){
	  int t = a.first;
	  if(a.second){
		  ctn++;
		  if(ctn > ans){
			  ans = ctn;
			  s=t;
			cur=true;
		  }else if(ctn == ans && e == t){
			cur=true;
		  }
	  }else{
		  if(cur){
			  e = t;
			  cur = false;
		  }
		  ctn--;
	  }
  }

  cout<<ans<<"\n"<<s<<" "<<e<<"\n";

  return 0;
}
