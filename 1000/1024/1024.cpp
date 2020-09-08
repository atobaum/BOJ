#include<iostream>
using namespace std;

int main(){
	long N;
	int L;
	cin >> N >> L;

	for(int l = L; l <= 100; ++l){
		long numerator = ((2 * N) - l * (l-1));
		if(numerator < 0) break;
		if(numerator % (2 * l) == 0){
			long a = numerator / (2 * l);
			for(int i = 0; i < l; ++i){
				cout << a + i << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}
