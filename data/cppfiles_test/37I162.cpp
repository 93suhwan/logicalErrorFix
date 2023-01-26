#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;
int add(int x, int y) { return x += y, x < mod ? x : x - mod; }
int sub(int x, int y) { return x -= y, x < 0 ? x + mod : x; }

void solve() {
	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int edge = 1; edge < n; ++edge) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> sz(n);
	auto dfs = [&sz, &g](const auto &self, int u, int p) -> void {
		sz[u] = 1;
		for (int v : g[u]) {
			if (v == p) continue;
			sz[u] += sz[v];
			self(self, v, u);
		}
	};
	dfs(dfs, 0, -1);

	vector<int> dp(n + 1);
	dp[1] = 1;
	for (int i = 1; i < n; ++i)
		dp[1] = add(dp[1], dp[1]);
	
	for (int d = 2; d < n; ++d) {
		if ((n - 1) % d)
			continue;
		dp[d] = 1;
		for (int u = 0; u < n; ++u)
			dp[d] &= sz[u] % d == 0 || sz[u] % d == 1;
	}

	auto f = dp;
	for (int d = n; d > 0; --d)
		for (int m = d + d; m < n; m += d)
			f[d] = sub(f[d], f[m]);
	for (int d = 1; d <= n; ++d)
		cout << f[d] << ' ';
	cout << '\n';
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--) solve();
}