#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long arr[n][m];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) cin >> arr[i][j];
  long long downs[m];
  memset(downs, 0, sizeof(downs));
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      if (arr[i][j] == 2) downs[j]++;
    }
  long long col;
  for (long long i = 0; i < k; i++) {
    cin >> col;
    col--;
    if (downs[col] != n) {
      long long row = 0;
      while (row != n) {
        if (arr[row][col] == 2)
          row++;
        else {
          downs[col]++;
          if (arr[row][col] == 1) {
            arr[row][col] = 2;
            col++;
          } else {
            arr[row][col] = 2;
            col--;
          }
        }
      }
    }
    cout << col + 1 << ' ';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
