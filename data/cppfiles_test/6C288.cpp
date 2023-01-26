#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, u, v, m, ans, t;
  cin >> n >> m;
  vector<long long> c(n + 1);
  ans = n;
  while (m--) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    ++c[u];
    if (c[u] == 1) --ans;
  }
  cin >> m;
  while (m--) {
    cin >> t;
    if (t == 3)
      cout << ans << "\n";
    else {
      cin >> u >> v;
      if (u > v) swap(u, v);
      if (t == 1) {
        ++c[u];
        if (c[u] == 1) --ans;
      } else {
        --c[u];
        if (c[u] == 0) ++ans;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
