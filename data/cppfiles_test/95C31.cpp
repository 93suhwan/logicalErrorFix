#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int _i = 0; _i < t; _i++) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> a[i][j];
      a[i][m] = i;
    }
    sort(a.begin(), a.end());
    int inf_l[n][m];
    int sup_l[n][m];
    int inf_r[n][m];
    int sup_r[n][m];
    for (int i = 0; i < n; i++) {
      inf_l[i][0] = a[i][0];
      sup_l[i][0] = a[i][0];
      inf_r[i][m - 1] = a[i][m - 1];
      sup_r[i][m - 1] = a[i][m - 1];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
        inf_l[i][j] = min(inf_l[i][j - 1], a[i][j]);
        sup_l[i][j] = max(sup_l[i][j - 1], a[i][j]);
      }
      for (int j = m - 2; j >= 0; j--) {
        inf_r[i][j] = min(inf_r[i][j + 1], a[i][j]);
        sup_r[i][j] = max(sup_r[i][j + 1], a[i][j]);
      }
    }
    for (int c = 0; c < m; c++) {
      for (int r = 1; r < n; r++) {
        sup_l[r][c] = max(sup_l[r][c], sup_l[r - 1][c]);
        inf_r[r][c] = min(inf_r[r][c], inf_r[r - 1][c]);
      }
      for (int r = n - 2; r >= 0; r--) {
        inf_l[r][c] = min(inf_l[r][c], inf_l[r + 1][c]);
        sup_r[r][c] = max(sup_r[r][c], sup_r[r + 1][c]);
      }
    }
    bool found_it = false;
    for (int k = 0; k < m - 1; k++) {
      if (found_it) break;
      for (int i = 1; i < n; i++) {
        if (inf_l[i][k] <= sup_l[i - 1][k]) continue;
        if (inf_r[i - 1][k + 1] <= sup_r[i][k + 1]) continue;
        cout << "YES" << endl;
        vector<pair<int, char>> res;
        for (int r = i; r < n; r++) res.push_back({a[r][m], 'R'});
        for (int r = 0; r < i; r++) res.push_back({a[r][m], 'B'});
        sort(res.begin(), res.end());
        for (auto r : res) cout << r.second;
        cout << " " << k + 1 << endl;
        found_it = true;
        break;
      }
    }
    if (!found_it) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
