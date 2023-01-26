#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef double ld;
const ld tau = 2*acos(-1);

const int MOD = 998244353;


// unity_root(n)^n = (e^(2.pi.i/n))^n = 1
inline complex<ld> unity_root(int n, bool inv) { 
	return polar<ld>(1.0, (inv ? -1 : 1) * tau / n);
}

template<typename T> void fft(vector<T>& a, bool inv) {
	for (int i = 1, j = 0; i < a.size(); i++) { // reverse bit order
		int bit = a.size() / 2;
		while (j & bit) j ^= bit, bit /= 2;
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}

	for (int n = 2; n <= a.size(); n *= 2) {
		vector<T> roots(n/2);
		T omega = unity_root(n, inv);
		roots[0] = 1;
		for (int i = 1; i < n/2; i++) roots[i] = roots[i-1] * omega;
		for (int i = 0; i < a.size(); i += n) {
			int l = i, r = i + n/2;
			for (int j = 0; j < n/2; j++, l++, r++) {
				T t = roots[j] * a[r];
				a[r] = a[l] - t, a[l] = a[l] + t;
			}
		}
	}
}

template<typename T> vector<T> convolution(vector<T> A, vector<T> B) {
	int n = A.size() + B.size();
	n = 1 << (__builtin_clz(1) - __builtin_clz(n) + (n & (n - 1) ? 1 : 0)); // log ceil
	A.resize(n), B.resize(n);

	fft(A, false), fft(B, false);
	vector<T> C(n);

	for (int i = 0; i < n; i++) C[i] = A[i] * B[i];
	
	fft(C, true);
	for (auto& c : C) c /= n;

	return C;
}

int n;

vector<int> deg;
vector<complex<ld>> solve(int l, int r) {
	if (l == r) {
		vector<complex<ld>> pol = {complex<ld>(1), complex<ld>(deg[l])};
		return pol;
	}
	int m = (l + r)/2;
	vector<complex<ld>> vl = solve(l, m), vr = solve(m + 1, r);
	if (vl.size() > n) vl.resize(n);
	if (vr.size() > n) vr.resize(n);
	for (complex<ld>& v : vl) v = (ll)round(v.real())%MOD;
	for (complex<ld>& v : vr) v = (ll)round(v.real())%MOD;
	return convolution(vl, vr);
}

int main() { _
	cin >> n;
	vector g(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	deg.resize(n);
	function<void(int, int)> dfs = [&] (int v, int p) {
		for (int u : g[v]) if (u != p)
			deg[v]++, dfs(u, v);
	};
	dfs(0, -1);

	vector<ll> fat(n + 1);
	fat[0] = 1;
	for (ll i = 1; i <= n; i += 1) fat[i] = fat[i - 1]*i%MOD;

	sort(deg.rbegin(), deg.rend());
	while (deg.back() == 0) deg.pop_back();
	int m = deg.size();
	vector<complex<ld>> G = solve(0, m - 1);
	for (complex<ld>& v : G) v = (ll)round(v.real())%MOD;

	ll ans = fat[n];
	for (ll i = 1, sgn = -1; i < min(m + 1, n); i += 1, sgn *= -1) {
		ans += sgn*fat[n - i]%MOD*ll(G[i].real())%MOD;
		ans %= MOD;
	}
	ans = (ans + MOD)%MOD;

	cout << ans << endl;

	return 0;
}