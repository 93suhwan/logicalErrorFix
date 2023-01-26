#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int cnt[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    cnt[u]++;
    if (cnt[u] == 1) ans++;
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      if (cnt[u] == 1) ans++;
    } else if (t == 2) {
      int u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      cnt[u]--;
      if (!cnt[u]) ans--;
    } else
      printf("%d\n", n - ans);
  }
  return 0;
}
