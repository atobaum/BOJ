#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)

int arr[1000000];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int N, K, t, s=0, e=0, odds=0, ans=0;

  cin>>N>>K;
  FOR(i, 0, N)
    cin>>arr[i];

  while(e < N){
    if(arr[e]%2){
      if(odds >= K){
        if(arr[s]%2)
          --odds;
        s++;
      }else{
        odds++;
        e++;
      }
    }else
      e++;
    ans = max(ans, e-s-odds);
  }
  cout<<ans;

  return 0;
}
