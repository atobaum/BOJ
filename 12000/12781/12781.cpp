#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll commutator(int x1, int y1, int x2, int y2){
	return x1*y2-x2*y1;
}

ll ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	return commutator(x1, y1, x2, y2) + commutator(x2, y2, x3, y3) + commutator(x3, y3, x1, y1);
}


int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int x1, y1, x2, y2, x3, y3, x4, y4;

  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

  if(ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0)
	  cout << 1 << "\n";
  else
	  cout << 0 << "\n";

  return 0;
}
