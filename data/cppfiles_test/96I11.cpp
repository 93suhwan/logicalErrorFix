#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 1e5 + 10;
const long long MOD = 998244353;
int sign(double x, double y) {
  if (fabs(x - y) < 1e-12) return 0;
  if (x - y > 1e-12)
    return 1;
  else
    return -1;
}
long long quickPow(long long a, long long b) {
  long long res = 1;
  for (a %= MOD; b; b >>= 1) {
    if (b & 1) res = (res * a) % MOD;
    a = a * a % MOD;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long inv(long long x) { return quickPow(x, MOD - 2); }
int lowbit(int x) { return x & (-x); }
const int N = 505;
long long c[N][N], f[N][N];
void initCom() {
  c[0][0] = 1;
  for (int i = 1; i < N; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  initCom();
  int n, k;
  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j <= i - 1)
        f[i][j] = quickPow(j, i);
      else {
        for (int k = 2; k <= i; k++)
          f[i][j] = (f[i][j] + f[k][j - i + 1] * quickPow(i - 1, i - k) % MOD *
                                   c[i][k] % MOD) %
                    MOD;
        f[i][j] = (f[i][j] + quickPow(i - 1, i));
      }
    }
  }
  cout << f[n][k] << '\n';
  return 0;
}
