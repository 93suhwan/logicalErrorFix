// Problem: E. Fixed Points
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/contest/1551/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define fi first
#define google_codejam int MMR; cin>>MMR; for (int i = 1; i <= MMR; i++) {cout << "Case #" << i << ": "; solve();}
#define int int64_t
#define left gazzy_garcia_ioi
#define len(x) (int(sizeof(x)/sizeof(x[0])))
#define mp make_pair
#define output_time cerr << "Time elapsed: " << 1000*clock() / CLOCKS_PER_SEC << "ms" << endl
#define pb push_back
#define right bossreaper_sucks_at_csgo
#define se second
#define sep cerr << "-----------------------------" << endl
#define short int32_t
#define sz(x) (int(x.size()))
#define test_cases int MMR; cin>>MMR; for (int i = 0; i < MMR; i++) 
#define test_input ifstream in("input.txt"); if (in) cin.rdbuf(in.rdbuf());
#define test_local freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr)

typedef long double ld;
typedef __int128 LL;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
typedef pair<LL, LL> pLL;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> using maxpq = priority_queue<T, vector<T>>;
template<class A, class B> using pq = priority_queue<A, vector<A>, B>;

#ifdef _LOCAL
	void debug_out() {cerr << endl;}
	template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
		cerr << H << ", ";
		debug_out(T...);
	}
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
	#define debug(...)
#endif

const int INTMAX = 9223372036854775807;
const int INTMIN = -9223372036854775807;
const ld pi = 3.1415926535897932385;

template<typename A, typename B> auto MIN(const A &a, const B &b) {return ((a) < (b) ? (a) : (b));}
template<typename A, typename B> auto MAX(const A &a, const B &b) {return ((a) > (b) ? (a) : (b));}

mt19937 RNG{random_device{}()};
template<typename T> T rand(const T &a, const T &b) {
	T m = b - a + 1;
	return a + RNG() % m;
}

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

template<typename K, typename V> using umap = unordered_map<K, V, custom_hash>;
template<typename K, typename V> using umultimap = unordered_multimap<K, V, custom_hash>;
template<typename T> using uset = unordered_set<T, custom_hash>;
template<typename T> using umultiset = unordered_multiset<T, custom_hash>;

