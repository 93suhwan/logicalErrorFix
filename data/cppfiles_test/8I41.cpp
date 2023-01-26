#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mx = 1e5 + 5;
vector<int> g[mx];
int val[mx], st[mx], en[mx], sv = 1;
int n;


struct bit {
	const static int mx = 1e5 + 5 * 2;
	int v[mx];
	void update(int pos, int val) {
		for (; pos < mx; pos += pos & (-pos))v[pos] += val;
	}
	int query(int pos) {
		int sum = 0;
		for (; pos > 0; pos -= pos & (-pos))sum += v[pos];
		return sum;
	}
	void clear() {memset(v, 0, sizeof v);}
} stt;


void dfs(int u, int par) {
	stt.update(st[u] = sv++, val[u]);
	for (auto x : g[u]) {
		if (x != par) {
			dfs(x, u);
		}
	} stt.update(en[u] = sv++, -val[u]);
}



struct sptable {
	static const int maxn = 30002;
	static const int K = log2(maxn) + 1;
	int tmin[maxn][K];//0 based indexing
	int lg[maxn + 1], is_calc = 0;
	void init(int *A, int n) {
		if (!is_calc) {
			is_calc = 1;
			lg[1] = 0;
			for (int i = 2; i <= maxn; ++i) lg[i] = lg[i / 2] + 1;
		}
		for (int i = 0; i < n; ++i) tmin[i][0] = A[i];
		for (int j = 1; j <= K; ++j) {
			for (int i = 0; i + (1 << j) <= n; ++i) {
				tmin[i][j] = min(tmin[i][j - 1], tmin[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	inline int rmin(int L, int R) {
		int j = lg[R - L + 1];
		return min(tmin[L][j], tmin[R - (1 << j) + 1][j]);
	}
} sp;
struct lca {
	static const int maxn = 30002;
	int time[maxn], path[maxn], ret[maxn], T = 0;
	int dis[maxn]; // distance
	void dfs(int v, int p) {
		dis[v] = (~p) ? dis[p] + 1 : 0;
		time[v] = T, path[time[v]] = v, ret[T++] = (~p) ? time[p] : 0;
		for (int x : g[v]) if (x != p) {
				dfs(x, v);
			}
	}
	void init(int _r = 1) { //set root
		T = 0;
		dfs(_r, -1);
		sp.init(ret, T);
	}
	inline int get(int u, int v) {
		if (u == v)return u;
		tie(u, v) = minmax(time[u], time[v]);
		return path[sp.rmin(u + 1, v)];
	}
	inline int distance(int u, int v) {
		return dis[u] + dis[v] - 2 * dis[get(u, v)];
	}
} lca;

int fun(int v) {
	return stt.query(st[v]);
}
int fun(int u, int v) {
	int l = lca.get(u, v);
	return fun(v) + fun(u) - 2 * fun(l) + val[l];
}




signed main() {
	int t = 1, tc = 1; while (t--) {
		int m;
		cin >> n >> m;
		sv = 1;
		stt.clear();
		for (int i = 1; i <= n; i++) {
			cin >> val[i];
			val[i] = abs(val[i]);
			g[i].clear();
		}
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		lca.init();
		dfs(1, -1);
		while (m--) {
			int ty, l, r; cin >> ty >> l >> r;
			if (ty == 1) {
				r = abs(r);
				l++;
				stt.update(st[l], -val[l] + r);
				stt.update(en[l], val[l] - r);
				val[l] = r;
			} else {
				cout << 2LL * fun(l, r) - val[l] - val[r] << '\n';
			}
		}
	}
	return 0;
}