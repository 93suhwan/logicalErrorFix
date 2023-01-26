#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> p(m, vector<int>(n));
    vector<int> pmx(n, -1);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> p[i][j];
        pmx[j] = max(pmx[j], p[i][j]);
      }
    }
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
      mn = min(mn, pmx[i]);
    }
    int l = 0, r = mn;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      int ok = 0;
      for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
          if (p[i][j] >= mid) cnt++;
        }
        if (cnt > 1) {
          ok = 1;
          break;
        }
      }
      if (!ok)
        r = mid - 1;
      else
        l = mid;
    }
    cout << l << '\n';
  }
  return 0;
}
