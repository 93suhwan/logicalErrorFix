#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW { cout << "meowwwww" << '\n'; system("pause"); }
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

const int maxn = 1234567, mod = 1000000007;

#define fac_init() fact(maxn - 1, 1);
#define C(x,y) ((fact(x, 2) * fact(y, 3) % mod) * fact((x) - (y), 3) % mod)

int fact(int cur, int mode)
{
	static int f[maxn], g[maxn];
	if (mode == 1)
	{
		f[0] = 1;
		F1 (i, cur) f[i] = f[i - 1] * i % mod;
		g[cur] = 1;
		int a = f[cur], b = (mod - 2) << 1;
		while (b >>= 1)
		{
			if (b & 1) g[cur] = g[cur] * a % mod;
			a = a * a % mod;
		}
		for (int i = cur - 1; i >= 0; --i)
			g[i] = g[i + 1] * (i + 1) % mod;
		return 0;
	} else if (mode == 2) return f[cur];
	else return g[cur];
}

int t;
int a[maxn], b[maxn], ins[maxn];
int n;

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
}

void gao(int q, int p, int l, int r)
{
	//dbgg(mp(q, p));
	//dbg(mp(l, r));
	int m = (l + r) / 2;
	int cur = 0;
	int pos = 0;
	pii best = mp(cur, q);
	for (int i = q; i <= p; ++i)
	{
		if (b[m] < a[i]) ++cur;
		if (b[m] > a[i]) --cur;
		best = min(best, mp(cur, i + 1));
	}
	ins[m] = best.se;
	if (l < m) gao(q, min(ins[m], p), l, m - 1);
	if (m < r) gao(min(ins[m], p), p, m + 1, r);
}

vi in[maxn];

map<int, int> app;
int bit[maxn];

#define lowbit(x) (x & -x)

void add(int p, int v)
{
	while (p < maxn)
	{
		bit[p] += v;
		p += lowbit(p);
	}
}

int qry(int p)
{
	int ret = 0;
	while (p)
	{
		ret += bit[p];
		p -= lowbit(p);
	}
	return ret;
}

void solve()
{
	while (t --> 0)
	{
		int m; cin >> n >> m;
		F1 (i, n) cin >> a[i];
		F1 (i, m) cin >> b[i];
		app.clear();
		F1 (i, n) ++app[a[i]];
		F1 (i, m) ++app[b[i]];
		int cnt = 0;
		for (auto &x : app) x.se = ++cnt;
		F1 (i, n) a[i] = app[a[i]];
		F1 (i, m) b[i] = app[b[i]];  
		sort(b + 1, b + m + 1);
		gao(1, n, 1, m);
		F1 (i, n + 1) in[i].clear();
		//F1 (i, m) dbg(ins[i]);
		F1 (i, m) in[ins[i]].pb(i);
		vi v;
		F1 (i, n + 1)
		{
			for (auto x : in[i]) v.pb(b[x]);
			if (i != n + 1) v.pb(a[i]);
		}
		//dbg(v);
		int ans = 0;
		F (i, n + m) 
		{
			ans += i - qry(v[i]);
			add(v[i], 1);
		}
		F (i, n + m) add(v[i], -1);
		cout << ans << '\n';
	}
}

main()
{
	//fac_init();
	input();
	solve();
}
