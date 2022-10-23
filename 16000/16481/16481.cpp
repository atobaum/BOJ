#include <bits/stdc++.h>
using namespace std;

// https://ko.wikipedia.org/wiki/%EB%B0%A9%EC%A0%91%EC%9B%90
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int a, b, c;
  cin>>a>>b>>c;
  printf("%.8f\n", (1.0)*a*b*c/(a*b+b*c+c*a));

  return 0;
}
