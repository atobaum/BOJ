#include <iostream>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define out1(a) cout << a << endl;

int N, M, parent[201];

void merge(int i, int j);
int find(int i);

int main() {
  int a;

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  reap(i, 1, 201){
	  parent[i] = i;
  }

  in2(N, M);

  reap(i, 1, N+1){
	reap(j, 1, N+1){
		in1(a);
		if(a == 1)
			merge(i, j);
	}
  }

  in1(a);
  int root = find(a);
  reap(i, 1, M){
	  in1(a);
	  if(find(a) != root){
		out1("NO")
		return 0;
	  }
  }

  out1("YES")
  return 0;
}

void merge(int i, int j){
	int a = find(i);
	int b = find(j);
	if(a != b) parent[a] = b;
}

int find(int i){
	if(parent[i] == i) return i;
	return parent[i] = find(parent[i]);
}
