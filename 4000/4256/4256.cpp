#include <bits/stdc++.h>
using namespace std;

int T, n, preorder[1005], inorder[1005], visited[1005];
int pre_idx, in_idx;

void go(){
	if(pre_idx >= n) return;
	int r = preorder[pre_idx++];
	visited[r] = 1;

	if(inorder[in_idx] != r) go();
	in_idx++;
	if(!visited[inorder[in_idx]]) go();

	cout << r << " ";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin >> T;

  for(int i=0;i<T;++i){
	  cin >> n;
	  pre_idx = 0;
	  in_idx = 0;
	  memset(preorder, 0, sizeof(preorder));
	  memset(visited, 0, sizeof(visited));
	  for(int j=0;j<n;++j) cin >> preorder[j];
	  for(int j=0;j<n;++j) cin >> inorder[j];

	  go();
	  cout << endl;
  }

  return 0;
}
