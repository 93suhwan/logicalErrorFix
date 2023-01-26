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

using str = string;
#define ts to_string

str ts(char c) { return str(1, c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char *s) { return (str)s; }
str ts(str s) { return s; }
template <class A> str ts(complex<A> c) {
	stringstream ss;
	ss << c;
	return ss.str();
}
str ts(vector<bool> v) {
	str res = "{";
	for (int i = 0; i < (int)v.size(); i++)
		res += char('0' + v[i]);
	res += "}";
	return res;
}
template <size_t SZ> str ts(bitset<SZ> b) {
	str res = "";
	for (int i = 0; i < b.size(); i++)
		res += char('0' + b[i]);
	return res;
}
template <class A, class B> str ts(pair<A, B> p);
template <class T> str ts(T v) {
	bool fst = 1;
	str res = "{";
	for (const auto &x : v) {
		if (!fst) res += ", ";
		fst = 0;
		res += ts(x);
	}
	res += "}";
	return res;
}
template <class A, class B> str ts(pair<A, B> p) {
	return "(" + ts(p.f) + ", " + ts(p.s) + ")";
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h);
	if (sizeof...(t)) cerr << ", ";
	DBG(t...);
}

#ifdef ACMX /* Credits of Debug Code go to Benjamin Qi */
#define dbg(...)                                                               \
	cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [",         \
		DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const int MX = 1e4 + 10; 

int n, k; 
int amt[MX]; 
int c[MX]; 
vi pos[MX]; 
vector<array<int, 3>> segs;
int ans[MX]; 
pii res[MX]; 

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	cin >> n >> k; 
	const int bound = (n + k - 2) / (k - 1); 
	for (int i = 0; i < n * k; i++) {
		cin >> c[i]; 
		c[i]--; 
		pos[c[i]].pb(i); 	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++) {
			segs.pb({pos[i][j + 1], pos[i][j], i}); 
		}
	}
	sort(segs.begin(), segs.end()); 
	for (auto &[L, R, idx] : segs) {
		bool ok = 1; 
		for (int i = L; i <= R; i++) {
			ok &= amt[i] < bound;	
		}
		if (ok && !ans[idx]) {
			res[idx] = {L + 1, R + 1}; 
		}
	}
	for (int i = 0; i < n; i++) 
		cout << res[i].f << " " << res[i].s << "\n"; 
}
