#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long

using namespace std;

void read(int &ret)
{
	ret = 0;
	char ch = getchar(), flag = 0;
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-')
		flag = 1, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = ret * 10 + ch - '0', ch = getchar();
	if (flag)
		ret = -ret;
}

const int N = 200005, Log = 20;
int T, n;
int st[N][Log], a[N];

int gcd(int x, int y)
{
	return __gcd(x, y);
	if (x == 0 || y == 0)
		return x + y;
	int r = x % y;
	while (r)
		x = y, y = r, r = x % y;
	return y;
}

void prework()
{
	for (int i = 1; i <= n; i++)
		st[i][0] = abs(a[i] - a[i - 1]);
	for (int j = 1; j < Log; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
	int tmp = log2(r - l + 1);
	return gcd(st[l][tmp], st[r - (1 << tmp) + 1][tmp]);
}

signed main()
{
	cin >> T;
	while (T--)
	{
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		prework();
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int l = i, r = n, res = i - 1;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (query(i + 1, mid) > 1)
					res = mid, l = mid + 1;
				else
					r = mid - 1;
			}
			ans = max(ans, res - i + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
