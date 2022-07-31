#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

int N, M, num_h, num_s, dist[102][15];
int ans = (int)2e20;
vector<pii> house, store;

int count_bits(int bits){
	int n = 0;
	while(bits){
		n += bits % 2;
		bits /= 2;
	}

	return n;
}

void score(int bits){
	int s = 0;
	FOR(i, 0, num_h){
		int d = (int)20000;
		FOR(j, 0, num_s){
			if(bits & (1 << j)) d = min(d, dist[i][j]);
		}
		s += d;
		if(s >= ans) return;
	}

	ans = min(ans, s);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N>>M;

  FOR(i, 0, N) FOR(j, 0, N){
	  int t;
	  cin>>t;
	  switch(t){
		  case 1:
			  house.push_back(make_pair(i, j));
			  break;
		  case 2:
			  store.push_back(make_pair(i, j));
			  break;
	  }
  }

  num_h = house.size();
  num_s = store.size();

  FOR(i, 0, num_h) FOR(j, 0, num_s) {
	  pii h = house[i];
	  pii s = store[j];
	  dist[i][j] = abs(h.X-s.X)+abs(h.Y-s.Y);
  }

  FOR(i, 1, 1<<num_s){
	  if(count_bits(i) != M) continue;
	  score(i);
  }

  cout<<ans<<"\n";

  return 0;
}
