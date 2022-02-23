#include <bits/stdc++.h>
using namespace std;

int T, n, m, prev_rank[501], adj[501][501], indegree[501];

void solve(){
	int cur=-1, i;
	vector<int> ans;
	for(i = 1; i<=n; ++i){
		if(!indegree[i]) {
			cur = i;
			++i;
		}
	}
	for(; i<n; ++i){
		if(!indegree[i]){
			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
	}
	if(cur==-1){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	ans.push_back(cur);

	while(ans.size() != n){
		bool cur_updated = false;
		for(i = 1; i<=n; ++i){
			if(!adj[cur][i]) continue;
			indegree[i]--;
			if(indegree[i] < 0){
				cout<<"IMPOSSIBLE"<<endl;
				return;
			}
			if(!indegree[i]){
				if(!cur_updated){
					cur = i;
					cur_updated = true;
				}else{
					cout<<"?"<<endl;
					return;
				}
			}
		}
		if(!cur_updated){
			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
		ans.push_back(cur);
	}

	for(int i: ans) cout<<i<<" ";
	cout<<endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  
  cin>>T;
  for(int t=0;t<T;++t){
	  memset(adj, 0, sizeof(adj));
	  memset(prev_rank, 0, sizeof(prev_rank));
	  memset(indegree, 0, sizeof(indegree));
	  cin>>n;
	  for(int i=0;i<n;++i){
		  cin>>prev_rank[i];
		  for(int j=0;j<i;++j){
			  adj[prev_rank[j]][prev_rank[i]] = 1;
			  indegree[prev_rank[i]]++;
		  }
	  }
	  cin>>m;
	  for(int i=0;i<m;++i){
		int a, b, tmp;
		cin>>a>>b;
		adj[a][b] = (adj[a][b] + 1)%2;
		adj[b][a] = (adj[b][a] + 1)%2;
		if(adj[a][b]){
			indegree[a]--;
			indegree[b]++;
		}else{
			indegree[a]++;
			indegree[b]--;
		}
	  }
	  solve();
  }

  return 0;
}
