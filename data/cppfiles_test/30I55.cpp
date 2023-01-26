#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2,avx")


typedef long long ll;
typedef long double ld;

using namespace std;
using namespace __gnu_pbds;

// #define int ll
#define pii pair<int, int>
#define f first
#define s second
#define vi vector<int>
#define vp vector<pii>
#define pb push_back
mt19937 rnd(time(0));

const int mod = 1e9 + 7;

int fastpow(int a, int b) {
	if (b == 0)
		return 1;
	if (b & 1)
		return fastpow(a, b - 1) * a % mod;
	int t = fastpow(a, b / 2);
	return t * t % mod;
}

const int maxn = 150000 + 50;
int p[maxn];
int s[maxn];

int get(int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}

int merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b) {
		if (s[a] > s[b])
			swap(a, b);
		s[b] += s[a];
		p[a] = b;
		return 1;
	}
	return 0;
}

const int maxa = 1e6 + 50;
vector<int> dels[maxa];

vector<int> dels2[maxn];
int ok_comp[maxn];

int cc[maxa];

void solve() {
	memset(cc, -1, sizeof(cc));
	int n, q;
	cin >> n >> q;
	iota(p, p + n, 0);
	fill(s, s + n, 1);
	int a[n];
	for (auto &i : a)
		cin >> i;
	map<int, vector<int>> mp;
	for (int i = 0; i < n; ++i) {
		for (auto &j : dels[a[i]])
			mp[j].pb(i);
	}
	for (auto &i : mp) {
		for (int j = 0; j < int(i.s.size()) - 1; ++j) {
			merge(i.s[j], i.s[j + 1]);
		}
	}
	for (int i = 0; i < n; ++i) {
		int v = get(i);
		for (auto &j : dels[a[i]]) {
			ok_comp[v] |= j == 2;
			cc[j] = v;
		}
		for (auto &j : dels[a[i] + 1]) {
			dels2[v].pb(j);
		}
	}
	vector<pair<pii, int>> qs[n];
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		a = get(a);
		b = get(b);
		qs[a].pb({{a, b}, i});
		qs[b].pb({{b, a}, i});
	}
	int used[n];
	memset(used, 0, sizeof(used));
	int ans[q];
	fill(ans, ans + q, 2);
	int ff[n];
	fill(ff, ff + n, 0);
	for (int i = 0; i < n; ++i) {
		int v = get(i);
		if (used[v])
			continue;
		used[v] = 1;
		bool ok = ok_comp[v];
		for (auto &j : dels2[v]) {
			if (cc[j] != -1)
				ff[cc[j]] = 1;
		}
		for (auto &j : qs[v]) {
			if (j.f.s == v) {
				ans[j.s] = 0;
			} else if (ff[j.f.s] || ok) {
				ans[j.s] = min(ans[j.s], 1);
			}
		}
		for (auto &j : dels2[v]) {
			if (cc[j] != -1)
				ff[cc[j]] = 0;
		}
	}

	for (auto &i : ans)
		cout << i << '\n';

}

signed main() {
	for (int i = 2; i < maxa; ++i) {
		if (dels[i].size() == 0)
		for (int j = i; j < maxa; j += i) {
			dels[j].pb(i);
		}
	}

	// freopen("tests/26", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}