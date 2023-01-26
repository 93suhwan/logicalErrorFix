#include <bits/stdc++.h>
using namespace std;
const int h = 3, ki = 149;
int mo;
int mod(int x) { return (x % mo + mo) % mo; }
int inc(int x, int k) {
  x += k;
  return x < mo ? x : x - mo;
}
int dec(int x, int k) {
  x -= k;
  return x >= 0 ? x : x + mo;
}
int ksm(int x, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = 1ll * ans * x % mo;
    k >>= 1;
    x = 1ll * x * x % mo;
  }
  return mod(ans);
}
int inv(int x) { return ksm(x, mo - 2); }
int read() {
  char ch = 0;
  int x = 0, flag = 1;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') flag = -1;
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  }
  return x * flag;
}
void write(int x) {
  if (!x) return (void)putchar(48);
  if (x < 0) putchar(45), x = -x;
  int len = 0, p[20];
  while (x) p[++len] = x % 10, x /= 10;
  for (int i = len; i >= 1; i--) putchar(p[i] + 48);
}
void writeln(int x) { write(x), putchar('\n'); }
int fac[1100], C[1100][1100], dp[120][120][120];
int dfs(int n, int m, int k) {
  if (n == 0) {
    if (k) return 0;
    return 1;
  }
  if (m == 1) {
    if (k == 1)
      return fac[n];
    else
      return 0;
  }
  if (dp[n][m][k] != -1) return dp[n][m][k];
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++) {
      int t = C[n - 1][i - 1];
      ans = inc(ans, 1ll * t * dfs(i - 1, m - 1, j) % mo *
                         dfs(n - i, m - 1, k - j) % mo);
    }
  dp[n][m][k] = ans;
  return ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n, m, k;
  n = read();
  m = read();
  k = read();
  mo = read();
  C[0][0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= 200; i++) fac[i] = 1ll * fac[i - 1] * i % mo;
  for (int i = 1; i <= 200; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = inc(C[i - 1][j - 1], C[i - 1][j]);
  }
  write(dfs(n, m, k));
  return 0;
}
