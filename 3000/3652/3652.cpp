#include <bits/stdc++.h>
using namespace std;

int a, b;
char t;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

void solve(int a, int b){
	int g = gcd(a, b);
	a /= g;
	b /= g;

	if(a==1 && b==1) return;

	if(a > b){
		cout<<"R";
		solve(b, a-b);
	} else{
		cout<<"L";
		solve(b-a, a);
	}
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>a>>t>>b;
  solve(a, b);

  return 0;
}
