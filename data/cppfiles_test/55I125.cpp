#include <bits/stdc++.h>
#include <random> 
#include <chrono>
#define INF (ll)(2e16)
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

using namespace std;
using ll = long long;
using cd = complex<double>;
using ul = unsigned long;

void f_io () { ios_base :: sync_with_stdio (false); cin.tie (nullptr);
 cout.tie (nullptr);
}

const ll MAX = 3e5 + 15;
ll gc (ll a, ll b) {
	if (!a || !b) {
		return max (a, b);
	}
	ll r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

const ll MOD = 1e9 + 7;

inline ll mult (ll a, ll b) {
	return ((a % MOD)  * 1LL * (b % MOD)) % MOD;
}

inline ll add (ll a, ll b) {
	b = (b % MOD + MOD) % MOD;
	return (a + b) % MOD;
}

ll pw (ll a, ll b) {
	if (b < 0) {
		return 1;
	}
	ll r = 1;
	while (b) {
		if (b & 1) {
			r = mult (a, r);
		}
		b >>= 1;
		a = mult (a, a);
	}
	return r;
}

ll f[MAX];

ll nck (ll n, ll k) {
	if (n < 0 || k < 0 || k > n) {
		return 0;
	}
	return mult (f[n], pw (mult (f[n - k], f[k]), MOD - 2));
}

pair<int, int> comb (pair<int, int> p1, pair<int, int> p2) {
	return p2;
}

pair<int, int> seg[MAX * 4], laz[MAX * 4];

void push (int ind) {
	if (laz[ind].ft) {
		int x = ind << 1 | 1, y = ind << 1;
		laz[x] =  comb (laz[x], laz [ind]);
		laz[y] = comb (laz[y], laz[ind]);
		seg[x] = comb (seg[x], laz[ind]);
		seg[y] = comb (seg[y], laz[ind]);
		laz[ind] = {0, 0};
	}
}

void rup (int ind, int l, int r, int st, int en, pair<int, int> v) {
	if (en < l || r < st) {
		return;
	}
	if (st <= l && en >= r) {
		seg[ind] = comb (seg[ind], v);
		laz[ind] = comb (laz[ind], v);
		return ;
	}
	push (ind);
	int m = (l + r) >> 1, x = (ind << 1), y = (ind << 1 | 1);
	rup (x, l, m, st, en, v);
	rup (y, m + 1, r, st, en , v);
	seg[ind] = max (seg[x], seg[y]);
}

pair<int, int> qur (int ind, int l, int r, int st, int en) {
	if (en < l || r < st) {
		return {0, 0};
	}
	if (l >= st && en >= r) {
		return seg[ind];
	}
	push (ind);
	int m = (l + r) >> 1, x = (ind << 1), y = (ind << 1 | 1);
	return max (qur (x, l, m, st, en), qur (y, m + 1, r, st, en));
}

pair<int, int> ans[MAX];

int main () {
	f_io ();
	int n, m;
	cin >> n >> m;
	set<int> se;
	vector<pair<int, pair<int, int>>> vp (m);
	for (int i = 0; i < m; i++) {
		cin >> vp[i].ft >> vp[i].sd.ft >> vp[i].sd.sd;
		se.insert (vp[i].sd.ft);
		se.insert (vp[i].sd.sd);
	}
	map<int, int> ma;
	int cc = 0;
	for (int x : se) {
		ma[x] = ++cc;
	}
	sort (vp.begin (), vp.end ());
	int ind = 0, lim = 0;
	vector<pair<int, int>> vv [n + 1];
	for (int i = 0; i < m; i++) {
		int l = ma[vp[i].sd.ft], r = ma[vp[i].sd.sd];
		vv[vp[i].ft].pb (mp (l, r));
	}
	pair<int, int> fi = {};
	for (int i = 1; i <= n; i++) {
		if (vv[i].size () == 0) {
			continue;
		}
		sort (vv[i].begin (), vv[i].end ());
		int st = 0;
		vector<pair<int ,int>> so;
		for (auto x : vv[i]) {
			int l = x.ft, r = x.sd;
			l = max (st + 1, l);
			if (l > r) {
			 	break;
			}
			so.pb (mp (l, r));
			st = max (l, r);
			ans[i] = max (ans[i], qur (1, 1, cc, l, r));
		}
		ans[i].ft++;
		for (auto x : so) {
			rup (1, 1, cc, x.ft, x.sd, mp (ans[i].ft, i));
		}
		fi = max (fi, mp (ans[i].ft, i));
	}
	bool ch[n + 1] = {};
	while (fi.sd) {
		ch[fi.sd] = 1;
		fi.sd = ans[fi.sd].sd;
	}
	cout << n - fi.ft << "\n";
	for (int i = 1; i <= n; i++) {
		if (ch[i] == 0) {
			cout << i << " ";
		}
	}
	cout << "\n";
}
