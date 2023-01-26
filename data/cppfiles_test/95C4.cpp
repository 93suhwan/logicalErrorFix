#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cases;
  cin >> cases;
  for (int c = 0; c < cases; c++) {
    bool ok = false;
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> arr(rows + 1, vector<int>(cols + 1)),
        prefmax(rows + 2, vector<int>(cols + 2, 0)),
        prefmin(rows + 2, vector<int>(cols + 2, INT_MAX));
    for (int i = 1; i <= rows; i++)
      for (int j = 1; j <= cols; j++) {
        int x;
        cin >> x;
        arr[i][j] = x;
        prefmax[i][j] = max(prefmax[i][j - 1], x);
        prefmin[i][j] = min(prefmin[i][j - 1], x);
      }
    vector<vector<int>> suffmax(rows + 2, vector<int>(cols + 2, 0)),
        suffmin(rows + 2, vector<int>(cols + 2, INT_MAX));
    for (int i = 1; i <= rows; i++)
      for (int j = cols; j >= 1; j--) {
        suffmax[i][j] = max(suffmax[i][j + 1], arr[i][j]);
        suffmin[i][j] = min(suffmin[i][j + 1], arr[i][j]);
      }
    for (int j = 1; j < cols; j++) {
      vector<int> ind(rows);
      for (int i = 0; i < rows; i++) ind[i] = i + 1;
      sort(ind.begin(), ind.end(),
           [&](int a, int b) { return prefmin[a][j] < prefmin[b][j]; });
      vector<int> preftmax(rows + 2, 0), sufftmax(rows + 2, 0),
          preftmin(rows + 2, INT_MAX), sufftmin(rows + 2, INT_MAX);
      for (int i = 1; i <= rows; i++) {
        preftmax[i] = max(preftmax[i - 1], prefmax[ind[i - 1]][j]);
        sufftmin[i] = min(sufftmin[i - 1], suffmin[ind[i - 1]][j + 1]);
      }
      for (int i = rows; i >= 1; i--) {
        sufftmax[i] = max(sufftmax[i + 1], suffmax[ind[i - 1]][j + 1]);
        preftmin[i] = min(preftmin[i + 1], prefmin[ind[i - 1]][j]);
      }
      for (int i = 1; i < rows; i++) {
        if (preftmax[i] < preftmin[i + 1] && sufftmax[i + 1] < sufftmin[i]) {
          cout << "YES\n";
          vector<char> ans(rows);
          for (int k = 0; k < i; k++) ans[ind[k] - 1] = 'B';
          for (int k = i; k < rows; k++) ans[ind[k] - 1] = 'R';
          for (int k = 0; k < rows; k++) cout << ans[k];
          cout << ' ' << j << '\n';
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    if (!ok) cout << "NO\n";
  }
  return 0;
}
