#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
const int P = 998244353;
int N, X, f[MAXN][MAXN], pw[MAXN][MAXN], binom[MAXN][MAXN];
void add(int& a, int b) { a = a + b >= P ? a + b - P : a + b; }
int dif(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
int main() {
  for (int i = (0), iend = (MAXN); i < iend; ++i) {
    pw[i][0] = (i > 0);
    for (int j = (1), jend = (MAXN); j < jend; ++j)
      pw[i][j] = 1ll * pw[i][j - 1] * i % P;
  }
  binom[0][0] = 1;
  for (int i = (1), iend = (MAXN); i < iend; ++i) {
    binom[i][0] = 1;
    for (int j = (1), jend = (i + 1); j < jend; ++j)
      binom[i][j] = binom[i - 1][j - 1], add(binom[i][j], binom[i - 1][j]);
  }
  for (int i = (1), iend = (MAXN); i < iend; ++i) f[0][i] = 1;
  for (int i = (2), iend = (MAXN); i < iend; ++i)
    for (int j = (1), jend = (MAXN); j < jend; ++j) {
      for (int x = i - 1; x < j; x += i - 1) {
        for (int k = (1), kend = (i); k < kend; ++k)
          add(f[i][j],
              1ll * binom[i][k] * f[i - k][j - x] % P * pw[i - 1][k] % P);
      }
      for (int x = 0; x < j; x += i - 1) add(f[i][j], pw[min(i - 1, j - x)][i]);
    }
  scanf("%d %d", &N, &X);
  printf("%d\n", f[N][X]);
  return 0;
}
