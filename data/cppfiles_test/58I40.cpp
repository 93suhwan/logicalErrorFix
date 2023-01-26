#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define siz(x) (int)x.size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool ckmin(auto &a, const auto &b) { return b < a ? a = b, 1 : 0; }
bool ckmax(auto &a, const auto &b) { return b > a ? a = b, 1 : 0; }

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char *s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
	string res = "{";
	for (int i = 0; i < (int)v.size(); i++)
		res += char('0' + v[i]);
	res += "}";
	return res;
}
template <size_t SZ> string to_string(bitset<SZ> b) {
	string res = "";
	for (int i = 0; i < b.size(); i++)
		res += char('0' + b[i]);
	return res;
}
template <class A, class B> string to_string(pair<A, B> p);
template <class T> string to_string(T v) {
	bool fst = 1;
	string res = "{";
	for (const auto &x : v) {
		if (!fst) res += ", ";
		fst = 0, res += to_string(x);
	}
	res += "}";
	return res;
}
template <class A, class B> string to_string(pair<A, B> p) { 
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; 
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if (sizeof...(t)) cerr << ", ";
	DBG(t...);
}

#ifdef ACMX 
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int RANDOM =
	chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64((x ^ RANDOM) * C); }
};
// gp_hash_table<ll, int, chash> h({}, {}, {}, {}, {1 << 17});

const int MOD = 998244353; 

template <int mod> struct mint {
	int v;
	explicit operator int() const { return v; }
	mint() { v = 0; }
	mint(ll _v) {
		v = int((-mod < _v && _v < mod) ? _v : _v % mod);
		if (v < 0) v += mod;
	}
	mint &operator+=(const mint &m) {
		if ((v += m.v) >= mod) v -= mod;
		return *this;
	}
	mint &operator-=(const mint &m) {
		if ((v -= m.v) < 0) v += mod;
		return *this;
	}
	mint &operator*=(const mint &m) {
		v = int((ll)v * m.v % mod);
		return *this;
	}
	friend mint pow(mint a, ll p) {
		mint ans = 1;
		assert(p >= 0);
		for (; p; p /= 2, a *= a)
			if (p & 1) ans *= a;
		return ans;
	}
	friend istream &operator>>(istream &is, mint &a) {
		long long x;
		is >> x, a = mint(x);
		return is;
	}
	friend ostream &operator<<(ostream &os, mint a) {
		os << a.v;
		return os;
	}
	friend mint inv(const mint &a) { return pow(a, mod - 2); }
	friend mint operator+(mint a, const mint &b) { return a += b; }
	friend mint operator-(mint a, const mint &b) { return a -= b; }
	friend mint operator*(mint a, const mint &b) { return a *= b; }
	friend mint operator/(mint a, const mint &b) { return a /= b; }
	friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
	friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
	friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
	friend string to_string(mint a) { return to_string(a.v); }
	mint &operator/=(const mint &m) { return (*this) *= inv(m); }
	mint operator-() const { return mint(-v); }
};

using mi = mint<MOD>;

vector<mi> invs, fac, ifac;
void genFac(int SZ) {
	invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ);
	invs[1] = fac[0] = ifac[0] = 1;
	for (int i = 2; i < SZ; i++)
		invs[i] = int(MOD - (ll)MOD / i * invs[MOD % i].v % MOD);
	for (int i = 1; i < SZ; i++) {
		fac[i] = fac[i - 1] * i;
		ifac[i] = ifac[i - 1] * invs[i];
	}
}

mi choose(int n, int k) {
	if (k > n) return 0;
	return fac[n] * ifac[n - k] * ifac[k];
}

int n, m; 
vector<pii> ops;
vector<vi> res; 

void build(vi a) {
	if (siz(a) < n) {
		for (int i = 0; i < n; i++) {
			a.pb(i);
			build(a);
			a.pop_back(); 
		}
	} else {
		vector<pii> cur;
		bool debug = 0; 
		vi orig = a; 
		if (a == vi{2, 1, 1}) {
			debug = 1; 
		}
		for (int i = 1; i < n; i++) {
			if (a[i] >= a[i - 1]) continue; 
			auto x = upper_bound(a.begin(), a.begin() + i, a[i]) - a.begin(); 
			cur.pb({i + 1, x + 1}); 
			auto v = a[i];
			a.erase(a.begin() + i); 
			a.insert(a.begin() + x, v);
		}
		if (debug) dbg(cur); 
		if (cur == ops) {
			res.pb(orig);
		}
	}
}

void brute() {
	// solve in O(n ^ n * n) 
	cin >> n >> m; 
	ops.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> ops[i].f >> ops[i].s;
	}
	vi st; 
	build(st);
	cout << siz(res) << "\n"; 
	for (auto &x : res) {
		sort(x.begin(), x.end());
		for (auto &v : x) {
			cout << v << " "; 
		}
		cout << "\n"; 
	}
	res.clear();
}

// a[3] < a[2] < a[0] <= a[1] && a[3] < a[2] <= a[4] < a[0] <= a[1]    a[3], a[2], a[0], a[1], 
// a[1] < a[2] < a[0]
// a[0] <= a[1] <= a[2] <= a[3] <= a[4] 

const int MX = 2e5;

oset<int> o; 

void solve() {
	int n, m;
	cin >> n >> m; 
	vector<pii> ops(m);
	for (auto &v : ops) {
		cin >> v.f >> v.s; 
	}

	vector<int> proc;

	auto sub = [&](int x) {
		proc.pb(x); 
		o.erase(x); 
	};

	// 2 equals, 3 numbers = choose(5, 2) 
	// 2 equals, 7 numberse = choose(7, 2) 
	set<int> used;
	int bad = 0; 
	for (auto [a, b] : ops) {
		a--, b--; 
		swap(a, b);
		auto x = *o.find_by_order(a);
		sub(x); 
		x = *o.find_by_order(a); 
		dbg(o); 
		if (x < n) used.insert(x); 
	}
	// a[0] <= a[1] <= a[2] <= a[3] <= a[4]
	// a[2] < a[0] <= a[1] <= a[3] <= a[4] 
	// a[3] < a[2] < a[0] <= a[1] <= a[4] 
	// a[3] < a[2] <= a[4] < a[0] <= a[1] 
	// 3 numbers 
	dbg(used);	
	cout << choose(n + n - siz(used) - 1, n - siz(used) - 1) << "\n"; 


	for (auto x : proc) {
		o.insert(x);
	}
	/*
	when an operation happens between two numbers x and y : 
	 if (x < y) x <= z < y (the number of bad shit doesnt change) 
	 if (x <= y) x <= z < y (the number of bad shit goes +1) 
	
	*/
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	genFac(MX);
	for (int i = 0; i < MX; i++) {
		o.insert(i); 
	}
	int t; 
	cin >> t;
	while (t--) {
		// brute(); 
		solve();
	}
}