#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long modpow(long long a, long long x) {
  long long tmp = x;
  long long val = a;
  long long ret = 1LL;
  while (tmp > 0) {
    if (tmp % 2 == 1) ret = ret * val % mod;
    val = val * val % mod;
    tmp /= 2;
  }
  return ret;
}
long long modinv(long long a) { return modpow(a, mod - 2); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<long long>> G(1 << n, vector<long long>(n, 1));
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (((i >> j) & 1) == 0) continue;
      for (int k = 0; k < n; k++) {
        G[i][k] = G[i][k] * a[j] % mod * modinv(a[j] + a[k]) % mod;
      }
    }
  }
  long long ans = 0LL;
  vector<long long> P(1 << n);
  for (int i = 1; i < (1 << n); i++) {
    long long cnt = __builtin_popcount(i);
    long long P_tmp = 1LL;
    for (int j = i; j > 0; j = ((j - 1) & i)) {
      if (j == i) continue;
      long long G_tmp0 = 1LL;
      for (int k = 0; k < n; k++) {
        if (((j >> k) & 1) == 1) continue;
        if (((i >> k) & 1) == 0) continue;
        G_tmp0 = (G_tmp0 * G[j][k]) % mod;
      }
      P_tmp = (P_tmp - P[j] * G_tmp0 % mod + mod) % mod;
    }
    long long G_tmp1 = 1LL;
    for (int k = 0; k < n; k++) {
      if (((i >> k) & 1) == 1) continue;
      G_tmp1 = (G_tmp1 * G[i][k]) % mod;
    }
    ans = (ans + cnt * P_tmp % mod * G_tmp1) % mod;
    P[i] = P_tmp;
  }
  cout << ans << "\n";
  return 0;
}
