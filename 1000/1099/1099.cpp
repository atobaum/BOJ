#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int memo[50];
int minLen = 0;
string src;
vector<string> words;

int min(int a, int b){
	return a > b ? b : a;
}

int diffStr(string a, string b){
	int res = 0;
	string aa = a;
	string bb = b;
	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());

	if(aa != bb) return -1;
	for(int i = 0; i < a.length(); ++i){
		if(a[i] != b[i]) res++;
	}
	return res;
}

int solve(int i){
	if(i == -1) return 0;
	if(i < minLen) return -1;
	if(memo[i] != -2) return memo[i];

	int result = -1;

	for(string w: words){
		int temp = solve(i - w.length());
		if(temp == -1) continue;
		int diff = diffStr(w, src.substr(i - w.length() + 1, w.length()));
		if(diff == -1) continue;

		temp += diff;
		if(result == -1) result = temp;
		else result = min(result, temp);
	}

	memo[i] = result;
	return result;
}

int main(){
	fill_n(memo, 50, -2);

	string temp;
	int n;

	cin >> src;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> temp;
		minLen = min(minLen, temp.length());
		words.push_back(temp);
	}

	cout << solve(src.length() - 1) << endl;

	return 0;
}
