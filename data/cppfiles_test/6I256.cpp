#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  int ans = n;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    u = min(v, u);
    if (A[u] == 0) ans--;
    A[u]++;
  }
  int q;
  cin >> q;
  while (q--) {
    int z;
    cin >> z;
    if (z == 3)
      cout << ans << endl;
    else if (z == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      u = min(u, v);
      if (A[u] == 0) ans--;
      A[u]++;
    } else if (z == 2) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      u = min(u, v);
      if (A[u] == 0) ans++;
      A[u]++;
    }
  }
}
int main() {
  solve();
  return 0;
}
