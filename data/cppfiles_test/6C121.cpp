#include <bits/stdc++.h>
using namespace std;
void solveCase() {
  long long n = 0, m = 0;
  cin >> n >> m;
  vector<long long> good(n, 0);
  while (m--) {
    long long u = 0, v = 0;
    cin >> u >> v;
    u--, v--;
    if (v > u) good[u]++;
    if (u > v) good[v]++;
  }
  long long ans = n;
  for (long long x : good) ans -= x > 0;
  long long q = 0;
  cin >> q;
  while (q--) {
    long long type = 0;
    cin >> type;
    if (type == 1) {
      long long u = 0, v = 0;
      cin >> u >> v;
      u--, v--;
      if (v > u) {
        good[u]++;
        if (good[u] == 1) ans--;
      }
      if (u > v) {
        good[v]++;
        if (good[v] == 1) ans--;
      }
    } else if (type == 2) {
      long long u = 0, v = 0;
      cin >> u >> v;
      u--, v--;
      if (v > u) {
        good[u]--;
        if (good[u] == 0) ans++;
      }
      if (u > v) {
        good[v]--;
        if (good[v] == 0) ans++;
      }
    } else
      cout << ans << '\n';
  }
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  solveCase();
}
