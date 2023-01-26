#include <bits/stdc++.h>
using namespace std;
void printv(vector<int>& vv);
int T, kase;
int m, n;
void solve() {
  cin >> m >> n;
  vector<vector<int>> a(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> id(m);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int x, int y) { return a[x][0] < a[y][0]; });
  int mxl_small[m][n], mnl_big[m][n], mnr_small[m][n], mxr_big[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      mxl_small[i][j] = a[id[i]][j];
      if (j) mxl_small[i][j] = max(mxl_small[i][j], mxl_small[i][j - 1]);
      if (i) mxl_small[i][j] = max(mxl_small[i][j], mxl_small[i - 1][j]);
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      mnl_big[i][j] = a[id[i]][j];
      if (j) mnl_big[i][j] = min(mnl_big[i][j], mnl_big[i][j - 1]);
      if (i < m - 1) mnl_big[i][j] = min(mnl_big[i][j], mnl_big[i + 1][j]);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = n - 1; j >= 0; j--) {
      mnr_small[i][j] = a[id[i]][j];
      if (j < n - 1)
        mnr_small[i][j] = min(mnr_small[i][j], mnr_small[i][j + 1]);
      if (i) mnr_small[i][j] = min(mnr_small[i][j], mnr_small[i - 1][j]);
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      mxr_big[i][j] = a[id[i]][j];
      if (j < n - 1) mxr_big[i][j] = max(mxr_big[i][j], mxr_big[i][j + 1]);
      if (i < m - 1) mxr_big[i][j] = max(mxr_big[i][j], mxr_big[i + 1][j]);
    }
  }
  for (int j = 0; j < n - 1; j++) {
    for (int i = 0; i < m - 1; i++) {
      if (mxl_small[i][j] < mnl_big[i + 1][j] &&
          mnr_small[i][j + 1] > mxr_big[i + 1][j + 1]) {
        cout << "YES\n";
        char res[m];
        for (int k = 0; k <= i; k++) res[id[k]] = 'B';
        for (int k = i + 1; k < m; k++) res[id[k]] = 'R';
        cout << res;
        cout << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << "NO"
       << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  for (kase = 1; kase <= T; kase++) {
    solve();
  }
  return 0;
}
void printv(vector<int>& vv) {
  for (int i = 0; i < vv.size(); i++) {
    if (i) cout << " ";
    cout << vv[i];
  }
  cout << "\n";
}
