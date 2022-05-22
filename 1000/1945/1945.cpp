#include <bits/stdc++.h>
using namespace std;

#define mp(a, b) make_pair(a, b)

int n, i;
vector<pair<double, int> > arr;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> n;
  for(i=0;i<n;++i){
	  int xbl, ybl, xtr, ytr;
	  cin>>xbl>>ybl>>xtr>>ytr;
	  double angle=((double)ybl) / xtr;
	  arr.push_back(mp(angle, 0));
	  angle = ((double)ytr) / xbl;
	  arr.push_back(mp(angle, 1));
  }

  sort(arr.begin(),arr.end());

  int cur=0,ans=0;
  for(auto a: arr){
	  if(a.second){
		  cur--;
	  }else {
		  cur++;
		  ans = max(ans, cur);
	  }
  }

  cout<<ans<<"\n";

  return 0;
}
