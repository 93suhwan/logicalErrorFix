#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
const int M = 1100000;
const long long mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;
long long n, k, a[N];
long long f[N], inv[N], fac[N], sinv[N], g[N];
long long pw[N];
long long pow_mod(long long a, long long e) {
  long long res = 1;
  for (; e; a = a * a % mod, e >>= 1)
    if (e & 1) res = res * a % mod;
  return res;
}
const int L = 500;
long long num;
long long C(int n, int m) {
  long long res = fac[n] * sinv[m] % mod;
  res = res * sinv[n - m] % mod;
  return res;
}
map<int, int> S;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == -1)
      num++;
    else
      S[a[i]]++;
  }
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++) inv[i] = pow_mod(i, mod - 2);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * (long long)i) % mod;
  sinv[0] = 1;
  for (int i = 1; i <= n; i++) sinv[i] = (sinv[i - 1] * inv[i]) % mod;
  f[0] = 0, f[1] = 0;
  for (int i = 2; i <= n; i++) {
    long long a = i - 1;
    long long tmp1 = (k - 1) * a + n - a;
    tmp1 %= mod;
    tmp1 = tmp1 * f[i - 1] % mod;
    long long tmp2 = (k - 1) * a % mod;
    tmp2 %= mod;
    tmp2 = tmp2 * f[i - 2] % mod;
    long long tmp3 = a * k % mod;
    long long tmp = (tmp1 - tmp2 - tmp3 + mod + mod) % mod;
    f[i] = tmp * inv[n - a] % mod;
  }
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = (pw[i - 1] * (k - 1)) % mod;
  long long fm = pow_mod(pow_mod(k, num), mod - 2);
  for (int i = 0; i < L; i++) {
    long long res = 0;
    for (int j = 0; j <= num; j++) {
      long long tmp = C(num, j) * f[i + j] % mod;
      res = (res + tmp * pw[num - j]) % mod;
    }
    res = res * fm % mod;
    g[i] = res;
  }
  long long ans = 0;
  for (auto p : S) {
    int val = p.second;
    ans = (ans + g[val]) % mod;
  }
  ans = (ans + (k - S.size()) * g[0]) % mod;
  cout << (ans - f[n] + mod) % mod << "\n";
  return 0;
}
