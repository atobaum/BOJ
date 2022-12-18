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

int N, Q, k;
int s = 100000, e = 100000, p[200001];
bool direction = true;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N>>Q>>k;

  FOR(i, 0, Q){
    int t, tt;
    cin>>t;
    switch(t){
      case 0:
        cin >> p[direction ? e : --s];
        if(direction) ++e;
        break;
      case 1:
        if(direction)
          sort(&p[s], &p[e], less<int>());
        else
          sort(&p[s], &p[e], greater<int>());
        break;
      case 2:
        direction = !direction;
        break;
    }
  }

  cout << p[direction ? e-k+1 : s+k-1];

  return 0;
}
