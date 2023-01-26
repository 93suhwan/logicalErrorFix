#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(vector<vector<T>> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(multimap<T, V> v);
template <class T>
void _print(queue<T> v);
template <class T>
void _print(priority_queue<T> v);
template <class T>
void _print(stack<T> s);
template <class T>
void _print(T v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(vector<vector<T>> v) {
  cerr << "==>" << endl;
  for (vector<T> vec : v) {
    for (T i : vec) {
      _print(i);
      cerr << " ";
    }
    cerr << endl;
  }
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(multimap<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(queue<T> v) {
  cerr << "[ ";
  while (!v.empty()) {
    _print(v.front());
    v.pop();
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(priority_queue<T> v) {
  cerr << "[ ";
  while (!v.empty()) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(stack<T> v) {
  cerr << "[ ";
  while (!v.empty()) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(T v) {}
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
long long mod_exp(long long a, long long b) {
  a %= mod;
  if (a == 0) return 0LL;
  long long res = 1LL;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long mod_inv(long long a) { return mod_exp(a, mod - 2); }
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
vector<long long> v1, v2;
deque<long long> dq;
long long n, m;
vector<long long> v;
struct fenwick_tree {
  int n;
  vector<long long> bit;
  fenwick_tree(int n) {
    this->n = n;
    bit.clear();
    bit.resize(n + 1);
  }
  void init() {
    bit[0] = 0LL;
    for (int i = 1; i <= n; i++) bit[i] = 0LL;
  }
  void build() {
    for (int i = 1; i <= n; i++) {
      point_update(i, v[i]);
    }
  }
  void point_update(int i, long long delta) {
    while (i <= n) {
      bit[i] += delta;
      i += (i & (-i));
    }
  }
  long long range_query(int l, int r) {
    return range_query(r) - range_query(l - 1);
  }
  long long range_query(int i) {
    long long res = 0LL;
    while (i > 0) {
      res += bit[i];
      i -= (i & (-i));
    }
    return res;
  }
};
template <typename T>
struct coordinate_compression {
  map<T, T> id, rid;
  coordinate_compression() {
    id.clear();
    rid.clear();
  }
  void compress(vector<T> &v) {
    for (int i = 1; i <= n; i++) id[v[i]];
    int order = 0;
    for (auto &x : id) x.second = ++order, rid[x.second] = x.first;
  }
};
void solve() {
  cin >> n;
  v1.clear();
  v1.resize(n + 1, 0LL);
  v2.clear();
  v2.resize(n + 1, 0LL);
  dq.clear();
  m = 0;
  for (int i = 1; i <= n; i++) cin >> v1[i];
  struct coordinate_compression<long long> cc;
  cc.compress(v1);
  for (int i = 1; i <= n; i++) {
    v2[i] = cc.id[v1[i]];
    m = max(m, v2[i]);
  }
  v.clear();
  v.resize(m + 1, 0LL);
  fenwick_tree ft(m);
  ft.init();
  long long res = 0LL;
  for (int i = 1; i <= n; i++) {
    long long x = v2[i];
    long long fr, bk;
    if (x - 1 <= 0)
      fr = 0;
    else
      fr = ft.range_query(1, x - 1);
    if (x + 1 > m)
      bk = 0;
    else
      bk = ft.range_query(x + 1, m);
    res += min(fr, bk);
    ft.point_update(x, 1LL);
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
