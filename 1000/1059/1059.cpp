#include<iostream>
using namespace std;

int main(){
	int i, n, must;
	int a = 0, b = 1000;
	int lucky_set[50];

	cin >> n;
	for(i = 0; i < n; ++i)
		cin >> lucky_set[i];
	
	cin >> must;

	for(i = 0; i < n; ++i){
		int cur = lucky_set[i];
		if(cur == must){
			cout << 0 << endl;
			return 0;
		};
		if(a < cur && cur < must)
			a = cur;
		if(must < cur && cur < b)
			b = cur;
	}
	cout << (must-a)*(b-must)-1 << endl;

	return 0;
}
