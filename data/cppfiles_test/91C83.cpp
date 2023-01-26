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
  v[w].push_back(w + 1);
}
inline void init() {
  for (int i = 1; i <= LIM; i++) block(i);
}
inline void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 0;
  vector<pair<int, int> > pre, cur;
  for (int i = n; i >= 1; i--) {
    int w = a[i] - 1;
    int edv = v[w].size() - 1;
    int edp = pre.size() - 1, tk = 0;
    for (int j = 1; j <= edv; j++) {
      int r = v[w][j] - 1, val = w / v[w][j - 1];
      int tmp = 0;
      while (tk <= edp && pre[tk].first <= r) {
        tmp += pre[tk].second;
        tmp %= MOD;
        tk++;
      }
      ans += (long long)tmp * val % MOD * i % MOD;
      ans %= MOD;
      if (tmp) cur.push_back({a[i] / (val + 1), tmp});
      if (tk > edp) break;
    }
    int tmp = 0;
    for (int j = 0; j <= edp; j++)
      if (pre[j].first >= a[i]) tmp += pre[j].second, tmp %= MOD;
    cur.push_back({a[i], (tmp + 1) % MOD});
    if (i == 1) break;
    pre = cur;
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
