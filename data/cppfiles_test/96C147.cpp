#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
long long readll() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int MOD = 998244353;
int d[505][505], c[505][505], mi[505][505];
int main() {
  int n, x;
  n = read();
  x = read();
  c[1][1] = 1;
  c[1][0] = 1;
  for (int i = 2; i <= 500; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
  }
  for (int i = 1; i <= 500; i++) {
    for (int j = 0; j <= 500; j++) {
      if (j == 0)
        mi[i][j] = 1;
      else
        mi[i][j] = 1ll * mi[i][j - 1] * i % MOD;
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (j <= i - 1)
        d[i][j] = mi[j][i];
      else {
        d[i][j] = mi[i - 1][i];
        for (int k = 0; k <= i - 2; k++) {
          d[i][j] = (d[i][j] + 1ll * mi[i - 1][k] * c[i][k] % MOD *
                                   d[i - k][j - (i - 1)] % MOD) %
                    MOD;
        }
      }
    }
  }
  cout << d[n][x] << endl;
  return 0;
}
