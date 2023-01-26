#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 510;
int n, first;
long long f[N][N];
long long c[N][N];
long long qmi(long long a, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * a % mod;
    k >>= 1;
    a = a * a % mod;
  }
  return res;
}
int dp(int n, int first) {
  if (f[n][first] != -1) {
    return f[n][first];
  }
  f[n][first] = 0;
  if (n == 0) return f[n][first] = 1;
  if (n == 1) return f[n][first] = 0;
  if (first <= 0) return f[n][first] = 0;
  if (first <= n - 1)
    f[n][first] = (f[n][first] + qmi(first, n)) % mod;
  else
    f[n][first] = (f[n][first] + qmi(n - 1, n)) % mod;
  if (first >= n) {
    f[n][first] = (f[n][first] + dp(n, first - (n - 1))) % mod;
    for (int i = 1; i <= n - 2; i++)
      f[n][first] = (f[n][first] + c[n][i] * qmi(n - 1, i) % mod *
                                       dp(n - i, first - (n - 1)) % mod) %
                    mod;
  }
  return f[n][first];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++)
      if (!j)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  memset(f, -1, sizeof f);
  cin >> n >> first;
  cout << dp(n, first) << endl;
  return 0;
}
