#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int deg[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    deg[x]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0) ans++;
  int q;
  cin >> q;
  while (q--) {
    int op, x, y;
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      if (x > y) swap(x, y);
      deg[x]++;
      if (deg[x] == 1) ans--;
    } else if (op == 2) {
      cin >> x >> y;
      if (x > y) swap(x, y);
      deg[x]--;
      if (deg[x] == 0) ans++;
    } else
      cout << ans << "\n";
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
