#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, temp_v;
ll res=0;
vector<pii> adj[2001];

int dfs(int s, ll *dist, int a, int b){
	int furthest = s;
	for(auto p: adj[s]){
		if((s == a && p.first == b) || (s == b && p.first == a)) continue;
		if(!dist[p.first]){
			dist[p.first] = dist[s] + p.second;
			int v = dfs(p.first, dist, a, b);
			if(dist[furthest] < dist[v]) furthest = v;
		}
	}

	return furthest;
}

// diameter of tree containing vertex a, whose edge from a to b is excluded.
ll diam(int a, int b){
	int furthest;
	ll dist[2001] = {0};
	
	// to check vertex is visited
	dist[a] = 1;
	furthest = dfs(a, dist, a, b);

	memset(dist, 0, sizeof(dist));
	dist[furthest] = 1;
	furthest = dfs(furthest, dist, a, b);
	return dist[furthest] - 1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N;
  for(int i=1;i<N;++i) {
	  int a, b, c;
	  cin>>a>>b>>c;
	  adj[a].push_back(make_pair(b, c));
	  adj[b].push_back(make_pair(a, c));
  }

  for(int s=0;s<N;++s){
	  for(pii p: adj[s]){
		  if(s >= p.first) continue;
		  res = max(res, diam(s, p.first) + diam(p.first, s) + p.second);
	  }
  }

  cout<<res<<endl;
  return 0;
}
