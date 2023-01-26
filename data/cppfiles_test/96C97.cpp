#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, x, C[510][510], p[510][510], f[510][510];
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= 500; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  for (int i = 1; i <= 500; i++) {
    p[i][0] = 1;
    for (int j = 1; j <= 500; j++) {
      p[i][j] = (long long)p[i][j - 1] * i % mod;
    }
  }
  cin >> n >> x;
  f[n][0] = 1;
  for (int i = n; i > 1; i--) {
    for (int j = 0; j <= x; j++) {
      for (int k = i; k >= 0; k--) {
        int l = min(x, j + i - 1);
        f[k][l] =
            (f[k][l] + (long long)C[i][k] * p[l - j][i - k] % mod * f[i][j]) %
            mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= x; i++) {
    ans += f[0][i];
  }
  cout << ans % mod << endl;
  return 0;
}
