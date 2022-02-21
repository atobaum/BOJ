#include <bits/stdc++.h>
using namespace std;

int N, M, indegree[1001] = {0}, dist[1001] = {0};
vector<int> st, adj[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>N>>M;
  for(int i=0;i<M;++i){
	  int a, b;
	  cin>>a>>b;

	  indegree[b]++;
	  adj[a].push_back(b);
  }

  for(int i=1;i<=N;++i){
	  if(!indegree[i]){
		  dist[i] = 1;
		  st.push_back(i);
	  }
  }

  while(!st.empty()){
	  int cur = st.back();
	  st.pop_back();

	  for(int to: adj[cur]){
		  dist[to] = max(dist[to], dist[cur]+1);
		  indegree[to]--;
		  if(indegree[to] == 0){
			  st.push_back(to);
		  }
	  }
  }

  for(int i=1; i<=N; ++i){
	  cout<<dist[i]<<" ";
  }

  return 0;
}
