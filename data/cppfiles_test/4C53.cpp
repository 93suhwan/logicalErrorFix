#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const long long mod = 1e9 + 7;
int n, k;
vector<int> a;
vector<vector<pair<int, int>>> g;
vector<int> sz;
vector<int> mark;
struct BIT {
  int n;
  vector<long long> t;
  void init(int _n) {
    n = _n;
    t.resize(n);
  }
  void inc(int i, long long val) {
    for (; i < n; i = (i | (i + 1))) t[i] = (t[i] + val) % mod;
  }
  long long pref(int r) {
    long long res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) res = (res + t[r]) % mod;
    return (res + mod) % mod;
  }
};
BIT pref0, pref1, cnt0, cnt1;
void find_sz(int v, int p = -1) {
  sz[v] = 1;
  for (auto [to, type] : g[v])
    if (to != p && !mark[to]) {
      find_sz(to, v);
      sz[v] += sz[to];
    }
}
int find_centroid(int v, int p, int n) {
  for (auto [to, type] : g[v])
    if (!mark[to] && to != p && sz[to] * 2 > n) return find_centroid(to, v, n);
  return v;
}
struct history {
  int lastEdge;
  long long value;
  int k;
};
vector<history> current;
vector<history> total;
long long ans = 0;
void go(int v, int p, history hist, int last, int c) {
  hist.value = (hist.value + a[v]) % mod;
  if (hist.k <= k) {
    ans = (ans + hist.value) % mod;
    int i = k - hist.k;
    ans = (ans + pref0.pref(i - (hist.lastEdge == 1))) % mod;
    ans = (ans +
           cnt0.pref(i - (hist.lastEdge == 1)) * (hist.value - a[c] + mod)) %
          mod;
    ans = (ans + pref1.pref(i - (hist.lastEdge == 0)));
    ans = (ans +
           cnt1.pref(i - (hist.lastEdge == 0)) * (hist.value - a[c] + mod)) %
          mod;
    current.push_back(hist);
  }
  for (auto [to, type] : g[v]) {
    if (!mark[to] && to != p) {
      hist.k += (type != last);
      go(to, v, hist, type, c);
      hist.k -= (type != last);
    }
  }
}
void calc(int v) {
  find_sz(v);
  int c = find_centroid(v, -1, sz[v]);
  mark[c] = true;
  ans = (ans + a[c]) % mod;
  for (auto [to, type] : g[c]) {
    if (!mark[to]) {
      go(to, c, {type, a[c], 0}, type, c);
      while (!current.empty()) {
        if (type == 0) {
          pref0.inc(current.back().k, current.back().value);
          cnt0.inc(current.back().k, 1);
        } else {
          pref1.inc(current.back().k, current.back().value);
          cnt1.inc(current.back().k, 1);
        }
        total.push_back(current.back());
        current.pop_back();
      }
    }
  }
  while (!total.empty()) {
    if (total.back().lastEdge == 0) {
      pref0.inc(total.back().k, -total.back().value);
      cnt0.inc(total.back().k, -1);
    } else {
      pref1.inc(total.back().k, -total.back().value);
      cnt1.inc(total.back().k, -1);
    }
    total.pop_back();
  }
  for (auto [to, type] : g[c]) {
    if (!mark[to]) {
      calc(to);
    }
  }
}
void solve() {
  cin >> n >> k;
  a.resize(n);
  g.resize(n);
  mark.resize(n);
  sz.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    u--, v--;
    g[u].push_back({v, t});
    g[v].push_back({u, t});
  }
  pref0.init(n);
  pref1.init(n);
  cnt0.init(n);
  cnt1.init(n);
  current.reserve(n);
  total.reserve(n);
  calc(0);
  cout << ans;
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
