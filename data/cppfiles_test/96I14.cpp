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
long long c[N][N], q[N][N], f[N][N];
void initCom() {
  for (int i = 1; i < N; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < N; j++) q[i][j] = quickPow(i, j);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  initCom();
  int n, x;
  cin >> n >> x;
  f[n][0] = 1;
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < x; j++) {
      for (int k = 0; k <= i; k++) {
        int nj = min(x, j + i - 1);
        f[k][nj] = (f[k][nj] + c[i][k] * q[nj - j][i - k] % MOD) % MOD;
      }
    }
  }
  long long ans = 0;
  for (int j = 1; j <= x; j++) ans += f[0][j];
  cout << ans << '\n';
  return 0;
}
