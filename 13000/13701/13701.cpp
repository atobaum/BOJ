#include <bits/stdc++.h>
using namespace std;

bitset<1<<25> bs;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int t;
  while(cin>>t){
	  if(!bs.test(t)){
		cout<<t<<" ";
		bs.set(t, true);
	  }
  }
  cout<<"\n";
  return 0;
}
