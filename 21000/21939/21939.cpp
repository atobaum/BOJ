#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

int N, M, level[100001];

priority_queue<pii> q_max, q_min;

void push(int n, int l){
    q_max.push(mp(l, n));
    q_min.push(mp(-l, -n));
    level[n] = l;
}

int get(priority_queue<pii> &q){
    while(q.top().X > 0 ? (level[q.top().Y] != q.top().X) : (level[-q.top().Y] != -q.top().X)) q.pop();

    return abs(q.top().Y);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N;

  FOR(i, 0, N){
      int p, l;
      cin>>p>>l;
      push(p, l);
  }

  cin>>M;
  FOR(i, 0, M){
      string op;
      cin>>op;

      if(op.compare("add") == 0) {
          int p, l;
          cin>>p>>l;
          push(p, l);
      }else if(op.compare("recommend") == 0){
          int x;
          cin>>x;
          if(x==1) cout<<get(q_max)<<"\n";
          else cout<<get(q_min)<<"\n";
      }else{
          int p;
          cin>>p;
          level[p] = 0;
      }
  }

  return 0;
}

