#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;

int N, M, x, y, visited[100001]={0,};
vector<pii> adj[100001];
priority_queue<pii> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N>>M;

  FOR(i, 0, N){
    int a, b, c;
    cin>>a>>b>>c;
    adj[a].push_back(mp(b, c));
    adj[b].push_back(mp(a, c));
  }

  cin>>x>>y;

  q.push(mp(1000000001, x));
  visited[x] = 1000000001;

  while(!q.empty()){
    int cur = q.top().Y;
    int cost = q.top().X;

    q.pop();
    out3("cur, cost", cur, cost);

    if(cur == y) {
      cout<<cost<<"\n";
      break;
    }

    visited[cur] = min(visited[cur], cost);

    for(auto t: adj[cur]) {
      if(visited[t.X] <= min(visited[cur], t.Y)) {
        visited[t.X] = min(visited[cur], t.Y);
        q.push(mp(visited[t.X], t.X));
      }
    }
  }

  return 0;
}
