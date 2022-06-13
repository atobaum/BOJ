#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)

#define rep(i, a, b) for (int i = a; i < b; i++)
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define out1(a) cout << a << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;

int N, i;
map<int, vector<pii> > pts;
vector<vector<double> > angles;

int gcd(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (b > a)
		swap(a, b);
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}

	return a;
}

pii normalize(pii p)
{
	int g = gcd(abs(p.first), abs(p.second));
	int flag = 1;
	if (p.first < 0 || (p.first == 0 && p.second < 0))
		flag = -1;

	return mp(flag * p.first / g, flag * p.second / g);
}


bool sort_pts(pii a, pii b)
{
	// on x-axis
	if (a.second == 0 && a.second == b.second)
		return a.first < b.first;

	// on the diffrerent hemisphere
	if (a.second * b.second < 0)
		return a.second > b.second;

	if (a.second > 0 || b.second > 0)
		return a.first > b.first;
	else
		return a.first < b.first;
}

int sq_norm(int a, int b){
	return a*a+b*b;
}

bool is_symmetric(vector<pii> &pts, pii p)
{
	vector<int> dist;
	map<int, int> dist_m;
	for (pii pp: pts) {
		// exclude itself and opposite point
		if(p.first*pp.second == p.second*pp.first) continue;

		int d = p.first * pp.first + p.second * pp.second;
		dist.push_back(d);

		dist_m[d]++;
	}

	if (dist.size() % 2 != 0) return false;

	sort(dist.begin(), dist.end());

	for(auto t: dist_m){
		assert(t.second > 0 && t.second <= 2);
	}

	for (int i = 0; i < dist.size(); i += 2) {
		if (dist[i] != dist[i + 1]) return false;
	}

	return true;
}

set<pii> find_symetries(vector<pii> &pts)
{
	set<pii> res;
	sort(pts.begin(), pts.end(), sort_pts);

	// points
	for (pii p : pts) {
		if(res.find(normalize(p)) != res.end()) continue;
		if (is_symmetric(pts, p)) res.insert(normalize(p));
	}

	for (int i = 0; i < pts.size(); ++i) {
		pii a = pts[i];
		pii b = pts[(i + 1) % pts.size()];

		pii p = mp(a.first + b.first, a.second + b.second);
		// use the perpendicular line whe the middle point is origin
		if (p.first == 0 && p.second == 0)
			p = mp(a.second, -a.first);
		if(res.find(normalize(p)) != res.end()) continue;
		if (is_symmetric(pts, p)) res.insert(normalize(p));
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	for (i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0)
			continue;
		pts[x * x + y * y].push_back(mp(x, y));
	}

	if (pts.size() == 0) {
		cout << -1 << "\n";
		return 0;
	}

	map<pii, int> m;

	for (auto t: pts)
	{
		for (auto p: find_symetries(t.second)) {
			m[p]++;
			out4("asdf", p.first, p.second, m[p]);
		}
	}

	int ans = 0;
	for (auto p: m) {
		if (p.second == pts.size()) ans++;
	}

	cout << ans << "\n";
	return 0;
}
