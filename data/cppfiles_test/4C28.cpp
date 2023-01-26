#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7, MAXN = 2e5 + 5, oo = 3e18;
class fenwick {
 private:
  vector<long long> ft;

 public:
  vector<pair<long long, long long> > save;
  fenwick(long long n) { ft.assign(n + 5, 0); }
  long long ls(long long x) { return x & (-x); }
  void reset() {
    for (long long &cur : ft) {
      cur = 0;
    }
    save.clear();
  }
  void inc(long long pos, long long val) {
    pos++;
    if (pos <= 0) return;
    for (; pos < ft.size(); pos += ls(pos)) {
      ft[pos] = (ft[pos] + val + mod) % mod;
    }
  }
  long long rsq(long long pos) {
    pos++;
    if (pos <= 0) return 0;
    long long res = 0;
    for (; pos; pos -= ls(pos)) {
      res = (res + ft[pos] + mod) % mod;
    }
    return res;
  }
  void update(long long pos, long long val) {
    save.push_back(make_pair(pos, val));
    inc(pos, val);
  }
  void rollback(long long sz) {
    while (save.size() > sz) {
      pair<long long, long long> cur = save.back();
      save.pop_back();
      inc(cur.first, -cur.second);
    }
  }
};
fenwick black(MAXN);
fenwick white(MAXN);
fenwick cum_black(MAXN);
fenwick cum_white(MAXN);
long long tc, n, m;
long long a[MAXN], sum[MAXN];
vector<pair<long long, long long> > g[MAXN];
long long ANS;
long long sz[MAXN];
bool re[MAXN];
long long find_size(long long u, long long p = -1) {
  sz[u] = 1;
  for (auto cur : g[u]) {
    long long v = cur.first;
    if (v == p || re[v]) continue;
    sz[u] += find_size(v, u);
  }
  return sz[u];
}
long long find_centroid(long long u, long long sub, long long p = -1) {
  for (auto cur : g[u]) {
    long long v = cur.first;
    if (v == p || re[v]) continue;
    if (sz[v] > sub / 2) return find_centroid(v, sub, u);
  }
  return u;
}
long long cur_cen;
void dfs(long long u, long long p, long long col, long long trans,
         long long cur_down, bool filling) {
  if (trans > m) return;
  if (!filling) {
    sum[u] = (sum[p] + a[u] + mod) % mod;
  }
  if (filling) {
    long long exc = (sum[u] + mod - a[cur_cen]) % mod;
    if (cur_down == 0) {
      black.update(trans, 1);
      cum_black.update(trans, exc);
    } else {
      white.update(trans, 1);
      cum_white.update(trans, exc);
    }
  } else {
    if (trans <= m) {
      ANS = (ANS + sum[u] + mod) % mod;
    }
    long long tmp = 0;
    if (cur_down == 0) {
      tmp = sum[u] * black.rsq(m - trans) % mod;
      tmp = (tmp + cum_black.rsq(m - trans)) % mod;
      tmp = (tmp + sum[u] * white.rsq(m - 1 - trans) % mod) % mod;
      tmp = (tmp + cum_white.rsq(m - 1 - trans)) % mod;
      ANS = (ANS + tmp) % mod;
    } else {
      tmp = sum[u] * white.rsq(m - trans) % mod;
      tmp = (tmp + cum_white.rsq(m - trans)) % mod;
      tmp = (tmp + sum[u] * black.rsq(m - 1 - trans) % mod) % mod;
      tmp = (tmp + cum_black.rsq(m - 1 - trans)) % mod;
      ANS = (ANS + tmp) % mod;
    }
  }
  for (auto edge : g[u]) {
    long long v = edge.first, t = edge.second;
    if (v == p || re[v]) continue;
    if (t != col) {
      dfs(v, u, t, trans + 1, cur_down, filling);
    } else {
      dfs(v, u, t, trans, cur_down, filling);
    }
  }
}
void centroid(long long u = 1) {
  u = find_centroid(u, find_size(u));
  re[u] = true;
  cur_cen = u;
  long long black_size = black.save.size();
  long long white_size = white.save.size();
  long long cum_black_size = cum_black.save.size();
  long long cum_white_size = cum_white.save.size();
  sum[u] = a[u];
  for (auto edge : g[u]) {
    long long v = edge.first, t = edge.second;
    if (re[v]) continue;
    dfs(v, u, t, 0, t, 0);
    dfs(v, u, t, 0, t, 1);
  }
  black.rollback(black_size);
  white.rollback(white_size);
  cum_black.rollback(cum_black_size);
  cum_white.rollback(cum_white_size);
  for (auto edge : g[u]) {
    long long v = edge.first;
    if (re[v]) continue;
    centroid(v);
  }
}
void caau() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ANS = (ANS + a[i] + mod) % mod;
  }
  for (int i = 1; i < n; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  centroid();
  cout << ANS << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tc = 1;
  while (tc--) caau();
}
