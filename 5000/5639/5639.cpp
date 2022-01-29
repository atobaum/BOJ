#include <iostream>
using namespace std;

class Node{
	public:
	int d;
	Node* l;
	Node* r;

	Node(int newd){
		d = newd;
		l = NULL;
		r = NULL;
	}
};

Node* root;

void insert(int d){
	Node* n = new Node(d);
	Node* cur = root;

	while(true){
		if(cur -> d < d) {
			if(cur -> r == NULL){
				cur -> r = n;
				return;
			} else {
				cur = cur -> r;
			}
		} else{
			if(cur -> l == NULL){
				cur -> l = n;
				return;
			} else {
				cur = cur -> l;
			}
		}
	}
}

void postorder(Node* cur){
	if(cur -> l){
		postorder(cur -> l);
	}
	if(cur -> r){
		postorder(cur -> r);
	}
	cout << cur -> d << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int temp;

  cin >> temp;

  root = new Node(temp);

  while(cin >> temp){
	insert(temp);
  }

  postorder(root);

  return 0;
}
