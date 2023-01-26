#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define debug(...) __VA_ARGS__
#define judge(...)
#else
#define endl '\n'
#define debug(...)
#define judge(...) __VA_ARGS__
#endif
#define debugf(...) debug(printf(__VA_ARGS__))

const int N = 1e5 + 5;
using ll = long long;
constexpr int mod = 998'244'353;
int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }

vector<int> g[N];

void clear(int n) {
	for (int i = 1; i <= n; i++)
		g[i].clear();
}

pair<bool, bool> dfs(int k, int u = 1, int p = 0) {
	int e = 0;
	bool hasAns = true;
	for (int v : g[u]) if (v != p) {
		auto [vHasAns, vTookParentEdge] = dfs(k, v, u);
		hasAns &= vHasAns;
		if (!vTookParentEdge) e++;
	}

	bool tookParentEdge = e % k == 1;
	if (e % k > 1 || (tookParentEdge && p == 0)) {
		hasAns = false;
	}

	return { hasAns, tookParentEdge };
}

int ans[N];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	ans[1] = 1;
	for (int i = 0; i < n-1; i++)
		ans[1] = add(ans[1], ans[1]);

	for (int k = 2; k <= n; k++) {
		ans[k] = (n-1) % k == 0 ? dfs(k).first : 0;
	}

	for (int k = n; k >= 1; k--) {
		for (int x = k+k; x <= n; x += k)
			ans[k] = add(ans[k], mod - ans[x]);
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;

	clear(n);
}

int (((((((main)))))))() {
	cin.tie(0)->sync_with_stdio(false);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}
