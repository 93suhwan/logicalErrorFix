#include <bits/stdc++.h>
const int N = 505;
const int p = 998244353;
long long a[N][N];
long long b[N][N];
long long c[N][N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  for (int i = 0; i <= 500; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
  }
  for (int i = 1; i <= 500; i++) {
    b[i][1] = i;
    for (int j = 2; j <= 500; j++) b[i][j] = b[i][j - 1] * i % p;
  }
  for (int i = 1; i <= 500; i++) {
    a[i][1] = i;
    for (int j = 2; j <= i; j++)
      for (long long k = j, x = 1; k; k--, x = x * (j - 1) % p)
        a[i][j] = (a[i][j] + a[i - j + 1][k] * c[j][j - k] % p * x) % p;
  }
  int n, m;
  while (std::cin >> n >> m) std::cout << (b[m][n] - a[m][n] + p) % p << '\n';
  return 0;
}
