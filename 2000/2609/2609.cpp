#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int gcd(int a, int b){
	if(a < b) swap(a, b);

	while(b != 0){
		a %= b;
		swap(a, b);
	}

	return a;
}

int main(){
	int a, b;
	cin >> a >> b;

	int g = gcd(a, b);

	cout << g << endl << (a * b / g) << endl;
	return 0;
}
