#include <bits/stdc++.h>
using namespace std;
long long d[501][501];
long long C[501][501];
long long P(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long x = P(a, n / 2);
  if (n % 2)
    return (((x * x) % 998244353) * a) % 998244353;
  else
    return (x * x) % 998244353;
}
long long n, x;
int main() {
  cin >> n >> x;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 500; i++) C[i][i] = C[i][0] = 1;
  for (int i = 1; i <= 500; i++)
    for (int j = 1; j < i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 998244353;
  d[1][1] = 1;
  for (int i = 2; i <= x; i++) {
    d[i][1] = 1;
    for (int j = 2; j <= n && i - j + 1 >= 0; j++) {
      long long p = 1;
      for (int k = j; k >= 1; k--) {
        d[i][j] += (((C[j][k] * d[i - j + 1][k]) % 998244353) * p) % 998244353;
        d[i][j] %= 998244353;
        p *= j - 1;
        p %= 998244353;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= x; i++) ans += d[i][n];
  ans %= 998244353;
  ans = P(x, n) - ans;
  while (ans < 0) ans += 998244353;
  cout << ans;
}
