#include <algorithm> //sort
#include <iostream>
using namespace std;

#define reap(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a
#define out1(a) cout << a << endl;

int x, n, blocks[1000000];

void solve(){
	sort(blocks, blocks + n);
	int s = 0, e = n-1;
	
	while(s < e){
		int sum = blocks[s]+blocks[e];
		
		if(sum > x) --e;
		else if(sum < x) ++s;
		else {
			out1("yes "+to_string(blocks[s])+" "+to_string(blocks[e]));
			return;
		}
	}

	out1("danger");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(in1(x)){
		x *= 10000000;
		in1(n);
		reap(j, 0, n){
		  in1(blocks[j]);
		}

		solve();
	}

	return 0;
}
