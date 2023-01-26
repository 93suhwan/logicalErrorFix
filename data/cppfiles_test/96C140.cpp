#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
const double PI = 3.14159265358979323846;
const double eps = 1e-10;
const long long N = 510, mod = 998244353;
long long n, x, f[N][N];
long long bin(long long x, long long n, long long MOD) {
  long long ret = MOD != 1;
  for (x %= MOD; n; n >>= 1, x = x * x % MOD)
    if (n & 1) ret = ret * x % MOD;
  return ret;
}
inline long long get_inv(long long x, long long p) { return bin(x, p - 2, p); }
long long invf[N], fac[N] = {1};
void fac_inv_init(long long n, long long p) {
  for (decay<decltype(n)>::type i = (1), _i = (n); i < _i; ++i)
    fac[i] = i * fac[i - 1] % p;
  invf[n - 1] = bin(fac[n - 1], p - 2, p);
  for (decay<decltype(n - 2)>::type i = (n - 2), _i = (-1); i > _i; --i)
    invf[i] = invf[i + 1] * (i + 1) % p;
}
inline long long C(long long n, long long m) {
  return n < m || m < 0 ? 0 : fac[n] * invf[m] % mod * invf[n - m] % mod;
}
long long dfs(long long i, long long j) {
  if (f[i][j] != -1) return f[i][j];
  if (i == 1) return 0;
  f[i][j] = bin(min(j, i - 1), i, mod);
  if (j <= i - 1) {
    return f[i][j];
  }
  for (long long k = 0; k <= i - 1; k++) {
    f[i][j] +=
        (dfs(i - k, j - i + 1) * ((C(i, k) * bin(i - 1, k, mod)) % mod)) % mod;
    f[i][j] %= mod;
  }
  return f[i][j];
}
void solve() {
  cin >> n >> x;
  cout << dfs(n, x) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fac_inv_init(N - 5, mod);
  memset(f, -1, sizeof(f));
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
