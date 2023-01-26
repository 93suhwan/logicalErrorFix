#include <bits/stdc++.h>
const int INF = (int)1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int A[n][m];
    for (auto &i : A)
      for (auto &j : i) j = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        A[i][j] = c - '0';
      }
    }
    int B[n + 1][m];
    for (auto &i : B)
      for (auto &j : i) j = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < m; ++j) B[i][j] = B[i - 1][j] + A[i - 1][j];
    }
    int ans = INF;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 4; j < n; ++j) {
        int cnt = j - i - 1;
        int C[m], D[m];
        for (int k = 0; k < m; ++k) C[k] = cnt - (B[j][k] - B[i + 1][k]);
        for (int k = 0; k < m; ++k)
          D[k] = (2 - A[i][k] - A[j][k]) + (B[j][k] - B[i + 1][k]);
        int mn = C[0] + D[1] + D[2];
        for (int k = 3; k < m; ++k) {
          ans = min(ans, mn + C[k]);
          mn = min(mn + D[k], C[k - 2] + D[k - 1] + D[k]);
        }
      }
    }
    cout << ans << '\n';
  }
}
