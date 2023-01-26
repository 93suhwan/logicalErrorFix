#include <bits/stdc++.h>
using namespace std;
const int MAX = 202020;
const int INF = 1e9;
const long long LINF = 1e18;
long long p;
bool chk[101][101][101];
long long dp[101][101][101], C[101][101], fact[101];
long long f(int n, int m, int k) {
  if (m > n) return 0;
  if (k > m) return 0;
  if (k > (n - m + 1)) return 0;
  if (n == 0) {
    if (k == 0)
      return 1;
    else
      return 0;
  }
  if (m == 1) {
    if (k == 1)
      return fact[n];
    else
      return 0;
  }
  if (chk[n][m][k]) return dp[n][m][k];
  chk[n][m][k] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[n][m][k] += (C[n - 1][i - 1] *
                      ((f(i - 1, m - 1, j) * f(n - i, m - 1, k - j)) % p)) %
                     p;
      dp[n][m][k] %= p;
    }
  }
  return dp[n][m][k];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k >> p;
  C[0][0] = 1;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    fact[i] = (fact[i - 1] * i) % p;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    }
  }
  if (k > 50)
    cout << 0 << endl;
  else
    cout << f(n, m, k);
}
