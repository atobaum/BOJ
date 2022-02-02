#include<bits/stdc++.h>
using namespace std;

int N,neighborhood[300001] = {0};
vector<int> adj[300001];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>N;
  for(int i=0;i<N-1;++i) {
	  int a, b;
	  cin>>a>>b;
	  adj[a].push_back(b);
	  adj[b].push_back(a);
  }

  // D - 3*G
  //long long res = 0;
  long long D = 0;
  long long G = 0;

  for(int i=1;i<=N;++i){
	long long temp = adj[i].size();
	// res += number_of_chain(i);
	// res -= 3 * n
	G += temp * (temp-1) * (temp-2) / 6;

	for(int b: adj[i]){
		D += (temp-1) * (adj[b].size() - 1);
	}
  }

  D /= 2;

  if(D > G * 3) cout << "D";
  else if(D < G * 3) cout <<"G";
  else cout << "DUDUDUNGA";

  return 0;
}
