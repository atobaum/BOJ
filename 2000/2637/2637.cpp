#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, cnt[101]={0}, indegree[101]={0};
vector<pii> adj[101];
queue<int> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>N>>M;
  for(int i=0;i<M;++i){
	  int x, y, k;
	  cin>>x>>y>>k;
	  adj[x].push_back(make_pair(y, k));
	  indegree[y]++;
  }

  cnt[N] = 1;
  q.push(N);

  while(!q.empty()){
	  int cur = q.front();
	  q.pop();

	  for(pii tmp: adj[cur]){
		  int to = tmp.first;
		  cnt[to] += cnt[cur]*tmp.second;
		  indegree[to]--;
		  if(!indegree[to]) q.push(to);
	  }
  }

  for(int i=1;i<=N;++i){
	  if(adj[i].empty()) cout<<i<<" "<<cnt[i]<<endl;
  }
  cout<<endl;

  return 0;
}
