#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int mod = 1000000007;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>n;
  --n;

  ll ans = 1, cur = 2;
  if(n == 0){
    ans = 1;
  } 

  while(n > 0){
    if(n % 2) {
      ans = (ans*cur) % mod;
      n--;
    }else {
      n /= 2;
      cur = (cur*cur) % mod;
    }
  }

  cout<<ans<<"\n";
  return 0;
}
