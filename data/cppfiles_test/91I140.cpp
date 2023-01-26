#include <bits/stdc++.h>

typedef long long ll;

const int N = 100010, W = 1e9;

struct Node {
	int ls, rs, cnt;
} P[N * 100];
int top;

void change(int o, int k, int x) {
	int l = 1, r = W;
	while (l != r) {
		P[o].cnt += x;
		int mid = (l + r) >> 1;
		if (k <= mid) {
			if (!P[o].ls) P[o].ls = ++top;
			r = mid; o = P[o].ls;
		} else {
			if (!P[o].rs) P[o].rs = ++top;
			l = mid + 1; o = P[o].rs;
		}
	}
	P[o].cnt += x;
}
int locate(int o, int p, int q) {
	int l = 1, r = W;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (P[P[o].ls].cnt != P[P[p].ls].cnt + P[P[q].ls].cnt) {
			o = P[o].ls; p = P[p].ls; q = P[q].ls;
			r = mid;
		} else {
			o = P[o].rs; p = P[p].rs; q = P[q].rs;
			l = mid + 1;
		}
	}
	return l;
}

int rt[N];

std::set<std::tuple<int, int, int>> edges;
std::map<std::pair<int, int>, int> map;
std::multiset<ll> sums;
std::multiset<int> adj[N];

void adjust(int u, int sgn) {
	if (adj[u].size() >= 3) {
		ll val = 0; auto it = adj[u].begin();
		for (int rep = 0; rep != 3; ++rep) val += *it++;
		if (sgn == 1) sums.insert(val);
		else { sums.erase(sums.find(val)); }
	}
}

void insert(int u, int v, int w) {
	edges.insert(std::make_tuple(w, u, v));
	map.insert(std::make_pair(std::make_pair(u, v), w));
	adjust(u, -1); adjust(v, -1);
	adj[u].insert(w); adj[v].insert(w);
	adjust(u, 1); adjust(v, 1);
	change(rt[u], w, 1); change(rt[v], w, 1); change(rt[0], w, 1);
}
void erase(int u, int v) {
	auto it = map.find(std::make_pair(u, v));
	int w = it->second; map.erase(it);
	edges.erase(std::make_tuple(w, u, v));
	adjust(u, -1); adjust(v, -1);
	adj[u].erase(adj[u].find(w)); adj[v].erase(adj[v].find(w));
	adjust(u, 1); adjust(v, 1);
	change(rt[u], w, -1); change(rt[v], w, -1); change(rt[0], w, -1);
}
ll query() {
	ll ans = 0;
	if (!sums.empty()) ans = *sums.begin();
	int rep = 0;
	for (auto it = edges.begin(); rep != 4; ++it, ++rep) {
		int w, u, v; std::tie(w, u, v) = *it;
		change(rt[0], w, 1);
		if (P[rt[u]].cnt + P[rt[v]].cnt != P[rt[0]].cnt)
			ans = std::min(ans, (ll)w + locate(rt[0], rt[u], rt[v]));
		change(rt[0], w, -1);
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int n, m; std::cin >> n >> m;
	for (int i = 0; i <= n; ++i) rt[i] = ++top;
	while (m--) {
		int u, v, w; std::cin >> u >> v >> w;
		if (u > v) std::swap(u, v);
		insert(u, v, w);
	}
	std::cout << query() << '\n';
	int q; std::cin >> q;
	while (q--) {
		int opt, u, v; std::cin >> opt >> u >> v;
		if (u > v) std::swap(u, v);
		if (opt == 0) erase(u, v);
		else { int w; std::cin >> w; insert(u, v, w); }
		std::cout << query() << '\n';
	}

	return 0;
}
