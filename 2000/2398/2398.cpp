#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)

#define rep(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;

int n, m, a, b, c, dist[3][1001];
vector<pii> adj[1001];
set<int> edges;

void calcDist(int s, int* dist){
	dist[s] = 0;
	priority_queue<pii> q;
	q.push(mp(0, s));

	while(!q.empty()){
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();

		if(cost > dist[cur]) continue;

		for(pii t: adj[cur]){
			int next_cost = cost + t.second;
			if(dist[t.first] == -1 || next_cost < dist[t.first]){
			  dist[t.first] = next_cost;
			  q.push(mp(-next_cost, t.first));
			}
		}
	}
}

void findPath(int s, int e, int *dist){
	int cur = e;

	while(cur != s){
		for(pii t: adj[cur]){
			if(dist[t.first] + t.second == dist[cur]){
				int to = t.first;
				edges.insert((min(cur, to)*1000)+max(cur, to));
				cur = to;
			}
		}

	}
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);


  cin>>n>>m;
  for(int i=0;i<m;++i){
	  cin>>a>>b>>c;
	  adj[a].push_back(make_pair(b, c));
	  adj[b].push_back(make_pair(a, c));
  }
  cin>>a>>b>>c;

  memset(dist, -1, sizeof(dist));
  calcDist(a, dist[0]);
  calcDist(b, dist[1]);
  calcDist(c, dist[2]);

  int center, cost = 9999999;
  for(int i=0;i<n;++i){
	  int next_cost = dist[0][i]+dist[1][i]+dist[2][i];
	  if(next_cost > 0 && cost > next_cost){
		  cost = next_cost;
		  center = i;
	  }
  }

  findPath(a, center, dist[0]);
  findPath(b, center, dist[1]);
  findPath(c, center, dist[2]);


  cout << cost << " " << edges.size() << "\n";
  for(auto e: edges){
	cout << (e / 1000) << " " << (e % 1000) << "\n";
  }

  return 0;
}
