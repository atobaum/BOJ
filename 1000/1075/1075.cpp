#include<iostream>

using namespace std;

int main(){
	int n, f;

	cin >> n;
	cin >> f;

	n = n - n % 100;
	int result = f - (n % f);
	if (result == f)
		result = 0;

	if(result < 10)
		cout << "0";
	cout << result << endl;
	return 0;
}
