#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, i;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>t;
  for(i=0;i<t;++i){
	  ll x, y, a, res;
	  cin>>x>>y;
	  y -= x;

	  a = floor(sqrt(y));
	  if(a==1){
		cout<<y<<"\n";
		continue;
	  }
	  res = 2*a-1;
	  y -= a*a;
	  while(y > 0){
		  y -= a;
		  res++;
	  } 
	  cout<<res<<"\n";
  }

  return 0;
}
