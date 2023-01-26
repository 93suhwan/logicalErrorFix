#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
const long long Mod = 1000000007, Mod2 = 998244353;
const long long MOD = Mod2;
const long long maxn = 1005;
long long n, m, a[maxn], b[maxn], c[maxn];
vector<long long> adj[maxn];
bool vis[maxn];
void orzck() {
  cin >> n >> m;
  for (long long i = (0); i < ((long long)(n - 1)); i++) cin >> a[i + 1];
  for (long long i = (0); i < ((long long)(n - 1)); i++) cin >> b[i + 1];
  for (long long i = (0); i < ((long long)(n - 1)); i++) a[i + 1]++;
  for (long long i = (0); i < ((long long)(n)); i++) adj[i].clear();
  for (long long i = (0); i < ((long long)(m)); i++) {
    long long u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  for (long long i = (0); i < ((long long)(n - 1)); i++) c[i + 1] = i + 1;
  sort(c + 1, c + n, [](long long i, long long j) { return a[i] > a[j]; });
  for (long long i = (0); i < ((long long)(n - 1)); i++) {
    long long u = c[i + 1];
    long long cnt = 0;
    for (auto v : adj[u])
      if (a[v] <= a[u] + b[u]) cnt++;
    if (cnt == 1) {
      long long minn = 4000000000000000000;
      for (auto v : adj[u])
        if (a[v] > a[u] + b[u]) (minn = min(minn, a[v]));
      a[u] = minn - b[u];
    }
  }
  long long l = 0, r = 7777714490;
  while (l < r) {
    long long mid = l + r >> 1;
    long long cur = mid;
    memset(vis, 0, sizeof vis);
    vis[0] = 1;
    long long u = 0;
    826;
    for (long long _ = (0); _ < ((long long)(n)); _++) {
      long long flag = 0;
      for (auto v : adj[u])
        if (vis[v]) flag++;
      cur += b[u];
      vis[u] = 1;
      826;
      if (flag >= 2) {
        bool ok = 0;
        for (long long i = (0); i < ((long long)(n)); i++)
          if (cur >= a[i] && !vis[i]) {
            bool flag2 = 0;
            for (auto j : adj[i])
              if (vis[j]) flag2 = 1;
            if (flag2) {
              u = i;
              ok = 1;
              break;
            }
          }
        if (!ok) break;
      } else {
        bool ok = 0;
        for (auto v : adj[u])
          if (cur >= a[v] && !vis[v]) {
            u = v;
            ok = 1;
            break;
          }
        if (!ok) break;
      }
    }
    bool flag = 1;
    for (long long i = (0); i < ((long long)(n)); i++)
      if (!vis[i]) flag = 0;
    if (flag)
      r = mid;
    else
      l = mid + 1;
  }
  print(l);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(15);
  long long t;
  cin >> t;
  while (t--) orzck();
  return 0;
}
