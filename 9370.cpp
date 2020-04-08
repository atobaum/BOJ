#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

#define INF 1e8
using namespace std;

void solve(int n, vector<pair<int, int>> *adj, int start, vector<int> dest, int g, int h, vector<int> &ret){
	priority_queue<tuple<int, int, bool>> q;
	vector<int> dist;
	for(int i = 0; i < n; ++i)
		dist.push_back(INF);

	q.push(make_tuple(0, start, false));
	while(!q.empty() or dest.size() != 0){
		int here, cost;
		bool through;
		tie(cost, here, through) = q.top();
		q.pop();
		cost *= -1;

		vector<int>::iterator iter;
		iter = find(dest.begin(), dest.end(), here);
		if(iter != dest.end()){
			if(through)
				ret.push_back(here);
			dest.erase(iter);
		}
		
		for(int i = 0; i < adj[here].size(); ++i){
			int there, nextCost;
			there = adj[here][i].first;
			nextCost = adj[here][i].second;
			if(dist[there] > cost + nextCost){
				dist[there] = cost + nextCost;
				if((here == g && there == h) || (here == g && there == h)){
					through = true;
				}
				q.push(make_tuple(-(cost+nextCost), there, through));
			}
		}
	}

	sort(ret.begin(), ret.end());
}

int main(){
	int T, n, m, t, s, g, h, a, b, d, x;
	cin >> T;

	for(int i = 0; i < T; ++i){
		vector<pair<int, int>> adj[2001];
		vector<int> dest;
		vector<int> ret;

		cin >> n >> m >> t;
		cin >> s >> g >> h;
		//scanf("%d %d %d\n", &n, &m, &t);
		//scanf("%d %d %d\n", &s, &g, &h);
		for(int j = 0; j < m; ++j){
			//scanf("%d %d %d\n", &a, &b, &d);
			cin >> a >> b >> d;
			adj[a].push_back({b, d});
			adj[b].push_back({a, d});
		}

		for(int j = 0; j < t; ++j){
			//scanf("%d\n", &x);
			cin >> x;
			dest.push_back(x);
		}

		solve(n, adj, s, dest, g, h, ret);

		for(int j = 0; j < ret.size(); ++j){
			cout << ret[j] << " ";
		}
		cout << endl;
	}
	return 0;
}
