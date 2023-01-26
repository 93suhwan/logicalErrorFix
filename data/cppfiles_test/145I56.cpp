# include <bits/stdc++.h>
using namespace std;
# define int long long 
const int N = 2e5 + 10;
struct P
{
	int x,y,t,id;
}p[N];
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;cin >> T;
	for(int TT = 1; TT <= T ;TT++)
	{
		int n,k;cin >> n >> k;
		int t[n + 1];
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i].x >> p[i].y>> p[i].t;
			p[i].id = i;
		}
		int d[n + 1];
		function<int(int)> find = [&](int x)
		{return x == d[x] ? x : d[x] = find(d[x]);};

		sort(p + 1,p + n + 1,[](P a,P b)
		{
			if(a.x != b.x)return a.x < b.x;
			return a.y < b.y;
		});
		for(int i = 1; i <= n; i++)t[i] = p[i].t;
		for(int i = 1; i <= n; i++)d[i] = i;

		for(int i = 1; i < n; i++)
			if(p[i].x == p[i + 1].x && abs(p[i].y - p[i + 1].y) <= k)
			{
				int fa = find(p[i].id), fb = find(p[i + 1].id);
				if(fa != fb)
				{
					d[fa] = fb;
					t[fb] = min(t[fb],min(p[i].t,p[i + 1].t));
				}
			}
		sort(p + 1,p + n + 1,[](P a,P b)
		{
			if(a.y != b.y)return a.y < b.y;
			return a.x < b.x;
		});
		for(int i = 1; i < n; i++)
			if(p[i].y == p[i + 1].y && abs(p[i].x - p[i + 1].x) <= k)
			{
				int fa = find(p[i].id), fb = find(p[i + 1].id);
				if(fa != fb)
				{
					d[fa] = fb;
					t[fb] = min(t[fb],min(p[i].t,p[i + 1].t));
				}
			}
		int m = 0;
		int b[n + 1];
		bool stf[n + 1] = {false};
		for(int i = 1; i <= n; i++)
		{
			int f = find(p[i].id); 
			if(!stf[f])
			{
				stf[f] = true;
				b[++m] = t[f];
			}
		}
		sort(b + 1,b + m + 1);
		int res = m - 1;
		for(int i = 1; i < m; i++)
			res = min(res,max(b[i],m - 1 -i));
		if(TT == 11)
		{
			cout <<'\n';
			for(int i =1; i <= m; i++)cout << b[i] <<' ';
			cout << '\n';
		}
		cout << res << '\n';
	}
	
}