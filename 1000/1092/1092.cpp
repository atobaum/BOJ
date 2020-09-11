#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool desc(int a, int b){
	return a > b;
}

int main(){
	int n, m, temp;
	vector<int> cranes, boxes;

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> temp;
		cranes.push_back(temp);
	}
	cin >> m;
	for(int i = 0; i < m; ++i){
		cin >> temp;
		boxes.push_back(temp);
	}
	sort(cranes.begin(), cranes.end(), desc);
	sort(boxes.begin(), boxes.end());

	int res = 0;

	while(!boxes.empty()){
		res++;
		int crane_idx = 0;
		int box_idx = boxes.size()-1;
		int moved = 0;

		for(; crane_idx < cranes.size(); ++crane_idx){
			int available_weight = cranes[crane_idx];

			for(; box_idx >= 0; --box_idx){
				if(boxes[box_idx] != -1 && boxes[box_idx] <= available_weight){
					moved = 1;
					boxes[box_idx] = -1;
					break;
				}
			}
		}

		if(moved == 0){
			cout << -1 << endl;
			return 0;
		}

		while(!boxes.empty() && boxes.back() == -1){
			boxes.pop_back();
		}
	}

	cout << res << endl;
	return 0;
}
