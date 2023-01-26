#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    bool ok = true;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        if (arr[i][j] != '.') {
          int cnt = 0;
          while (i - cnt >= 0 && j - cnt >= 0 && j + cnt < m &&
                 arr[i - cnt][j - cnt] != '.' && arr[i - cnt][j + cnt] != '.') {
            ++cnt;
          }
          if (cnt > k) {
            for (int p = 0; p < cnt; ++p) {
              arr[i - p][j - p] = '#';
              arr[i - p][j + p] = '#';
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (arr[i][j] == '*') ok = false;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
