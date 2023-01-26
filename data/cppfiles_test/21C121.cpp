#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
int mod, f[105][105][105], c[105][105];
int solve(int n, int m, int k) {
  if (n == 0) return !k;
  if (m == 0 && k) return 0;
  if (k && m > n) return 0;
  if (n < k || n + 1 < k * 2) return 0;
  if (f[n][m][k] != -1) return f[n][m][k];
  int flag = k;
  if (m == 1) {
    if (k != 1) return 0;
    k--;
  }
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      tmp = (tmp + 1ll * solve(i - 1, m - 1, j) * solve(n - i, m - 1, k - j) %
                       mod * c[n - 1][i - 1]) %
            mod;
    }
  }
  return f[n][m][flag] = tmp;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k >> mod;
  memset(f, -1, sizeof(f));
  c[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  cout << solve(n, m, k);
}
