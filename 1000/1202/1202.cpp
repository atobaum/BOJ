#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;


int main(){
	int N, K, M, V, C;
	vector<pair<int, int> > gems;
	vector<int> packs;

	cin >> N >> K;
	for(int i = 0; i < N; ++i){
		cin >> M >> V;
		gems.push_back(make_pair(V, M));
	}


	for(int i = 0; i < K; ++i){
		cin >> C;
		packs.push_back(C);
	}

	int result = 0;

	sort(gems.begin(), gems.end(), greater<pair<int, int> >());
	sort(packs.begin(), packs.end());

	for(int i = 0; i < N; ++i){
		pair<int, int> gem = gems[i];
		
		// lowerbound pack 찾기
		// binary search
		vector<int>::iterator low = packs.begin();
		vector<int>::iterator high = packs.end();

		for(vector<int>::iterator it = packs.begin(); it != packs.end(); it++){
			if(*it >= gem.second){
				result += gem.first;
				packs.erase(it);
				break;
			}
		}

		if(packs.empty()) break;
	}

	cout << result << endl;
	return 0;
}
