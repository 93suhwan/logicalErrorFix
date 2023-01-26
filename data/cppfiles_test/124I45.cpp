#include <bits/stdc++.h>
using namespace std;
int T, n, L[2000 + 5], R[2000 + 5], x, y;
long long dp[2000 + 5][2000 + 5], F[2000 + 5][2000 + 5], Q1[2000 + 5][2000 + 5],
    Q2[2000 + 5][2000 + 5];
char A[2000 + 5], B[2000 + 5];
inline long long calc1(int x, int y, int l, int r) {
  return Q1[y][r] - Q1[y][l - 1] - Q1[x - 1][r] + Q1[x - 1][l - 1];
}
inline long long calc2(int x, int y, int l, int r) {
  return Q2[y][r] - Q2[y][l - 1] - Q2[x - 1][r] + Q2[x - 1][l - 1];
}
inline void Solve() {
  register int i, j;
  scanf("%d%s%s", &n, A + 1, B + 1);
  for (i = 0; i <= n + 1; i++)
    for (j = 0; j <= n + 1; j++) dp[i][j] = F[i][j] = Q1[i][j] = Q2[i][j] = 0;
  A[0] = B[0] = A[n + 1] = B[n + 1] = 0;
  for (i = 1; i <= n; i += 2)
    A[i] ^ '?' && (A[i] ^= 1), B[i] ^ '?' && (B[i] ^= 1);
  for (i = 1; i <= n + 1; i++)
    L[i] = (A[i] ^ '1' ? L[i - 1] : i), R[i] = (B[i] ^ '1' ? R[i - 1] : i);
  F[0][0] = 1;
  for (i = 1; i <= n + 1; i++) {
    for (j = 1; j <= n + 1; j++) {
      Q1[i][j] = Q1[i - 1][j] + Q1[i][j - 1] - Q1[i - 1][j - 1];
      Q2[i][j] = Q2[i - 1][j] + Q2[i][j - 1] - Q2[i - 1][j - 1];
      if (A[i] == '0' || B[j] == '0') continue;
      x = L[i - 1];
      y = R[j - 1];
      F[i][j] = (calc1(x, i - 1, y, j - 1) + F[x][y]) % 1000000007;
      dp[i][j] = (F[i][j] * ((i - j) > 0 ? (i - j) : -(i - j)) +
                  calc2(x, i - 1, y, j - 1) + dp[x][y]) %
                 1000000007;
      if (A[i] == '?' || B[j] == '?') Q1[i][j] += F[i][j], Q2[i][j] += dp[i][j];
    }
  }
  printf("%lld\n", dp[n + 1][n + 1]);
}
int main() {
  scanf("%d", &T);
  while (T--) Solve();
}
