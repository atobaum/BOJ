#include <bits/stdc++.h>
using namespace std;

double D, H, a, b, c;

double square_of_inverse_of_tan(double deg){
  double t = 1 / tan(deg * 3.14159265358979 / 180);
  return t*t;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>D>>H;

  while(1){
    cin>>a>>b>>c;
    if(a<= 0 || b<= 0 || c <= 0) return 0;

    double ans = H + D*sqrt(2 / (square_of_inverse_of_tan(a) + square_of_inverse_of_tan(c) - 2*square_of_inverse_of_tan(b)));
    printf("%.0f\n", ans);
  }

  return 0;
}
