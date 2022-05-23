#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, int> pli;
#define mp(a, b) make_pair(a, b);

int i, n, arr[100001];
// sum, min_idx
pli seg[4 * 100001];

int get_min_idx(int a, int b){
	if(a==-1) return b;
	if(b==-1) return a;
	return arr[a] > arr[b] ? b : a;
}

pli init(int s, int e, int idx)
{
	if (s == e)
	{
		seg[idx] = mp(arr[s], s);
		return seg[idx];
	}
	int m = (s + e) / 2;

	pli a = init(s, m, idx * 2);
	pli b = init(m + 1, e, idx * 2 + 1);

	seg[idx] = mp(a.first + b.first, get_min_idx(a.second, b.second));
	return seg[idx];
}

pli score(int s, int e, int l, int r, int idx)
{
	if (l > e || r < s)
		return mp(0, -1);

	if (l <= s && e <= r)
		return seg[idx];

	int m = (s + e) / 2;
	pli a = score(s, m, l, r, idx * 2);
	pli b = score(m + 1, e, l, r, idx * 2 + 1);

	return mp(a.first + b.first, get_min_idx(a.second, b.second));
}

ll calc(int s, int e){
	if(s>e) return 0;
	if(s==e) return ((ll)arr[s])*arr[s];

	pli a = score(0, n-1, s, e, 1);
	ll t = a.first * arr[a.second];

	t = max(t, calc(s, a.second-1));
	t = max(t, calc(a.second+1, e));

	return t;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	init(0, n - 1, 1);

	cout << calc(0, n-1) << "\n";

	return 0;
}
