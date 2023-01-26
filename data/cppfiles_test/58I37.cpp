#define wiwihorz
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma loop-opt(on)

#define rep(i, a, b) for(int i = a; i <= b; i ++)
#define rrep(i, a, b) for(int i = b; i >= a; i --)
#define all(x) x.begin(), x.end()
#define ceil(a, b) ((a + b - 1) / (b))

#define INF 1000000000000000000
#define MOD 998244353
#define eps (1e-9)

using namespace std;

#define int long long int
#define lld long double
#define pii pair<int, int> 
#define random mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count())

#ifdef wiwihorz
#define print(a...) cerr << "Line " << __LINE__ << ": ", kout("[" + string(#a) + "] = ", a)
void vprint(auto L, auto R) {while(L < R) cerr << *L << " \n"[next(L) == R], ++L;}
void kout() { cerr << endl; }
template<class T1, class ... T2> void kout(T1 a, T2 ... e) { cerr << a << " ", kout(e...); }
#else
#define print(...) 0
#define vprint(...) 0
#endif
struct BIT {
	static const int n = (1 << 18), lg = 18;
	vector<int> cnt = vector<int>(n + 1, 0);
	stack<int> op;
	int lowbit(int x) {
		return x & (-x);
	}
	void modify(int x, int v) {
		if(v < 0) op.push(x);
		for(int i = x; i <= n; i += lowbit(i)) {
			cnt[i] += v;	
		}
	} 
	int query(int k) {
		int ans = 0, cal = 0;
		rrep(i, 0, lg - 1) if(cal + cnt[ans | (1 << i)] < k) {
			ans = (ans | (1 << i)), cal += cnt[ans];
		}
		return ans + 1;
	}
	void init_() {
		while(op.size()) {
			int x = op.top(); op.pop();
			modify(x, 1);
		}
	}
};
namespace solver {
	int n, m;
	BIT bit;
	const int P = (1 << 18);
	vector<int> x, y, fac, inv;
	vector<pii> a;
	int pow_(int a, int times) {
		int ans = 1;
		for(; times > 0; times >>= 1, a = a * a % MOD) {
			if(times & 1) ans = ans * a % MOD;
		}
		return ans;
	}
	void build() {
		fac.assign(P, 1);
		inv.assign(P, 1);
		rep(i, 1, P - 1) fac[i] = fac[i - 1] * i % MOD;
		inv[P - 1] = pow_(fac[P - 1], MOD - 2);
		rrep(i, 0, P - 2) inv[i] = inv[i + 1] * (i + 1) % MOD;
		rep(i, 1, P) bit.modify(i, 1); 
	}
	int C(int n, int m) {
		return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
	}
	void init_(int _n, int _m) {
		n = _n, m = _m;
		x.assign(m + 1, 0);
		y.assign(m + 1, 0);
		a.clear();
		bit.init_();
	}
	int solve() {
		rrep(i, 1, m) {
			int id = bit.query(y[i]);
			a.push_back({id, x[i]});
			bit.modify(id, -1);
		}
		int c = m; sort(all(a));
		rep(i, 1, m - 1) {
			if(a[i].first == a[i - 1].first + 1 &&
				a[i].second > a[i - 1].second) c --;
		}
		return C(2 * n - 1 - c, n);
	}
};
using namespace solver;
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	build();
	while(t--) {
		int n, m;
		cin >> n >> m;
		init_(n, m);
		rep(i, 1, m) cin >> x[i] >> y[i];
		cout << solve() << "\n";
	}
	return 0;
}