#include<iostream>
using namespace std;

#define in2(a, b) cin >> a >> b;
#define out1(a) cout << a << endl;

int inverse(int n){
	int r0 = 10007, r1 = n;
	int s0 = 1, t0 = 0, s1 = 0, t1 = 1;
	int temp, q0;

	while(r1 != 0){
		q0 = r0 / r1;
		temp = r0;
		r0 = r1;
		r1 = temp - r1 * q0;

		temp = s0;
		s0 = s1;
		s1 = temp - s0 * q0;

		temp = t0;
		t0 = t1;
		t1 = temp - t0 * q0;
	}

	return (t0 + 10007) % 10007;
}

int combication(int n, int k){
	int numerator = 1;
	int denominator = 1;

	for(int i = n; i > k; --i){
		numerator = (numerator * i) % 10007;
	}

	for(int i = n - k; i > 0; --i){
		denominator = (denominator * i) % 10007;
	}

	int inv = inverse(denominator);

	 return (numerator * inverse(denominator)) % 10007;
}

int main() {
	int n, k;
	in2(n, k);

	out1(combication(n, k));

  return 0;
}
