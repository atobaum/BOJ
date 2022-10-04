#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
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

int N, x[100000], y[100000], z[100000], parent[100000];
priority_queue<piii> q;
vector<pii> stars_x, stars_y, stars_z;

int get_root(int a){
  if(parent[a] == -1) return a;
  return parent[a] = get_root(parent[a]);
}

void merge(int a, int b){
  parent[get_root(a)] = get_root(b);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  memset(parent, -1, sizeof(parent));

  cin>>N;
  FOR(i, 0, N) {
    int x,y,z;
    cin>>x>>y>>z;
    stars_x.push_back(mp(x, i));
    stars_y.push_back(mp(y, i));
    stars_z.push_back(mp(z, i));
  }
  sort(stars_x.begin(), stars_x.end());
  sort(stars_y.begin(), stars_y.end());
  sort(stars_z.begin(), stars_z.end());

  FOR(i, 0, N-1){
    q.push(mp(stars_x[i].X - stars_x[i+1].X, mp(stars_x[i].Y, stars_x[i+1].Y)));
    q.push(mp(stars_y[i].X - stars_y[i+1].X, mp(stars_y[i].Y, stars_y[i+1].Y)));
    q.push(mp(stars_z[i].X - stars_z[i+1].X, mp(stars_z[i].Y, stars_z[i+1].Y)));
  }

  int e = 0;
  ll cost = 0;

  while(e < N-1){
    int c = -q.top().X, a = q.top().Y.X, b = q.top().Y.Y;
    q.pop();
    
    if(get_root(a) == get_root(b)) continue;

    e++;
    cost += c;
    merge(a, b);
  }

  cout<<cost<<endl;

  return 0;
}
