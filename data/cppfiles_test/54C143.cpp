#include <bits/stdc++.h>
using namespace std;
int vis[(int)(2e5 + 10) * 2];
int counts[(int)(2e5 + 10) * 2];
int anticounts[(int)(2e5 + 10) * 2];
int findroot(int x) { return x == vis[x] ? x : (vis[x] = findroot(vis[x])); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char opt[20];
    for (int i = 1; i <= 2 * n; ++i) vis[i] = i;
    int iferr = 0;
    for (int i = (0); i < (m); ++i) {
      int u, v;
      cin >> u >> v >> opt;
      if (iferr) continue;
      if (!strcmp(opt, "crewmate")) {
        int u1 = findroot(2 * u - 1), u2 = findroot(2 * u);
        int v1 = findroot(2 * v - 1), v2 = findroot(2 * v);
        if (u1 == v2 || u2 == v1) iferr = 1;
        vis[u1] = v1;
        vis[u2] = v2;
      } else {
        int u1 = findroot(2 * u - 1), u2 = findroot(2 * u);
        int v1 = findroot(2 * v - 1), v2 = findroot(2 * v);
        if (u1 == v1 || u1 == v1) iferr = 1;
        vis[u1] = v2;
        vis[u2] = v1;
      }
    }
    if (iferr)
      cout << "-1\n";
    else {
      memset(counts, 0, sizeof(int) * (2 * n + 1));
      memset(anticounts, 0, sizeof(int) * (2 * n + 1));
      for (int i = 1; i <= n; ++i)
        anticounts[findroot(i * 2)]++, counts[findroot(i * 2 - 1)]++;
      int ans = 0;
      for (int i = (1); i < (n * 2 + 1); ++i)
        ans += max(anticounts[i], counts[i]);
      cout << ans / 2 << '\n';
    }
  }
  return 0;
}
