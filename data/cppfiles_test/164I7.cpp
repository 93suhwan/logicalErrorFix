#include <bits/stdc++.h>

const int N = 1e6 + 50;

inline lowbit(int x) {
	return x & -x;
}

struct fenwick_t {
	int t[N];
	fenwick_t() {
		memset(t, 0, sizeof t);
	}
	inline void add(int p, int v) {
		++p;
		for (; p < N; p += lowbit(p))
			t[p] += v;
	}
	inline void add(int l, int r, int v) {
		add(l, v);
		add(r + 1, -v);
	}
	inline int qry(int p) {
		++p;
		int r = 0;
		for (; p; p -= lowbit(p))
			r += t[p];
		return r;
	}
} T1, T2;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, k, tot = 0;
	std::cin >> n >> k;
	std::vector<int> l(n + 1), r(n + 1), t(n + 1), fa(n + 1), siz(n + 1), dfn(n + 1), dep(n + 1), a, ban(n + 1);
	std::string s;
	std::cin >> s;
	s = "#" + s;
	for (int i = 1; i <= n; ++i) {
		std::cin >> l[i] >> r[i];
	}
	std::function<void(int)> dfs = [&](int x) {
		siz[x] = 1;
		dfn[x] = ++tot;
		if (l[x]) {
			dep[l[x]] = dep[x] + 1;
			dfs(l[x]);
			fa[l[x]] = x;
			siz[x] += siz[l[x]];
		}
		a.push_back(x);
		if (r[x]) {
			dep[r[x]] = dep[x] + 1;
			dfs(r[x]);
			fa[r[x]] = x;
			siz[x] += siz[r[x]];
		}
	};
	dep[1] = 1;
	dfs(1);
	assert(a.size() == n);
	std::vector<int> b(n), lst(n), mp(50, n + 1);
	for (int i = 0; i < n; ++i) {
		b[i] = s[a[i]] - 'a';
	}
	for (int i = n - 1; i >= 0; --i) {
		mp[b[i]] = i;
		int minp = n + 1;
		for (int c = 0; c < 26; ++c)
			if (b[i] != c) {
				minp = std::min(minp, mp[c]);
			}
		if (minp == n + 1) {
			lst[i] = -1;
		}
		else {
			lst[i] = b[minp];
		}
	}
	int rem = k;
	for (int i = 0; i + 1 < n; ++i) {
		int x = i;
		if (ban[a[i]]) continue;
		if (b[i] < lst[i]) {
			// try to select!
			if (T2.qry(a[i]) == 0) {
				int xx = a[i];
				int cost = dep[xx] - T1.qry(xx);
				if (rem >= cost) {
					rem -= cost;
					int y = xx, total = 0;
					while (y && !ban[y]) {
						ban[y] = true;
						T1.add(dfn[y], dfn[y] + siz[y] - 1, 1);
						++total;
						y = fa[y];
					}
					assert(total == cost);
				}
			}
		}
		else if (!ban[a[i]]){
			T2.add(dfn[a[i]], dfn[a[i]] + siz[a[i]] - 1, 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		putchar('a' + b[i]);
		if (ban[a[i]]) {
			putchar('a' + b[i]);
		}
	}
}
