#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (; t--;) {
    int n, m, mid = 0x3f3f3f3f, big = 0;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<int> idx(n);
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != m; ++j) cin >> arr[i][j];
      idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](const int lhs, const int rhs) {
      return arr[lhs][0] > arr[rhs][0];
    });
    vector<vector<int>> lb(n, vector<int>(m, -0x3f3f3f3f)),
        rm(n, vector<int>(m, 0x3f3f3f3f));
    vector<int> rb(m, -0x3f3f3f3f), lm(m, 0x3f3f3f3f);
    for (int i = n - 1; i != -1; --i) {
      for (int j = 0; j != m; ++j) {
        lb[i][j] = arr[idx[i]][j];
        if (i < n - 1) lb[i][j] = max(lb[i][j], lb[i + 1][j]);
        if (j) lb[i][j] = max(lb[i][j], lb[i][j - 1]);
      }
      for (int j = m - 1; j != -1; --j) {
        rm[i][j] = arr[idx[i]][j];
        if (i < n - 1) rm[i][j] = min(rm[i][j], rm[i + 1][j]);
        if (j < n - 1) rm[i][j] = min(rm[i][j], rm[i][j + 1]);
      }
    }
    pair<int, int> ans(-1, -1);
    for (int i = 0; i != n - 1; ++i) {
      for (int j = 0; j != m; ++j) {
        lm[j] = min(lm[j], arr[idx[i]][j]);
        if (j) lm[j] = min(lm[j], lm[j - 1]);
      }
      for (int j = m - 1; j != -1; --j) {
        rb[j] = max(rb[j], arr[idx[i]][j]);
        if (j < m - 1) rb[j] = max(rb[j], rb[j + 1]);
      }
      for (int j = 0; j != m - 1; ++j)
        if (lm[j] > lb[i + 1][j] && rb[j + 1] < rm[i + 1][j + 1]) ans = {i, j};
    }
    if (ans.first == -1)
      cout << "NO\n";
    else {
      cout << "YES\n";
      string res(n, ' ');
      for (int i = 0; i != n; ++i) res[idx[i]] = i <= ans.first ? 'R' : 'B';
      cout << res << ' ' << ans.second + 1 << '\n';
    }
  }
}
