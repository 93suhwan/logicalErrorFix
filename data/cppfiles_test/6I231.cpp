#include <bits/stdc++.h>
using namespace std;
const int sz = 2e5 + 10;
int mark[sz]{0}, extra[sz]{0};
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  int u, v;
  int ans = n;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (u > v) {
      mark[v]++;
      if (mark[v] == 1) {
        ans--;
      }
    } else {
      mark[u]++;
      if (mark[u] == 1) {
        ans--;
      }
    }
  }
  int q, x;
  cin >> q;
  vector<int> temp;
  int tt = ans;
  while (q--) {
    cin >> x;
    if (x == 1) {
      cin >> u >> v;
      temp.push_back(u);
      temp.push_back(v);
      if (u > v) {
        extra[v]++;
        if (extra[v] == 1) {
          ans--;
        }
      } else {
        extra[u]++;
        if (extra[u] == 1) {
          ans--;
        }
      }
    } else if (x == 2) {
      cin >> u >> v;
      if (u > v) {
        extra[v]--;
        if ((mark[v] + extra[v]) == 0) {
          ans++;
        }
      } else {
        extra[u]--;
        if ((extra[u] + mark[u]) == 0) {
          ans++;
        }
      }
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}
