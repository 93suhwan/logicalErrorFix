#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
#define pb push_back
#define mpp make_pair
#define all(x) 	(x).begin(), (x).end()

using namespace std;
using namespace __gnu_pbds;
template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int iinf = 1e9;
const ll inf = 1e18 + 1337;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const int N = 105;
const int md = 1e9 + 7;
inline int add(int a, int b) {
	int res = a + b;
	if (res >= md) res -= md;
	return res;
}
inline int mul(int a, int b) {
	return (ll)a * b % md;
}

int f[N], ff[N], iv[N];
inline void calc() {
	iv[0] = iv[1] = 1;
	for (int i = 2; i < N; ++i) {
		iv[i] = mul(iv[md % i], md - md / i);
		assert(mul(i, iv[i]) == 1);
	}
	f[1] = ff[1] = 1;
	f[0] = ff[0] = 1;
	for (int i = 2; i < N; ++i) {
		f[i] = mul(f[i - 1], i);
		ff[i] = mul(ff[i - 1], iv[i]);
	}
}

inline int c(int n, int k) {
	if (k > n) return 0;
	if (!n && k) return 0;
	return mul(f[n], mul(ff[k], ff[n - k]));
}

inline void solve() {
	int n, k;
	cin >> n >> k;
	vector < vector <int> > gr(n + 1);

	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		gr[v].pb(u), gr[u].pb(v);
	}

	queue <int> q;
	vector < vector <int> > d(n + 1, vector <int> (n + 1, -1)),
				cnt(n + 1, vector <int> (n + 1, 0));
	for (int i = 1; i <= n; ++i) {
		q.push(i); d[i][i] = 0;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto to : gr[v]) {
				if (d[i][to] == -1) {
					d[i][to] = d[i][v] + 1;
					q.push(to);
				}
			}
		}
		for (int j = 1; j <= n; ++j) ++cnt[i][d[i][j]];
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int dist = 1; dist <= n; ++dist) {
			ans = add(ans, c(cnt[i][dist], k));
		}
	}
	cout << ans << '\n';
}

signed main() { calc();
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q = 1; cin >> q;
	while (q--) solve();

	cerr << fixed << setprecision(3) << "Time execution: " << (ld)clock() / CLOCKS_PER_SEC << endl;
}
