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

class Node{
  public:
  int cnt;
  int children_cnt;
  Node* children[26];

  ~Node(){
    FOR(i, 0, 26){
      if(children[i] != nullptr) delete children[i];
    }
  }

  void insert(string s, int idx){
    cnt++;
    if(idx+1 == s.length()){
      return;
    }

    int c = s[idx] - 'a';

    if(children[c] == nullptr) {
      children_cnt++;
      children[c] = new Node;
    }

    children[c]->insert(s, idx+1);
  }
};

int sum(Node* n){
  if(n == nullptr) return 0;

  int c = 0;
  if(n->children_cnt == 0) return 0;
  if(n->children_cnt > 1) c += n->cnt;
  
  FOR(i, 0, 26) c += sum(n->children[i]);

  return c;
}

void solve(int n){
  Node *trie = new Node;

  FOR(i, 0, n){
    string s;
    cin >> s;
    trie->insert(s, 0);
  }

  int ans = sum(trie);
  printf("%.2f\n", (double)(ans+n) / n);

  delete trie;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n;
  while(cin>>n) solve(n);

  return 0;
}
