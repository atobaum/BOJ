#include <bits/stdc++.h>
using namespace std;

int G, P, i, ans, available_gate[100001];

int getAvailableGate(int n){
	if(available_gate[n] == n) return n;

	return available_gate[n] = getAvailableGate(available_gate[n]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  ans = 0;

  cin >> G >> P;
  for(i=0;i<=G;i++) available_gate[i]=i;
  for(i=0;i<P;i++){
	int g, t;
	cin >> g;

	t = getAvailableGate(g);
	if(t) {
	  available_gate[t] = t - 1;
	  ans++;
	} else break;
  }

  cout << ans << "\n";

  return 0;
}
