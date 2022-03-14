#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > piii;

int N, M, max_k, min_k;
priority_queue<piii> q1, q2;

int find_root(int a, int *root){
	while(root[a]) a = root[a];
	return a;
}

int find_cost(priority_queue<piii> q){
	int cost = 0, edges = 0;
	int parent[1001] = {0}, depth[1001] = {0};

	while(edges < N){
		auto p = q.top();
		q.pop();

		int c = p.first;
		int a = p.second.first;
		int b = p.second.second;

		int ra = find_root(a, parent);
		int rb = find_root(b, parent);

		if(ra == rb) continue;

		if(depth[ra] < depth[rb]) swap(ra, rb);
		if(depth[ra] == depth[rb]) depth[ra]++;

		parent[rb] = ra;
		edges++;
		cost += c;
	}

	return cost;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N>>M;
  for(int i=0;i<M+1;++i){
	  int a, b, c;
	  cin>>a>>b>>c;
	  q1.push(make_pair(c, make_pair(a, b)));
	  q2.push(make_pair(1-c, make_pair(a, b)));
  }

  max_k = find_cost(q2);
  min_k = N - find_cost(q1);

  cout << max_k*max_k - min_k*min_k <<"\n";
  return 0;
}
