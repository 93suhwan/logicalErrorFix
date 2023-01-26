#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long int maxn = 3e5 + 16, md = 1e9 + 7, inf = 2e16;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int tav(long long int n, long long int k) {
  long long int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= n;
      res %= md;
    }
    n *= n;
    n %= md;
    k >>= 1;
  }
  return res;
}
struct segtree {
  long long int sz = 1;
  vector<vector<long long int>> val;
  vector<long long int> res;
  void init(long long int n) {
    while (sz < n) sz <<= 1;
    val.resize(sz << 1);
    return;
  }
  void add(long long int l, long long int r, long long int k, long long int x,
           long long int lx, long long int rx) {
    if (rx <= l || lx >= r) return;
    if (rx <= r && lx >= l) {
      val[x].push_back(k);
      return;
    }
    long long int m = (rx + lx) >> 1, ln = (x << 1) + 1, rn = ln + 1;
    add(l, r, k, ln, lx, m);
    add(l, r, k, rn, m, rx);
    return;
  }
  void add(long long int l, long long int r, long long int k) {
    add(l, r, k, 0, 0, sz);
    return;
  }
  void cal(long long int i, long long int x, long long int lx,
           long long int rx) {
    for (auto v : val[x]) {
      res.push_back(v);
    }
    val[x].clear();
    if (rx - lx == 1) return;
    long long int m = (rx + lx) >> 1, ln = (x << 1) + 1, rn = ln + 1;
    if (i < m) {
      cal(i, ln, lx, m);
    } else {
      cal(i, rn, m, rx);
    }
    return;
  }
  void cal(long long int i) {
    res.clear();
    cal(i, 0, 0, sz);
    return;
  }
};
segtree st;
long long int a[maxn], b[maxn], dp[maxn], par[maxn];
vector<long long int> adj[maxn], u;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, 63, sizeof(dp));
  long long int n;
  cin >> n;
  st.init(n + 1);
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    st.add(i - a[i], i + 1, i);
  }
  for (long long int i = 1; i <= n; i++) {
    cin >> b[i];
    long long int h = i + b[i];
    adj[h].push_back(i);
  }
  adj[0].push_back(0);
  u.push_back(0);
  dp[0] = 0;
  long long int x = 0;
  while (x < (long long int)(u.size())) {
    long long int v = u[x++];
    for (auto i : adj[v]) {
      st.cal(i);
      for (auto j : st.res) {
        if (dp[j] > dp[v] + 1) {
          dp[j] = dp[v] + 1;
          u.push_back(j);
          par[j] = i;
        }
      }
    }
  }
  if (dp[n] > n) {
    cout << "-1\n";
    return 0;
  }
  cout << dp[n] << '\n';
  long long int h = n;
  while (h > 0) {
    cout << par[h] << ' ';
    h = par[h];
    h += b[h];
  }
  cout << '\n';
  return 0;
}
