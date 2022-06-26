#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)

#define X first
#define Y second

int i, n, k;
vector<pii> field;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>n>>k;
  for(i=0;i<n;++i){
	  int a, b;
	  cin>>a>>b;
	  field.push_back(mp(b, a));
  }

  sort(field.begin(), field.end());

  ll cur=field[0].Y, ans=cur;
  auto s=field.begin(), e=field.begin(); // both inclusive

  while(s != field.end()){
	  if(e->X - s->X > 2*k){
		  cur -= s->Y;
		  s++;
	  } else if(e != field.end()){
		  e++;
		  cur += e->Y;
	  } else break;

	  if(e->X - s->X <= 2*k) ans = max(ans, cur);
  }

  cout<<ans<<"\n";
  return 0;
}
