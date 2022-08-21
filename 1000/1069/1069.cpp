#include <bits/stdc++.h>
using namespace std;

int x, y, d, t;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>x>>y>>d>>t;
  double ans, s = sqrt(x*x+y*y);
  int j = s / d;

  // 걷기
  ans = s;

  s -= j*d;

  // 뛰고 걷기
  ans = min(ans, j*t + s);

  // 넘어가서 뒤로 걷기
  ans = min(ans, (j+1)*t + (d - s));

  // 삐딱하게 뛰고 마지막이 골인
  if(j) ans = min(ans, (double)(j+1)*t);
  // 두번만 뛰기
  else ans = min(ans, t*2.0);

  printf("%.14f\n", ans);

  return 0;
}
