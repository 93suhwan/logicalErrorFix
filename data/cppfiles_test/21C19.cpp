#include <bits/stdc++.h>
using namespace std;
int N, M, K, p, C[110][110], F[110][110][110];
int f(int n, int m, int k) {
  if (n + 1 < k * 2 || n < k) return 0;
  if (m == 0 && k > 0) return 0;
  if (m == 1 && k > 1) return 0;
  if (n == 0) return k == 0;
  if (~F[n][m][k]) return F[n][m][k];
  F[n][m][k] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k - (m == 1); j++)
      (F[n][m][k] += 1ll * f(i, m - 1, j) *
                     f(n - i - 1, m - 1, k - j - (m == 1)) % p * C[n - 1][i] %
                     p) %= p;
  return F[n][m][k];
}
signed main() {
  cin >> N >> M >> K >> p;
  memset(F, -1, sizeof(F));
  C[0][0] = 1;
  for (int i = 1, j; i < 110; i++)
    for (C[i][0] = 1, j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
  cout << f(N, M, K);
  return 0;
}
