//done by varunmaddipati
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
// #define int long long
#define all(x) x.begin(), x.end()
#define getline_clear int waste; scanf("%d\n", &waste)
#define merge_arrays(a,b,c) merge(all(a),all(b),back_inserter(c))
#define sz(x) ((int)(x).size())
#define uid(a, b) uniform_int_distribution<int>(a, b)
#define pb push_back
#define F first
#define S second

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = 1e9 + 7, nax = 1e5 + 5;
vector<int> primes, lf(nax);

ll mpow(ll base, ll exp, ll MOD);
void add_self(ll &a, ll b);
vector<int> randon_perm(int n);
void sieve(void);

void test_case() {
	int n, q; scanf("%d%d", &n, &q);
	string s; cin >> s;
	vector<vector<int>> v(6, vector<int>(n, 0));
	string s1; int cnt = 0;
	for (int i = 0; i < n; i++) {
		s1.pb('a' + cnt);
		cnt++; cnt %= 3;
	}
	string s2; cnt = 1;
	for (int i = 0; i < n; i++) {
		s2.pb('a' + cnt);
		cnt++; cnt %= 3;
	}
	string s3; cnt = 2;
	for (int i = 0; i < n; i++) {
		s3.pb('a' + cnt);
		cnt++; cnt %= 3;
	}
	string s4; cnt = 2;
	for (int i = 0; i < n; i++) {
		s4.pb('a' + cnt);
		cnt += 2; cnt %= 3;
	}
	string s5; cnt = 2;
	for (int i = 0; i < n; i++) {
		s5.pb('a' + cnt);
		cnt += 2; cnt %= 3;
	}
	string s6; cnt = 2;
	for (int i = 0; i < n; i++) {
		s6.pb('a' + cnt);
		cnt += 2; cnt %= 3;
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) v[0][i] = (s1[i] != s[i]);
		else v[0][i] = v[0][i - 1] + (s1[i] != s[i]);
		if (i == 0) v[1][i] = (s2[i] != s[i]);
		else v[1][i] = v[1][i - 1] + (s2[i] != s[i]);
		if (i == 0) v[2][i] = (s3[i] != s[i]);
		else v[2][i] = v[2][i - 1] + (s3[i] != s[i]);

		if (i == 0) v[3][i] = (s4[i] != s[i]);
		else v[3][i] = v[3][i - 1] + (s4[i] != s[i]);
		if (i == 0) v[4][i] = (s5[i] != s[i]);
		else v[4][i] = v[4][i - 1] + (s5[i] != s[i]);
		if (i == 0) v[5][i] = (s6[i] != s[i]);
		else v[5][i] = v[5][i - 1] + (s6[i] != s[i]);
	}
	while (q--) {
		int l, r; scanf("%d%d", &l, &r); l--; r--;
		int ans1 = v[0][r];
		if (l > 0) ans1 -= v[0][l - 1];
		int ans2 = v[1][r];
		if (l > 0) ans2 -= v[1][l - 1];
		int ans3 = v[2][r];
		if (l > 0) ans3 -= v[2][l - 1];
		int ans4 = v[3][r];
		if (l > 0) ans4 -= v[3][l - 1];
		int ans5 = v[4][r];
		if (l > 0) ans5 -= v[4][l - 1];
		int ans6 = v[5][r];
		if (l > 0) ans6 -= v[5][l - 1];
		printf("%d\n", min({ans1, ans2, ans3, ans4, ans5, ans6}));
	}
}

signed main() {
	// ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../inp", "r", stdin);
	freopen("../outp", "w", stdout);
	freopen("../err", "w", stderr);
#endif

	int T = 1; //cin >> T;
	for (int t = 1; t <= T; t++) {
		// cout << "Case #" << t << ": ";
		test_case();
	}
}

ll mpow(ll base, ll exp, ll MOD) {
	base %= MOD;
	ll result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

void add_self(ll &a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
}

vector<int> randon_perm(int n) {
	vector<int> v(n); iota(all(v), 1);
	for (int i = n - 1; i >= 0; i--) {
		int ind = rng() % (i + 1);
		swap(v[ind], v[i]);
	}
	return v;
}

void sieve(void) {
	iota(all(lf), 0);
	for (ll i = 2; i < nax; i++) {
		if (lf[i] == i) primes.pb(i);
		for (ll j = 0; j < (ll)primes.size() && i * primes[j] < nax; j++) {
			lf[i * primes[j]] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}
}
