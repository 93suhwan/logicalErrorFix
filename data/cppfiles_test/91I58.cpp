#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-15;
const int MAXN = 100005;
const int LIM = 100000;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const long long INF = 1e9 + 5;
const int MOD = 998244353;
int len = 62;
int a[MAXN];
vector<int> v[MAXN];
int t[MAXN];
int cnt = 0;
inline void block(int w) {
  for (int l = 1, r; l <= w; l = r + 1) {
    r = w / (w / l);
    v[w].push_back(l);
    cnt++;
  }
}
inline int ask(int x) {
  int ans = 0;
  for (int i = x; i; i -= (i & -i)) ans += t[i], ans %= MOD;
  return ans;
}
inline void add(int x, int k) {
  for (int i = x; i <= LIM; i += (i & -i)) t[i] += k, t[i] %= MOD;
}
inline int query(int l, int r) { return (ask(r) - ask(l - 1) + MOD) % MOD; }
inline void init() {
  for (int i = 1; i <= LIM; i++) block(i);
  cout << cnt << "\n";
}
inline void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 0;
  vector<pair<int, int> > pre, cur;
  for (int i = n; i >= 1; i--) {
    cur.push_back({a[i], (query(a[i], LIM) + 1) % MOD});
    int w = a[i] - 1;
    for (auto c : v[w]) {
      int l = c, r = w / (w / l), val = w / l;
      int tmp = query(l, r);
      ans += (long long)tmp * val % MOD * i % MOD;
      ans %= MOD;
      if (tmp) cur.push_back({a[i] / (val + 1), tmp});
    }
    for (auto c : pre) add(c.first, (-c.second + MOD) % MOD);
    if (i == 1) {
      break;
    }
    pre = cur;
    for (auto c : cur) {
      add(c.first, c.second);
    }
    cur.clear();
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
