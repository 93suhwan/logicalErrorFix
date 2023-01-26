#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, q, ans;
int w[N];
void solve() {
  cin >> n >> m;
  memset(w, 0, 4 * n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    if (!w[u]) w[0]++;
    w[u]++;
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int tp, u, v;
    cin >> tp;
    if (tp == 1) {
      cin >> u >> v;
      if (u > v) swap(u, v);
      if (!w[u]) w[0]++;
      w[u]++;
    } else if (tp == 2) {
      cin >> u >> v;
      if (u > v) swap(u, v);
      w[u]--;
      if (!w[u]) w[0]--;
    } else if (tp == 3) {
      ans = n - w[0];
      cout << ans << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _ = 1;
  while (_--) solve();
  return 0;
}
