#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int p;
long long f[111];
long long c[111][111];
int d[111][111][111];
int solve(int n, int m, int k) {
  if (k == 0) {
    if (m > n) return f[n];
  }
  if (m < 1 || k < 0 || m > n || k > n) return 0;
  if (n == 1) return (k == 1 ? 1 : 0);
  if (m == 1) return (k == 1 ? f[n] : 0);
  if (d[n][m][k] != -1) return d[n][m][k];
  long long res = 0;
  for (int i = (0); i < (n); i++) {
    int c1 = i;
    int c2 = n - 1 - i;
    if (c1 == 0 || c2 == 0) {
      res = (res + solve(n - 1, m - 1, k)) % p;
    } else {
      for (int j = (0); j < (k + 1); j++)
        if (j <= c1 && k - j <= c2)
          res = (res + ((c[c1 + c2][c1] * solve(c1, m - 1, j)) % p) *
                           solve(c2, m - 1, k - j)) %
                p;
    }
  }
  return d[n][m][k] = res;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k >> p;
  if (p == 1) {
    puts("0");
    return 0;
  }
  f[0] = 1;
  for (int i = (1); i < (111); i++) f[i] = (f[i - 1] * i) % p;
  for (int i = (0); i < (111); i++) {
    c[i][i] = c[i][0] = (1 % p);
    for (int j = (1); j < (i); j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
  }
  memset(d, -1, sizeof d);
  cout << solve(n, m, k) << endl;
  return 0;
}
