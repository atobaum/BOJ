#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
int a[8], ans = 0;

bool match(){
  FOR(i, 0, 8){
    int x = a[i];
    int y = a[(i+1)%8];
    int z = a[(i+2)%8];
    if(sqrt(2)*x*z > x*y+y*z) return false;
  }
  return true;
}

void permutation(int d){
  if(d==8){
    if(match()) ++ans;
    return;
  }

  FOR(i, d, 8){
    swap(a[d], a[i]);
    permutation(d+1);
    swap(a[d], a[i]);
  }
}


int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  FOR(i, 0, 8) cin>>a[i];

  permutation(0);
  cout<<ans;

  return 0;
}
