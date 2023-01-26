#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));
    vector<int> ma(m + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        cin >> p[i][j];
        if (p[i][j] > p[ma[j]][j]) ma[j] = i;
      }
    set<int> s;
    for (int i = 1; i <= m; i++) s.insert(ma[i]);
    if (s.size() == m) {
      int ans = 0;
      for (int i = 1; i <= m; i++) {
        int tem = 0;
        for (int j = 1; j <= m; j++) {
          if (i == j) continue;
          tem = max(tem, p[ma[j]][i]);
        }
        ans = max(tem, ans);
      }
      cout << ans << '\n';
    } else {
      int ans = 1e9;
      for (int i = 1; i <= m; i++) {
        ans = min(ans, p[ma[i]][i]);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
