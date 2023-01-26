#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
vector<pair<long long, long long> > e[maxn];
long long a[maxn], x[maxn], y[maxn], z[maxn];
bool ok;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i) {
      e[i].clear();
    }
    for (long long i = 1; i < n; ++i) {
      cin >> x[i] >> y[i] >> z[i];
      if (z[i] != -1) {
        (ok = __builtin_popcount(z[i])) &= 1;
        e[x[i]].push_back({y[i], ok});
        e[y[i]].push_back({x[i], ok});
      }
    }
    while (m--) {
      long long aa, b, ok;
      cin >> aa >> b >> ok;
      e[aa].push_back({b, ok});
      e[b].push_back({aa, ok});
    }
    memset(a, -1, sizeof(a));
    ok = true;
    for (long long i = 1; i <= n; ++i) {
      function<void(long long, long long)> dfs = [&](long long u, long long v) {
        a[u] = v;
        for (pair<long long, long long> g : e[u]) {
          if (a[g.first] == -1)
            dfs(g.first, v ^ g.second);
          else if (a[g.first] ^ v != g.second)
            ok = false;
        }
      };
      if (a[i] == -1) dfs(i, 0);
    }
    if (ok) {
      cout << "YES" << '\n';
      for (long long i = 1; i < n; ++i) {
        if (z[i] == -1) z[i] = a[x[i]] ^ a[y[i]];
        cout << x[i] << ' ' << y[i] << ' ' << z[i] << '\n';
      }
    } else
      cout << "NO" << '\n';
  }
  return 0;
}
