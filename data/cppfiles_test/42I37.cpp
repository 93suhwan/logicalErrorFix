#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <random>

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
#define all(v) v.begin(), v.end()
#define ld long double
#define ull unsigned long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
using namespace __gnu_pbds; 
typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

void file()
{
    freopen("fragmentation.in","r",stdin);
    freopen("fragmentation.out","w",stdout);
}

const int maxn=1e6+10,LOG=13,mod=998244353;
ll block = 300, timer = 0;
const ld eps = 1e-9;

#define bt(i) (1 << (i))
#define int ll
const int inf = 1e9;
#define y1 yy
#define pii pair <int, int>

int n, dp[400100], l[200100], r[200100], q, pos[400100], t[1601000];
vector <pii> vec;
map <int, int> have;

void upd(int v, int tl, int tr, int p, int val)
{
	if(p < tl || tr < p) return;
	if(p == tl && tr == tl)
	{
		t[v] = val;
		return;
	}
	upd(v * 2, tl, (tl + tr) / 2, p, val);
	upd(v * 2 + 1, (tl + tr) / 2 + 1, tr, p, val);
	t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
}

int sum(int v, int tl, int tr, int l, int r)
{
	if(l <= tl && tr <= r) return t[v];
	if(l > tr || r < tl) return 0;
	return (sum(v * 2, tl, (tl + tr) / 2, l, r) + sum(v * 2 + 1, (tl + tr) / 2 + 1, tr, l, r)) % mod;
}

int solve(int L, int R)
{
	if(L > R) return 0;
	int ret = 0;
	int Rb = 0;
	forn(L, i, R)
	{
		if(vec[i].s > 0 && have.count(vec[i].s)) Rb = i;
	}
	if(Rb == 0) return 0;
	int to = pos[l[vec[Rb].s]];
	forn(Rb + 1, i, R)
	{
		if(vec[i].s > 0)
		{
//			cout << "CLEAR " << pos[l[vec[i].s]] << endl;
			dp[pos[l[vec[i].s]]] = 0;
		}
	}
//	cout << "PLUS ";
	forn(L, i, to)
	{
		if(vec[i].s < 0)
		{
//			cout << dp[i] << " " << i << endl;
			ret = (ret + dp[i]) % mod;
		}
		if(have.count(-vec[i].s))
			have.erase(-vec[i].s);
	}
//	cout << endl;
//	cout << L << " " << R << " " << ret << " " << to << " " << Rb << endl;
	ret = (ret + solve(to + 1, Rb - 1)) % mod;
	return ret;
}

main()
{
	IOS
	cin >> n;
	vec.pb({-inf, -inf});
	forn(1, i, n)
	{
		cin >> l[i] >> r[i];
		vec.pb({l[i], -i});
		vec.pb({r[i], i});
	}
	sort(all(vec));
	n *= 2;
	forn(1, i, n) pos[vec[i].f] = i;
	forn(1, i, n)
	{
		if(vec[i].s > 0)
		{
			int to = pos[l[vec[i].s]];
			dp[to] = (sum(1, 1, n, to, i) + 1) % mod;
//			cout << "CALC " << to << " " << i << " " << dp[to] << endl;
			upd(1, 1, n, to, dp[to]);
		}
	}
	cin >> q;
	forn(1, i, q)
	{
		int num;
		cin >> num;
		have[num] = 1;
	}
//	cout << "START SOLVE " << 1 << " " << n << endl;
	cout << solve(1, n);
}