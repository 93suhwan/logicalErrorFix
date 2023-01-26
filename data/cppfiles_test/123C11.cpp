#include <bits/stdc++.h>
using namespace std;
const long long N = 2000100;
const long long mod = 998244353;
vector<long long> g[N];
long long go[N];
long long h[N];
long long val[N];
void dfs(long long v, long long pr) {
  go[v] = v;
  for (long long to : g[v]) {
    if (to != pr) {
      h[to] = h[v] + 1;
      dfs(to, v);
      if (h[go[to]] > h[go[v]]) go[v] = go[to];
    }
  }
  val[go[v]]++;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) g[i].clear();
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  h[1] = 0;
  dfs(1, 0);
  sort(val + 1, val + n + 1);
  reverse(val + 1, val + n + 1);
  long long w = 0;
  for (long long i = 1; i <= k; i++) {
    w += val[i];
  }
  if (n - w > k) {
    w = 0;
    long long r = k;
    for (long long i = 1; i <= k; i++) {
      w += val[i] - 1;
    }
    long long res = 0ll;
    for (long long b = 0; b <= n - r - w; b++) {
      res = min(res, 1ll * (n - r - b) * (r - b));
    }
    cout << res << '\n';
  } else {
    w = 0;
    long long res = 0;
    for (long long i = 1; i <= k; i++) {
      w += val[i] - 1;
      res = max(res, 1ll * w * (i - (n - w - i)));
    }
    cout << res << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
