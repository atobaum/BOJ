#include<iostream>
// 1068: 트리

using namespace std;
int parents[50];
int visited[50];
int is_leaf[50];
int is_connected[50];

// return 0 if node is in orphan tree.
// never visit root recursively.
int visit(int node){
	int parent = parents[node];

	visited[node] = 1;
	is_leaf[parent] = 0;
	if(parent == -1){
		is_connected[node] = 1;
		return 1;
	}

	if(parent == -2){
		is_connected[node] = 0;
		return 0;
	}
	
	if(visited[parent] == 1)
		is_connected[node] = is_connected[parent];
	else
		is_connected[node] = visit(parent);

	return is_connected[node];
}

int main(){
	int n, temp;
	fill_n(parents, 50, -1);
	fill_n(visited, 50, 0);
	fill_n(is_leaf, 50, 1);
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> temp;
		parents[i] = temp;
	}
	cin >> temp;
	parents[temp] = -2;

	for(int i = 0; i < n; ++i){
		if(!visited[i]) visit(i);
	}

	int result = 0;
	for(int i = 0; i < n; ++i){
		result += (is_leaf[i] && is_connected[i]);
	}
	cout << result << endl;

	return 0;
}
