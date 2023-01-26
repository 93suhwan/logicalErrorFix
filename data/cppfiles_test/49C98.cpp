#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = binpow(a, b / 2);
  ans = (1ll * ans * ans) % mod;
  if (b & 1) ans = (1ll * ans * a) % mod;
  return ans;
}
long long INV(long long x) { return binpow(x, mod - 2); }
template <typename T>
void md(T &x) {
  x %= mod;
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
}
template <typename T>
T mdd(T a) {
  a %= mod;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
  return a;
}
const long long B = 14;
long long f[(1 << B) + 1], dp[(1 << B) + 1], m[B];
long long win[B], lost[B];
long long clrW[B], clrL[B];
long long W[B][(1 << B) + 1], L[B][(1 << B) + 1];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  for (long long i = 0; i < n; ++i) {
    for (long long msk = 0; msk < (1 << n); ++msk) {
      L[i][msk] = W[i][msk] = 1;
      for (long long j = 0; j < n; ++j) {
        if ((1 << j) & msk) {
          W[i][msk] =
              (1ll * W[i][msk] * a[i] % mod * INV(mdd(a[i] + a[j]))) % mod;
          L[i][msk] =
              (1ll * L[i][msk] * a[j] % mod * INV(mdd(a[i] + a[j]))) % mod;
        }
      }
    }
  }
  for (long long msk = 0; msk < (1 << n); ++msk) {
    if (__builtin_popcount(msk) == 1) {
      f[msk] = 1;
      continue;
    }
    if (msk == 0) continue;
    long long tot = 0;
    for (long long u = msk; u > 0; u = (u - 1) & msk) {
      if (u != msk) {
        long long cur = msk ^ u;
        long long prob = 1;
        for (long long x = 0; x < n; ++x) {
          if ((1 << x) & cur) {
            prob = (1ll * prob * W[x][u]) % mod;
          }
        }
        tot += (1ll * prob * f[u]) % mod;
        md(tot);
      }
    }
    f[msk] = (1 - tot);
    md(f[msk]);
  }
  long long ans = 0;
  dp[0] = 1;
  for (long long msk = 0; msk < (1 << n); ++msk) {
    fill(m, m + B, 1);
    for (long long x = 0; x < n; ++x) {
      for (long long z = 0; z < n; ++z) {
        if ((1 << z) & msk) {
          m[x] = (1ll * m[x] * a[x] % mod * INV(mdd(a[x] + a[z])) % mod);
        }
      }
    }
    long long over = ((1 << n) - 1) ^ msk;
    for (long long u = over; u > 0; u = (u - 1) & over) {
      long long now = 1;
      for (long long x = 0; x < n; ++x) {
        if ((1 << x) & u) now = (1ll * now * m[x] % mod);
      }
      if ((msk ^ u) == ((1 << n) - 1)) {
        long long t = __builtin_popcount(u);
        long long option = (1ll * dp[msk] * f[u] % mod * now) % mod * t % mod;
        ans += (1ll * dp[msk] * f[u] % mod * now) % mod * t % mod;
        md(ans);
      } else {
        dp[msk ^ u] += (1ll * dp[msk] * f[u] % mod * now) % mod;
        md(dp[msk ^ u]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
