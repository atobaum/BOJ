#include <iostream>
using namespace std;

#define in1(a) cin >> a;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl;

int inverse(int n, int m){
        int r0 = n, r1 = m;
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

        return ((s0 % m) + m) % m;
}

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int solve(int M, int N, int x, int y){
	int inv_n, inv_m;
	int d = gcd(M, N);

	if((x - y) % d != 0) return -1;

	int residue = x % d;
	x /= d;
	y /= d;
	M /= d;
	N /= d;
	int mod = M * N;

	long long res = (((((long long)x * N * inverse(N, M)) + ((long long)y * M * inverse(M, N))) % mod + mod) % mod) * d + residue;

	if(res) return res;
	else return mod * d;
}

int main() {
	int T, M, N, x, y;
	in1(T);

	for(int i = 0; i < T; ++i){
		in4(M, N, x, y);
		out1(solve(M, N, x, y));
	}

  return 0;
}
