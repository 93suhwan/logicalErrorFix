#include <bits/stdc++.h>
using namespace std;
int n, m, A[405][405], B[405][405], a[405][405];
char s[405][405];
void Solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> (s[i] + 1);
    for (int j = 1; j <= m; ++j) {
      a[i][j] = s[i][j] - '0';
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      B[i][j] = B[i - 1][j] + a[i][j];
      A[i][j] = A[i - 1][j] + !a[i][j];
    }
  }
  int ans = n * m;
  for (int i = 2; i < n; ++i) {
    for (int j = i + 2; j < n; ++j) {
      static int s[405], pre[405];
      pre[0] = n * m;
      for (int k = 1; k <= m; ++k) {
        int w = B[j][k] - B[i - 1][k] + !a[j + 1][k] + !a[i - 1][k];
        s[k] = s[k - 1] + w;
        pre[k] = min(pre[k - 1], A[j][k] - A[i - 1][k] - s[k]);
      }
      for (int k = 4; k <= m; ++k) {
        ans = min(ans, pre[k - 3] + s[k - 1] + A[j][k] - A[i - 1][k]);
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}
