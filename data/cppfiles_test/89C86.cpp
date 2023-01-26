#include <bits/stdc++.h>
using namespace std;
void show(vector<long long> &a) {
  for (long long e : a) {
    if (e == (long long)(1e18 + 5))
      cout << "INF ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
void show(vector<int> &a) {
  for (int e : a) {
    if (e == (long long)(1e9 + 7))
      cout << "MOD ";
    else
      cout << e << " ";
  }
  cout << "\n";
}
template <typename T>
void enter(vector<T> &a) {
  for (T &e : a) cin >> e;
}
long long inline mo(long long a) { return a % (long long)(1e9 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long n, bud, tot_leaf;
vector<vector<long long>> g;
vector<long long> is_leaf, leaf_cnt;
void dfs(long long par, long long anc = -1) {
  long long is = 1;
  for (long long e : g[par]) {
    if (e == anc) continue;
    dfs(e, par);
    is *= (!is_leaf[e]);
    leaf_cnt[par] += is_leaf[e];
  }
  is_leaf[par] = is;
  tot_leaf += (is_leaf[par] && par);
  bud += (!is_leaf[par] && par);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    g.assign(n, {});
    for (long long i = 0; i < n - 1; i++) {
      long long x, y;
      cin >> x >> y;
      x--;
      y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    is_leaf.assign(n, 0);
    bud = 0;
    leaf_cnt.assign(n, 0);
    tot_leaf = 0;
    dfs(0);
    if (!is_leaf[0]) tot_leaf--;
    tot_leaf -= (bud - 1);
    cout << tot_leaf << "\n";
  }
  return 0;
}
