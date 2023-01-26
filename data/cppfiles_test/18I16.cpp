#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 3, LMAX = 3e16 + 13, IMAX = 2e9 + 13, mod = 998244353;
long long a[N];
vector<long long> g[N];
long long color[N];
long long val[N];
long long dfs(long long r) {
  color[r] = 1;
  long long ret = 0;
  for (auto i : g[r]) {
    if (color[i] == 1) return IMAX;
    if (color[i] == 2) return val[i] + 1;
    ret += max(ret, dfs(i));
  }
  color[r] = 2;
  return val[r] = ret + 1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T;
  cin >> T;
  for (long long t = 1; t <= T; t++) {
    long long n, d;
    cin >> n >> d;
    for (long long i = 0; i < n + 1; ++i) g[i].clear();
    for (long long i = 0; i < n; ++i) cin >> a[i];
    for (long long i = 0; i < n; ++i) {
      color[i] = -1;
      if (a[i] == 0) continue;
      color[i] = 0;
      long long temp = (i + n - d) % n;
      g[i].emplace_back(temp);
    }
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
      if (color[i] == 0) {
        ans = max(ans, dfs(i) - 1);
        if (ans >= IMAX - 1) break;
      }
    }
    if (ans >= IMAX - 1) ans = -1;
    cout << ans << "\n";
  }
}
