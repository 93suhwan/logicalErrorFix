#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
using ll = long long;
using pii = pair<int, int>;
const long long N = 510;
long long f[N][N];
long long c[N][N];
void init() {
  for (long long i = 0; i < N; i++) {
    c[i][0] = c[i][i] = 1;
    for (long long j = 1; j < i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long T = 1;
  init();
  while (T--) {
    long long n, x;
    cin >> n >> x;
    f[n][0] = 1;
    for (long long i = n; i > 1; i--) {
      for (long long j = 0; j < x; j++) {
        if (!f[i][j]) continue;
        long long pow = 1, nj = min(x, i + j - 1);
        for (long long k = i; k >= 0; k--) {
          f[k][nj] = (f[k][nj] + f[i][j] * c[i][k] % mod * pow % mod) % mod;
          pow = pow * (nj - j) % mod;
        }
      }
    }
    long long res = 0;
    for (long long i = 0; i <= x; i++) res = (res + f[0][i]) % mod;
    cout << res << '\n';
  }
  return 0;
}
