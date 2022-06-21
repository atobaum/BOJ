#include <bits/stdc++.h>
using namespace std;

int n, x[200000], i;
double ans[200000]; 

double square(double v){
	return v*v;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>n;
  for(i=0;i<n;++i){
	  cin>>x[i]>>ans[i];
  }

  vector<int> st;
  st.push_back(0);

  for(i=1;i<n;++i){
	while(!st.empty()){
		int j = st.back();
		ans[i] = min(ans[i], 0.25 * square(x[i]-x[j]) / ans[j]);
		if(ans[j] < ans[i]) st.pop_back();
		else break;
	}
	st.push_back(i);
  }

  for(i=0;i<n;++i) printf("%.4f\n", ans[i]);

  return 0;
}

