#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cnt(n + 1, 0);
  int ans = 0;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u = min(u, v);
    cnt[u]++;
    if (cnt[u] == 1) ans++;
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v;
      cin >> u >> v;
      u = min(u, v);
      cnt[u]++;
      if (cnt[u] == 1) ans++;
    } else if (type == 2) {
      int u, v;
      cin >> u >> v;
      u = min(u, v);
      cnt[u]--;
      if (cnt[u] == 0) ans--;
    } else {
      cout << n - ans << "\n";
    }
  }
  return 0;
}
