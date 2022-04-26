#include <bits/stdc++.h>
using namespace std;

typedef map<string, void*> node; 

void printIndent(int depth){
	for(;depth>0;--depth) cout<<"--";
}

void dfs(node root, int depth){
	for(auto iter: root){
		printIndent(depth);
		cout<<iter.first<<"\n";
		dfs(*(node*)iter.second, depth+1);
	}
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int N, K;

  node root;
  cin>>N;
  for(int i=0;i<N;++i){
	  cin>>K;
	  node *cur = &root;

	  for(int j=0;j<K;++j){
		  string s;
		  cin>>s;
		  if(!(*cur)[s]) {(*cur)[s] = new node;}
		  cur = (node*)(*cur)[s];
	  }
  }

  for(auto iter: root){
	cout<<iter.first<<"\n";
	dfs(*(node*)iter.second, 1);
  }

  return 0;
}
