#include <bits/stdc++.h>
using namespace std;
const int N = 2222, mod = 1e9 + 7;
int n, t, ans, a[N], cnt1[2][N], cntq[2][N];
string s[2];
int fac[N], ifac[N];
long long pow(long long x, long long y, long long mod) {
  return (!y ? 1 : pow(x * x % mod, y / 2, mod) * (y & 1 ? x : 1)) % mod;
}
void make_fac() {
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[N - 1] = pow(fac[N - 1], mod - 2, mod);
  for (int i = N - 2; i >= 0; i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1ll) % mod;
}
int C(int k, int n) {
  if (k < 0 || k > n) return 0;
  return 1ll * fac[n] * ifac[n - k] % mod * ifac[k] % mod;
}
int calc(int a0, int b0, int a1, int b1) { return C(a1 - a0 + b1, b0 + b1); }
void Main() {
  ans = 0;
  cin >> n;
  cin >> s[0] >> s[1];
  s[0] = ' ' + s[0];
  s[1] = ' ' + s[1];
  for (int k = 0; k < 2; k++) {
    for (int i = 1; i < n + 1; i++) {
      if (i & 1) {
        if (s[k][i] == '1')
          s[k][i] = '0';
        else if (s[k][i] == '0')
          s[k][i] = '1';
      }
      cnt1[k][i] = cnt1[k][i - 1] + (s[k][i] == '1');
      cntq[k][i] = cntq[k][i - 1] + (s[k][i] == '?');
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      ans = (ans + 1ll *
                       calc(cnt1[0][i - 1], cntq[0][i - 1], cnt1[1][j - 1],
                            cntq[1][j - 1]) *
                       calc(cnt1[0][n] - cnt1[0][i], cntq[0][n] - cntq[0][i],
                            cnt1[1][n] - cnt1[1][j], cntq[1][n] - cntq[1][j]) *
                       (s[0][i] != '0') * (s[1][j] != '0') % mod * abs(i - j) %
                       mod) %
            mod;
    }
  }
  cout << ans << '\n';
}
int main() {
  make_fac();
  cin >> t;
  while (t--) {
    Main();
  }
}
