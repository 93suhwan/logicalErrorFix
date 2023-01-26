#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    int res = 20;
    for (int i = 0; i + 4 < n; i++) {
      vector<int> cost1(m, 0), cost2(m, 0), val(m, 0);
      for (int k = 0; k < m; k++) {
        for (int j = 1; j <= 3; j++) {
          cost1[k] += (g[i + j][k] != '1');
          cost2[k] += (g[i + j][k] != '0');
        }
        cost2[k] += (g[i][k] != '1');
        cost2[k] += (g[i + 4][k] != '1');
      }
      for (int j = i + 4; j < n; j++) {
        if (j > i + 4) {
          for (int k = 0; k < m; k++) {
            cost1[k] += (g[j - 1][k] != '1');
            cost2[k] -= (g[j - 1][k] != '1');
            cost2[k] += (g[j - 1][k] != '0');
            cost2[k] += (g[j][k] != '1');
          }
        }
        int sum = 0, mx = -1 << 20;
        for (int k = 0; k < m; k++) {
          if (k >= 3) {
            mx = max(mx, val[k - 3]);
            res = min(res, sum + cost1[k] - mx);
          }
          sum += cost2[k];
          val[k] = sum - cost1[k];
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
