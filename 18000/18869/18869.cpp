#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b){
	for(int i=0; i<a.size(); ++i){
		if(a[i] > b[i]) return true;
		else if(a[i] < b[i]) return false;
	}

	return false;
}

bool isEqual(vector<int> a, vector<int> b){
	for(int i=0; i<a.size(); ++i){
		if(a[i] != b[i]) return false;
	}

	return true;
}

int M, N, i, j, primes[10001]={2};
vector<int> planets[100];

bool isPrime(int n){
	if(n==2) return true;
	if(n%2==0) return false;

	for(int i=3;i*i<=n;i+=2){
		if(n%i==0) return false;
	}

	return true;
}

void fill_up_primes(){
	int i = 0, cur = 3;
	while(i < N){
		if(isPrime(cur)) primes[++i] = cur;
		cur += 2;
	}
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  map<int, int> mm;

  cin >> M >> N;
  fill_up_primes();

  for(i=0;i<M;++i) {
	  set<int> numbers;
	  map<int, int> m;
	  for(j=0; j<N; ++j) {
		int t;
		cin >> t;
		planets[i].push_back(t);
		numbers.insert(t);
	  }

	  vector<int> unique(numbers.begin(), numbers.end());
	  sort(unique.begin(), unique.end());

	  for(j=0; j<unique.size(); ++j){
		  m[unique[j]] = j;
	  }

	  for(j=0; j<N; ++j) {
		 planets[i][j] = m[planets[i][j]];
	  }
  }

  sort(planets, planets+M, compare);

  int ans=0;

  int t=1;
  for(i=0;i<M-1;++i){
	  if(isEqual(planets[i], planets[i+1])){
		t++;
	  }else{
		  ans += t * (t-1) / 2;
		  t=1;
	  }
  }
  ans += t * (t-1) / 2;
  cout<<ans<<"\n";

  return 0;
}
