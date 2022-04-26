#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int V, E, cost=0, edge_count=0, parent[10001] = {0}, depth[10001]={0};
vector<pair<int, pii> > edges;

int find(int a){
	while(parent[a]) a = parent[a];
	return a;
}

void uni(int a, int b){
	int p = find(a);
	int q = find(b);

	if(depth[p] < depth[q]) swap(p, q);
	if(depth[p] == depth[q]) depth[p]++;
	parent[q] = p;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>V>>E;

  for(int i=0;i<E;++i){
	  int a, b, c;
	  cin>>a>>b>>c;
	  edges.push_back(make_pair(c, make_pair(a, b)));
  }

  sort(edges.begin(), edges.end());

  for(auto temp: edges){
	int c = temp.first;
	int a = temp.second.first;
	int b = temp.second.second;

	if(find(a) == find(b)) continue;

	uni(a, b);

	edge_count++;
	cost += c;

	if(edge_count == V - 1) break;
  }

  cout<<cost<<"\n";

  return 0;
}
