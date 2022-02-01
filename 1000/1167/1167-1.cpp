#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int V, visited[100001], diameter, farthest;
vector<pii> adj[100001];

void dfs(int s, int l){
	if(visited[s]) return;
	visited[s] = 1;
	for(pii t: adj[s]){
		if(visited[t.first]) continue;
		diameter = max(diameter, l + t.second);
		if(diameter == l + t.second) farthest = t.first;
		dfs(t.first, l + t.second);
	}
}


int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin >> V;

  for(int i=0;i<V;++i){
	  int a;
	  cin >> a;
	  
	  while(1){
		  int b, l;
		  cin >> b;
		  if(b == -1) break;
		  cin >> l;
		  adj[a].push_back(make_pair(b, l));
	  }
  }

  memset(visited, 0, sizeof(visited));
  diameter = 0;
  dfs(1, 0);

  memset(visited, 0, sizeof(visited));
  diameter = 0;
  dfs(farthest, 0);

  cout << diameter;

  return 0;
}
