#include <bits/stdc++.h>
const long long N = 3e5 + 100;
const long long mod = 1e9 + 7;
using namespace std;
long long n, m;
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long _ = 1;
  while (_--) {
    cin >> n;
    vector<long long> a(n + 1, 0), b(n + 1, 0);
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= n; i++) cin >> b[i];
    const long long M = (long long)1e8;
    vector<long long> dis(n + 1, M), par(n + 1, -1), bfs;
    set<long long> unknown;
    for (long long i = 0; i <= n; i++) unknown.insert(i);
    for (long long i = n; i >= n - a[n]; i--) {
      dis[i] = 1;
      unknown.erase(i);
      par[i] = n;
      bfs.push_back(i);
    }
    long long st = 0;
    while (st < bfs.size()) {
      long long s = bfs[st];
      st++;
      long long u = s + b[s];
      long long v = u - a[u];
      while (1) {
        auto it = unknown.lower_bound(v);
        if (it != unknown.end() && *it <= u) {
          long long t = *it;
          unknown.erase(t);
          dis[t] = dis[s] + 1;
          par[t] = s;
          bfs.push_back(t);
        } else
          break;
      }
    }
    if (dis[0] == M)
      cout << -1 << endl;
    else {
      long long cur = 0;
      vector<long long> path;
      while (cur != n) {
        path.push_back(cur);
        cur = par[cur];
      }
      reverse((path).begin(), (path).end());
      cout << path.size() << endl;
      for (auto x : path) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}
