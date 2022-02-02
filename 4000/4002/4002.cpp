#include <bits/stdc++.h>
using namespace std;

int N, M, level[100001], pay[100001];
vector<int> tree[100001];
long long res = 0;

pair<int, priority_queue<int> *> dfs(int root){
	int c = pay[root];
	auto q = new priority_queue<int>();
	q->push(pay[root]);

	for(auto b: tree[root]){
		auto temp = dfs(b);
		c += temp.first;
		auto bq = temp.second;
		if(bq->size() > q->size()) swap(bq, q);

		while(!bq->empty()){
			q->push(bq->top());
			bq->pop();
		}
		delete bq;

		while(c > M){
			c -= q->top();
			q->pop();
		}
	}

	long long new_res = (long long)level[root] * q->size();
	res = max(res, new_res);

	return make_pair(c, q);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin>>N>>M;
  for(int i=1;i<=N;++i){
	  int b;
	  cin >> b >> pay[i] >> level[i];

	  tree[b].push_back(i);
  }

  delete dfs(1).second;

  cout << res;

  return 0;
}
