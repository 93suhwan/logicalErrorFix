#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int64_t fx[10] = {0, 1, 0, -1, 1, -1, 1, -1};
int64_t fy[10] = {1, 0, -1, 0, 1, -1, -1, 1};
const long long M = 2e5 + 10, M2 = 1e6 + 6, oo = 1e9 + 7, mod = 998244353;
const long long MC = (1 << 20) + 5;
int64_t ara[2005];
map<int64_t, map<string, int64_t> > dp;
map<int64_t, int64_t> mark;
map<string, map<string, int64_t> > bad;
map<int64_t, int64_t> vis;
map<int64_t, map<int64_t, int64_t> > uvis;
vector<vector<int64_t> > adj;
vector<string> allcolors;
int64_t bigmod(int64_t n, int64_t p, int64_t md) {
  if (p == 0) return 1;
  int64_t ans = bigmod(n, p / 2, oo);
  ans = (ans * ans) % md;
  if (p & 1) ans = (ans * n) % oo;
  return ans;
}
void precomp() {}
void solve() {
  int64_t kval, n, ans = 0;
  queue<int64_t> q;
  cin >> kval >> n;
  allcolors = {"white", "yellow", "green", "blue", "red", "orange"};
  for (int64_t i = 0; i < 5; i++) {
    bad[allcolors[i]][allcolors[i]] = 1;
    bad[allcolors[i]][allcolors[i + 1]] = 1;
    bad[allcolors[i + 1]][allcolors[i]] = 1;
  }
  for (string s : allcolors) {
    for (string ss : allcolors) {
      if (bad[s].count(ss) == 0) bad[s][ss] = 0;
    }
  }
  string s;
  for (int64_t i = 0; i < n; i++) {
    cin >> ara[i] >> s;
    q.push(ara[i]);
    for (string s : allcolors) dp[ara[i]][s] = 0;
    dp[ara[i]][s] = 1;
  }
  mark[1] = 1;
  for (int64_t i = 0; i < n; i++) {
    int64_t u = ara[i];
    while (u != 1) {
      mark[u] = 1;
      u = u / 2;
    }
  }
  while (q.size()) {
    int64_t u = q.front();
    q.pop();
    int64_t lc = u * 2;
    int64_t rc = u * 2 + 1;
    int64_t pr = u / 2;
    for (int64_t v : {lc, rc, pr}) {
      if (mark.count(v) && uvis[u].count(v) == 0) {
        uvis[u][v] = 1;
        uvis[v][u] = 1;
        for (string c : allcolors) {
          if (dp[v].count(c) == 0) dp[v][c] = 1;
          int64_t cur = 0;
          for (string cc : allcolors) {
            if (!bad[c][cc]) {
              cur += dp[u][cc];
              cur %= oo;
            }
          }
          dp[v][c] *= cur;
          dp[v][c] %= oo;
        }
        if (!vis.count(v)) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
  int64_t sz = (int64_t)mark.size();
  int64_t tot = (1LL << kval) - 1;
  tot -= sz;
  ans = bigmod(4, tot, oo);
  for (pair<int64_t, int64_t> p : mark) {
    int64_t u = p.first;
    int64_t cur = 0;
    for (string c : allcolors) {
      cur += dp[u][c];
      cur %= oo;
    }
    ans = (ans * cur) % oo;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precomp();
  solve();
  return 0;
}
