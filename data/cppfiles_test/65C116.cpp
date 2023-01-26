#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
const long long M = 1e5 + 5;
const long long mod = 998244353;
const int inf = 1e9;
const double eps = 1e-9;
const double PI = acos(-1.0);
const pair<int, int> NIL = {0, 0};
int n, m;
long long l[N], r[N], mu[M], sum[M], f[M];
long long deal(long long d) {
  long long lim = m / d;
  f[0] = 1;
  for (long long i = 1; i <= lim; ++i) f[i] = 0;
  for (long long i = 1; i <= n; ++i) {
    long long L = (l[i] + d - 1) / d, R = r[i] / d;
    if (L > R) return 0;
    sum[0] = f[0];
    for (long long j = 1; j <= lim; ++j) sum[j] = (f[j] + sum[j - 1]) % mod;
    for (long long j = 0; j <= lim; ++j) {
      if (j > R)
        f[j] = (sum[j - L] - sum[j - R - 1] + mod) % mod;
      else if (j >= L)
        f[j] = sum[j - L];
      else
        f[j] = 0;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= lim; ++i) ans = (ans + f[i]) % mod;
  return ans;
}
void solve() {
  mu[1] = 1;
  cin >> n >> m;
  for (long long i = 1; i <= m; ++i)
    for (int j = i + i; j <= m; j += i) mu[j] = (mu[j] + mod - mu[i]) % mod;
  for (long long i = 1; i <= n; ++i) cin >> l[i] >> r[i];
  long long ans = 0;
  for (long long i = 1; i <= m; ++i) {
    ans = (mu[i] * deal(i) + ans + mod) % mod;
  }
  cout << ans << "\n";
}
int main() {
  solve();
  return 0;
}
