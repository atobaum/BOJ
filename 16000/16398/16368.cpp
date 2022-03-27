#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, adj[1001][1001], visited[1000]={0}, edge_count=0;
ll cost = 0;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  priority_queue<pair<int, pii> > pq;

  cin>>N;
  for(int i=0;i<N;++i){
	  for(int j=0;j<N;++j){
		cin>>adj[i][j];
	  }
  }

  visited[0]=1;
  for(int i=1;i<N;++i){
	  pq.push(make_pair(-adj[0][i], make_pair(0, i)));
  }

  while(edge_count != N-1){
	pair<int, pii> temp = pq.top();
	pq.pop();
	if(visited[temp.second.second]) continue;

	int c = temp.first;
	int to = temp.second.second;
	edge_count++;
	visited[to] = 1;
	cost -= c;

	for(int i=0;i<N;++i){
		if(i==to || visited[i]) continue;
		pq.push(make_pair(-adj[to][i], make_pair(to, i)));
	}
  }

  cout<<cost<<"\n";
  return 0;
}
