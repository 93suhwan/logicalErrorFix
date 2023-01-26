#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int, int>

using namespace std;

int n, m;
vector<int> a, b;
vector<vector<int>> g;
vector<int> tag, vis, p;

pii tek;

int dfs(int v, int q, ll val) {
	if (val <= a[v]) return 0;
	p[v] = q;
	vis[v] = 1;
	for (auto e : g[v]) {
		if (e == q) continue;
		if (!vis[e]) {
			if (dfs(e, v, val + b[v])) return 1;
		} else {
			tek = {v, e};
			return 1;
		}
	}
	return 0;
}

int test(int s) {
	vis.assign(n, 0);
	tag.assign(n, 0);
	tag[0] = 1;
	p.assign(n, 0);

	while (1) {
		// dfs
		int f = 0;

		for (int i = 0; i < n; i++) vis[i] = tag[i];
		for (int i = 0; i < n; i++) {
			if (tag[i])
				for (auto e : g[i]) {
					if (!tag[e]) {
						if (dfs(e, i, s)) {
							f = 1;
							break;
						}
					}
				}
				if (f) break;
		}

		if (f) {
			// add
			for (int i = tek.first; !tag[i]; i = p[i]) tag[i] = 1, s += b[i];
			for (int i = tek.second; !tag[i]; i = p[i]) tag[i] = 1, s += b[i];
		} else {
			break;
		}

	}
	for (int i = 0; i < n; i++) if (!tag[i]) return 0;
	return 1;
}

void solve() {
	int l = 0, r = 1'000'000'000;
	cin >> n >> m;
	a.assign(n, 0);
	b.assign(n, 0);
	g.assign(m, vector<int>(0, 0));
	for (int i = 1; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	while (l <= r) {
		int m = (l + r) >> 1;
		if (test(m)) r = m - 1;
		else l = m + 1;
	}
	cout << l << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
