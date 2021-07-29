#include <iostream>
using namespace std;

int n;

struct Tree
{
	int x;
	int y;
	int cost;
};

Tree trees[40];

int solve(long mask)
{
	int count = 0;
	int money = 0;
	int minX = 1000000, maxX = 0, minY = 1000000, maxY = 0;

	for (int i = 0; i < n; ++i)
	{
		Tree tree = trees[i];
		if ((mask & (1 << i)) != 0)
		{
			minX = min(minX, tree.x);
			maxX = max(maxX, tree.x);
			minY = min(minY, tree.y);
			maxY = max(maxY, tree.y);
		}
		else
		{
			count++;
			money += tree.cost;
		}
	}

	if (minX == maxX || minY == maxY)
	{
		if ((maxX - minX) + (maxY - minY) <= money)
			return count;
		else
			return 1 << 30;
	}
	else
	{
		if (2 * ((maxX - minX) + (maxY - minY)) <= money)
			return count;
		else
			return 1 << 30;
	}
}

int main()
{
	int x, y, c, res = 40;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y >> c;
		trees[i].x = x;
		trees[i].y = y;
		trees[i].cost = c;
	}

	// 남길 것
	for (long mask = 0; mask < ((long)1 << n); ++mask)
	{
		res = min(res, solve(mask));
	}

	cout << res << endl;

	return 0;
}
