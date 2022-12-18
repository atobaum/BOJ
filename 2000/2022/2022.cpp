#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
double x, y, c, m, M, mid;

double calc(double d){
  return 1/sqrt(x*x-d*d) + 1/sqrt(y*y-d*d) - 1/c;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>x>>y>>c;
  m=0;
  M=min(x, y);
  while(M-m >= 1e-5){
    mid = (m+M)/2;

    if(calc(mid) > 0) M = mid;
    else m = mid;
  }

  cout << mid;

  return 0;
}