bool setin(const string &s) {ifstream in(s.c_str()); if (in) freopen(s.c_str(), "r", stdin); return bool(in);}
void setout(const string &s) {freopen(s.c_str(), "w", stdout);}
void open(const string &s) {if (setin(s+".in")) setout(s+".out");}
template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> const &pair);
template<typename T> ostream& operator<<(ostream &out, uset<T> const &s);
template<typename T> ostream& operator<<(ostream &out, set<T> const &s);
template<typename T> ostream& operator<<(ostream &out, multiset<T> const &s);
template<typename T> ostream& operator<<(ostream &out, umultiset<T> const &s);
template<typename K, typename V> ostream& operator<<(ostream &out, multimap<K, V> const &m);
template<typename K, typename V> ostream& operator<<(ostream &out, umultimap<K, V> const &m);
template<typename T> ostream& operator<<(ostream &out, vector<T> const &v);
template<typename K, typename V> ostream& operator<<(ostream &out, map<K, V> const &m);
template<typename K, typename V> ostream& operator<<(ostream &out, umap<K, V> const &m);
template<typename T> ostream& operator<<(ostream &out, deque<T> d);
template<typename T> ostream& operator<<(ostream &out, stack<T> s);
template<typename A, typename B> ostream& operator<<(ostream &out, pq<A, B> heap);
ostream& operator<<(ostream &out, LL x);
template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> const &pair) {
  out << "(" << pair.first << ", " << pair.second;
  return out << ")";
}
template<typename T> ostream& operator<<(ostream &out, uset<T> const &s) {
  out << "["; int c = 0;
  for (T i : s) {if (c) out << ", "; out << i; c++;}
  return out << "]";
}
template<typename T> ostream& operator<<(ostream &out, set<T> const &s) {
  out << "["; int c = 0;
  for (T i : s) {if (c) out << ", "; out << i; c++;}
  return out << "]";
}
template<typename T> ostream& operator<<(ostream &out, vector<T> const &v) {
  out << "[";
  for (int i = 0; i < v.size(); i++) {if (i) out << ", "; out << v[i];}
  return out << "]";
}
template<typename K, typename V> ostream& operator<<(ostream &out, map<K, V> const &m) {
  out << "{"; int c = 0;
  for (const auto &pair : m) {if (c) out << ", "; out << pair.first << "=" << pair.second; c++;}
  return out << "}";
}
template<typename K, typename V> ostream& operator<<(ostream &out, umap<K, V> const &m) {
  out << "{"; int c = 0;
  for (const auto &pair : m) {if (c) out << ", "; out << pair.first << "=" << pair.second; c++;}
  return out << "}";
}
template<typename T> ostream& operator<<(ostream &out, multiset<T> const &s) {
  out << "["; int c = 0;
  for (T i : s) {if (c) out << ", "; out << i; c++;}
  return out << "]";
}
template<typename T> ostream& operator<<(ostream &out, umultiset<T> const &s) {
  out << "["; int c = 0;
  for (T i : s) {if (c) out << ", "; out << i; c++;}
  return out << "]";
}
template<typename K, typename V> ostream& operator<<(ostream &out, multimap<K, V> const &m) {
  out << "{"; int c = 0;
  for (const auto &pair : m) {if (c) out << ", "; out << pair.first << "=" << pair.second; c++;}
  return out << "}";
}
template<typename K, typename V> ostream& operator<<(ostream &out, umultimap<K, V> const &m) {
  out << "{"; int c = 0;
  for (const auto &pair : m) {if (c) out << ", "; out << pair.first << "=" << pair.second; c++;}
  return out << "}";
}
template<typename T> ostream& operator<<(ostream &out, deque<T> d) {
  out << "["; int c = 0;
  while (!d.empty()) {if (c) out << ", "; out << d.front(); d.pop_front(); c++;}
  return out << "]";
}
template<typename T> ostream& operator<<(ostream &out, stack<T> s) {
  out << "["; int c = 0;
  while (!s.empty()) {if (c) out << ", "; out << s.top(); s.pop(); c++;}
  return out << "]";
}
template<typename A, typename B> ostream& operator<<(ostream &out, pq<A, B> heap) {
  out << "["; int c = 0;
  while (!heap.empty()) {if (c) out << ", "; out << heap.top(); heap.pop(); c++;}
  return out << "]";
}
ostream& operator<<(ostream &out, LL n) {
	if (n < 0) {
		out.put('-');
		n = -n;
	}
	if (n > 9) out << n / 10;
	return out.put(n % 10 + '0');
}
istream& operator>>(istream &in, LL &n) {
	n = 0; 
	LL f = 1;
	char c; in.get(c);
	while (c < '0' || c > '9') {
		if (in.eof()) assert(false && "Reached EOF before reading next __int128.");
		if (c == '-') f = -1;
		in.get(c);
	}
	while (!in.eof() && c >= '0' && c <= '9') {
		n = n * 10 + c - '0';
		in.get(c);
	} 
	n *= f;
	return in;
}
template<typename A, typename B> istream& operator>>(istream &in, pair<A, B> &pair) {return in >> pair.first >> pair.second;}
template<typename T> void next_vec(vector<T> &vec, int l) {
  vec = vector<T>(l);
  for (int i = 0; i < l; i++) cin >> vec[i];
}
template<typename T> void next_grid(vector<vector<T>> &vec, int h, int w) {
  vec = vector<vector<T>>(h, vector<T>(w));
  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> vec[i][j];
}
template<typename T> void next_graph(vector<vector<T>> &adj, int nodes, int edges) {
	adj = vector<vector<int>>(nodes);
	for (int i = 0; i < edges; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
}
template<typename T> void next_directed_graph(vector<vector<T>> &adj, int nodes, int edges) {
	adj = vector<vector<int>>(nodes);
	for (int i = 0; i < edges; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
	}
}
template<typename T> void next_weighted_graph(vector<vector<pair<int, T>>> &adj, int nodes, int edges) {
	adj = vector<vector<pair<int, T>>>(nodes);
	for (int i = 0; i < edges; i++) {
		int a, b; T c; cin >> a >> b >> c;
		a--; b--;
		adj[a].eb(mp(b, c));
		adj[b].eb(mp(a, c));
	}
}
template<typename T> void next_dw_graph(vector<vector<pair<int, T>>> &adj, int nodes, int edges) {
	adj = vector<vector<pair<int, T>>>(nodes);
	for (int i = 0; i < edges; i++) {
		int a, b; T c; cin >> a >> b >> c;
		a--; b--;
		adj[a].eb(mp(b, c));
	}
}
string join(const vector<string> &vec, const string &t) {
  int l = vec.size();
  string s;
  for (int i = 0; i < l; i++) {
    s += vec[i];
    if (i != l-1) s += t;
  }
  return s;
}
int combo(int n, int d) {
  if (d > n) return 0;
  if (d*2 > n) d = n-d;
  if (d == 0) return 1;
  int res = n;
  for (int i = 2; i <= d; i++) {
    res *= (n-i+1);
    res /= i;
  }
  return res;
}
template<typename T> void shuffle_vec(vector<T> &vec) {
  shuffle(vec.begin(), vec.end(), mt19937(random_device()()));
}
int gcd(int a, int b) {
	assert(a >= 1 && b >= 1);
	return __gcd(a, b);
}
int lcm(int a, int b) {return a/gcd(a, b)*b;}
vector<string> split(const string& str, const string& delim = " ") {
  vector<string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == string::npos) pos = str.length();
    string token = str.substr(prev, pos-prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  }
  while (pos < str.length() && prev < str.length());
  return tokens;
}
template<typename T, typename F = function<T(T, T)>> vector<T> prefix(const vector<T> &vec, const F &f = [](T a, T b){return a+b;}) {
  int l = vec.size();
  if (l == 0) return vector<T>();
  vector<T> pre(l); pre[0] = vec[0];
  for (int i = 1; i < l; i++) pre[i] = f(pre[i-1], vec[i]);
  return pre;
}
template<typename T, typename F = function<T(T, T)>> vector<T> suffix(const vector<T> &vec, const F &f = [](T a, T b){return a+b;}) {
  int l = vec.size();
  if (l == 0) return vector<T>();
  vector<T> suf(l); suf[l-1] = vec[l-1];
  for (int i = l - 2; i >= 0; i--) suf[i] = f(suf[i+1], vec[i]);
  return suf;
}
int bs_lowest(const function<bool(int)> &f, int lo, int hi) {
  while (lo < hi) {
    int m = (lo+hi)/2;
    f(m) ? hi = m : lo = m+1;
  }
  return lo;
}
int bs_highest(const function<bool(int)> &f, int lo, int hi) {
  while (lo < hi) {
    int m = (lo+hi+1)/2;
    f(m) ? lo = m : hi = m-1;
  }
  return lo;
}
template<typename T> int bs_lowest(const vector<T> &vec, const T &n) {
  int l = vec.size();
  int left = 0, right = l-1;
  while (left<right) {
    int mid = (left+right)/2;
    if (vec[mid] < n) left = mid+1;
    else right = mid;
  }
  if (left > 0 && vec[left] > n) return left-1;
  return left;
}
template<typename T> int bs_highest(const vector<T> &vec, const T &n) {
  int l = vec.size();
  int left = 0, right = l-1;
  while (left<right) {
    int mid = (left+right+1)/2;
    if (vec[mid] > n) right = mid-1;
    else left = mid;
  }
  if (left < l-1 && vec[left] < n) return left+1;
  return left;
}
template<typename T> int sum(const T &x) {return accumulate(all(x), 0ll);}
template<typename A, typename B> int sum(const A &x, const B &f) {return accumulate(all(x), 0ll, f);}
template<typename T> int mine(const T &x) {return *min_element(all(x));} 
template<typename A, typename B> int mine(const A &x, const B &f) {return *min_element(all(x), f);}
template<typename T> int maxe(const T &x) {return *max_element(all(x));}
template<typename A, typename B> int maxe(const A &x, const B &f) {return *max_element(all(x), f);}
template<typename T> int mini(const T &x) {return min_element(all(x)) - x.begin();}
template<typename A, typename B> int mini(const A &x, const B &f) {return min_element(all(x), f);}
template<typename T> int maxi(const T &x) {return max_element(all(x)) - x.begin();}
template<typename A, typename B> int maxi(const A &x, const B &f) {return max_element(all(x), f) - x.begin();}
template<typename A, typename B> int lowb(const A &a, const B &b) {return lower_bound(all(a), b) - a.begin();}
template<typename A, typename B, typename C> int lowb(const A &a, const B &b, const C &f) {return lower_bound(all(a), b, f) - a.begin();}
template<typename A, typename B> int uppb(const A &a, const B &b) {return upper_bound(all(a), b) - a.begin();}
template<typename A, typename B, typename C> int uppb(const A &a, const B &b, const C &f) {return upper_bound(all(a), b, f) - a.begin();}
vector<bool> sieve(int n) {
  vector<bool> vec(n+1, true);
  vec[0] = false;
  vec[1] = false;
  for (int i = 2; i <= n; i++) {
    if (vec[i]) {
      for (int j = i*2; j <= n; j += i) vec[j] = false;
    }
  }
  return vec;
}
bool prime(int n) {
  for (int i = 2; i*i <= n; i++) if (n % i == 0) return false;
  return true;
}
template<typename T> umap<T, int> compress(const vector<T> &vec) {
	vector<T> sorted = vec;
	sort(all(sorted));
	int l = sorted.size();
	umap<T, int> m;
	for (int i = 0; i < l; i++) m[sorted[i]] = i;
	return m;
}
template <typename T> T power(T a, int b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

#define inf 1e18

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;

// if interactive, comment this out
#ifndef _LOCAL  
	#define endl '\n'
#endif

#define yes() {cout << "YES" << endl; return;}
#define no() {cout << "NO" << endl; return;}

void solve() {
	int l, k; cin >> l >> k;
	vi vec; next_vec(vec, l);
	for (int &i : vec) i--;
	vector<int> v(l);
	for (int i = 0; i < l; i++) {
		v[i] = max(i - vec[i], int(-1));
	}
	
	// dp[i][j] 
	// i is index, j is # of deleted
	//vector<vector<short>> dp(l, vector<short>(l));
	short dp[l][l];
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			dp[i][j] = 0;
		}
	}
	//debug(v);
	for (int i = 0; i < l-1; i++) {
		for (int j = 0; j < l; j++) {
			// delete cur 
			if (j < l-1) dp[i+1][j+1] = MAX(dp[i+1][j+1], dp[i][j] + (v[i+1] == j+1));
			// don't delete cur 
			dp[i+1][j] = MAX(dp[i+1][j], dp[i][j] + (v[i+1] == j));
		}
	}
	//debug(dp);
	//sep;
	for (int j = 0; j < l; j++) {
		for (int i = 0; i < l; i++) {
			if (dp[i][j] >= k) {
				cout << j << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  #ifndef _LOCAL
  	cin.tie(0);
  #endif
  open("fcolor");
  cout.precision(16);
  test_cases
  solve();
  //output_time;
}
