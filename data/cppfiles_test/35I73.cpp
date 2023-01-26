#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int m, t[N << 2], add[N << 2];
int n, a[N], lp[N], r[N];
vpii pos[N], gg[N];
char s[N];

void precalc() {
	for (int x = 2; x < N; ++x)
		if (!lp[x])
			for (int y = x; y < N; y += x) 
				lp[y] = x;
}

void build(int v = 1, int tl = 0, int tr = m - 1) {
	t[v] = add[v] = 0;
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

inline void push(int v) {
	if (add[v]) {
		t[v << 1] += add[v];
		t[v << 1 | 1] += add[v];

		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		add[v] = 0;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 0, int tr = m - 1) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		add[v] += x;
		return;
	}

	push(v);

	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get(int v = 1, int tl = 0, int tr = m - 1) {
	if (tl == tr)
		return tl;

	int tm = (tl + tr) >> 1;
	if (t[v << 1] < 0)
		return get(v << 1, tl, tm);

	return get(v << 1 | 1, tm + 1, tr);

}
 
main () {
	precalc();

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]); 
		while (a[i] > 1) {
			int x = lp[a[i]], p = 0;
			while (!(a[i] % x)) {
				a[i] /= x;
				p++;
			}

			pos[x].pb({i, p});
		}
	}
	
	scanf("\n%s", (s + 1));
	multiset < int > q;
	q.insert(n + 1);

	for (int x = 1; x < N; ++x) {
		if (!sz(pos[x]))
			continue;

		m = sz(pos[x]);
		build();

		for (int j = 0; j < sz(pos[x]); ++j) 
			update(j, sz(pos[x]) - 1, s[pos[x][j].f] == '/' ? -pos[x][j].s : pos[x][j].s);

		int cur = n + 1;
		if (t[1] < 0)
			cur = pos[x][get()].f;

		r[x] = cur;
		q.insert(r[x]);
		
		for (int j = 0; j < sz(pos[x]); ++j) {
			int i = pos[x][j].f, p = pos[x][j].s;
			update(j, sz(pos[x]) - 1, s[i] == '/' ? p : -p);

			int cur = n + 1;
			if (t[1] < 0)
				cur = pos[x][get()].f;

			gg[i].pb({x, cur});
		}
	}


	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += *q.begin() - i;
		for (auto j : gg[i]) {
			q.erase(q.find(r[j.f]));
			r[j.f] = j.s;
			q.insert(r[j.f]);
		}
	}

	printf("%lld\n", ans);
}