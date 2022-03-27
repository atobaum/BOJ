#include <bits/stdc++.h>
using namespace std;

int N, M;
const int CHARACTERS = 26;

int c2i(char c){
	return c - 'a';
}

class Trie {
	public:
		bool match;
		Trie *children[26];
};

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>N>>M;

  Trie* root = new Trie();

  for(int i=0;i<N;++i){
	  string s;
	  cin >> s;

	  s.length();
	  Trie* cur = root;

	  for(char c: s){
		int code = c2i(c);
		if(!cur->children[code]){
			cur->children[code] = new Trie();
		}
		cur = cur->children[code];
	  }

	  cur->match = true;
  }

  int res=0;

  for(int i=0;i<M;++i){
	  string s;
	  cin>>s;
	  
	  Trie* cur = root;
	  for(char c: s){
		int code = c2i(c);
		if(!cur->children[code]){
			cur = nullptr;
			break;
		}
		cur = cur->children[code];
	  }

	  if(cur && cur->match) ++res;
  }

  cout<<res<<"\n";

  return 0;
}
