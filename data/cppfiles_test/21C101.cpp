#include <bits/stdc++.h>
using namespace std;
int P;
int ad(int k1, int k2) { return k1 += k2 - P, k1 += k1 >> 31 & P; }
int su(int k1, int k2) { return k1 -= k2, k1 += k1 >> 31 & P; }
int mu(int k1, int k2) { return 1LL * k1 * k2 % P; }
void uad(int& k1, int k2) { k1 += k2 - P, k1 += k1 >> 31 & P; }
void usu(int& k1, int k2) { k1 -= k2, k1 += k1 >> 31 & P; }
template <typename... T>
int ad(int k1, T... k2) {
  return ad(k1, ad(k2...));
}
template <typename... T>
int su(int k1, T... k2) {
  return su(k1, ad(k2...));
}
template <typename... T>
int mu(int k1, T... k2) {
  return mu(k1, mu(k2...));
}
template <typename... T>
void uad(int& k1, T... k2) {
  return uad(k1, ad(k2...));
}
template <typename... T>
void usu(int& k1, T... k2) {
  return usu(k1, ad(k2...));
}
int po(int k1, int k2) {
  int k3 = 1;
  for (; k2; k2 >>= 1, k1 = mu(k1, k1))
    if (k2 & 1) k3 = mu(k3, k1);
  return k3;
}
const int N = 105;
int n, m, K, fac[N], C[N][N], dp[N][N][N];
int sol(int i, int j, int k) {
  if (dp[i][j][k] != -1) return dp[i][j][k];
  if (k + j - 1 > i && k != 0) return dp[i][j][k] = 0;
  if (k * 2 - 1 > i && k != 0) return dp[i][j][k] = 0;
  int& res = dp[i][j][k];
  res = 0;
  for (int i_ = (0); i_ <= (i - 1); ++i_) {
    for (int k_ = (0); k_ <= (k); ++k_) {
      uad(res,
          mu(sol(i_, j - 1, k_), sol(i - 1 - i_, j - 1, k - k_), C[i - 1][i_]));
    }
  }
  return res;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &K, &P);
  fac[0] = 1;
  for (int i = (1); i <= (N - 1); ++i) fac[i] = mu(fac[i - 1], i);
  C[0][0] = 1;
  for (int i = (1); i <= (N - 1); ++i) {
    C[i][0] = 1;
    for (int j = (1); j <= (i); ++j) {
      C[i][j] = ad(C[i - 1][j - 1], C[i - 1][j]);
    }
  }
  memset(dp, -1, sizeof(dp));
  memset(dp[0], 0, sizeof(dp[0]));
  memset(dp[1], 0, sizeof(dp[1]));
  for (int i = (0); i <= (N - 1); ++i) dp[0][i][0] = 1;
  dp[1][1][1] = 1;
  for (int i = (2); i <= (N - 1); ++i) {
    dp[1][i][0] = 1;
  }
  for (int i = (2); i <= (n); ++i) {
    memset(dp[i][1], 0, sizeof(dp[i][1]));
    dp[i][1][1] = fac[i];
  }
  printf("%d\n", sol(n, m, K));
  return 0;
}
