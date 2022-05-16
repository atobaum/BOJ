#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)

#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;

int n, m, ans = INT32_MAX, dist[501][501];
// true if left-top to right-bottom
int board[500][500];
deque<pii> d;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>n>>m;
  memset(dist, -1, sizeof(dist));

  for(int i=0;i<n;++i){
	  for(int j=0;j<m;++j){
		  char t;
		  cin>>t;
		  board[i][j] = t=='\\';
	  }
  }

  if((n-m)%2){
	  cout<<"NO SOLUTION\n";
	  return 0;
  }

  d.push_front(mp(0, 0));
  dist[0][0] = 0;

  while(!d.empty()){
	  pii front = d.front();
	  int x=front.first, y=front.second;
	  if(x==n&&y==m) {
		ans = dist[x][y];
		break;
	  }
	  d.pop_front();

	  for(int i=-1; i<=1; i+=2){
		  for(int j=-1; j<=1; j+=2){
			  if(x+i>=0 && x+i<=n && y+j>=0 && y+j<=m){
				  int w = board[x-(i==-1)][y-(j==-1)] != ((i*j)+1)/2;

				  if(dist[x][y]+w < dist[x+i][y+j] || dist[x+i][y+j]==-1){
					  dist[x+i][y+j] = dist[x][y]+w;
					  if(w)
						  d.push_back(mp(x+i, y+j));
					  else
						  d.push_front(mp(x+i, y+j));
				  }
			  }
		  }
	  }
  }
  
  if(ans==INT32_MAX) cout << "NO SOLUTION\n";
  else cout << ans << "\n";

  return 0;
}
