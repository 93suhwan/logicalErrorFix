#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, mod = 998244353;
int c[maxn][maxn];
int f[maxn][maxn];
int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == 45) y = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57)
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * y;
}
inline int add(int x) { return x >= mod ? x - mod : x; }
inline int sub(int x) { return x < 0 ? x + mod : x; }
int main() {
  int n, x;
  n = read();
  x = read();
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = add(c[i - 1][j] + c[i - 1][j - 1]);
  }
  for (int j = 1; j <= x; j++) {
    int pw = 1;
    for (int i = 1; i <= j + 1; i++) pw = 1ll * pw * j % mod;
    for (int i = j + 1; i <= n; i++, pw = 1ll * pw * j % mod) f[i][j] = pw;
  }
  for (int j = 1; j <= x; j++) f[0][j] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= x; j++) {
      int sum = 0, pw = 1;
      for (int k = 0; k <= i; k++, pw = 1ll * pw * (i - 1) % mod)
        sum = add(sum + 1ll * c[i][k] * pw % mod * f[i - k][j - i + 1] % mod);
      f[i][j] = sum;
    }
  }
  printf("%d\n", f[n][x]);
  return 0;
}
