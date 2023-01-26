#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
long long int dp[3][1001][1001];
bool has[1000][1000];
int n, m, q;
void tran(int i, int j) {
  if (i >= n || i < 0 || j < 0 || j >= m || has[i][j]) return;
  dp[2][i][j] = 1;
  if (i) dp[1][i][j] += dp[2][i - 1][j] + dp[0][i - 1][j];
  if (j) dp[0][i][j] += dp[2][i][j - 1] + dp[1][i][j - 1];
}
long long int ans = 0;
void upd(int i, int j, bool mode) {
  if (i >= n || i < 0 || j < 0 || j >= m) return;
  long long int c = mode ? 1 : -1;
  ans += c * (dp[0][i][j] + dp[1][i][j] + dp[2][i][j]);
  if (!mode) dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tran(i, j);
      upd(i, j, 1);
    }
  }
  while (q--) {
    int i, j;
    cin >> i >> j;
    has[i - 1][j - 1] ^= 1;
    while (i && j) {
      i--;
      j--;
    }
    for (int k = 0; k < n; k++) {
      upd(i + k - 1, j + k, 0);
      upd(i + k, j + k, 0);
      upd(i + k + 1, j + k, 0);
    }
    for (int k = 0; k < n; k++) {
      tran(i + k - 1, j + k);
      tran(i + k, j + k);
      tran(i + k + 1, j + k);
      upd(i + k - 1, j + k, 1);
      upd(i + k, j + k, 1);
      upd(i + k + 1, j + k, 1);
    }
    cout << ans << '\n';
  }
}
