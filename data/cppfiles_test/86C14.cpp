#include <bits/stdc++.h>
using namespace std;
int T, pw[10000005], N, K, X, c[10000005], d[10000005];
long long exp(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long res = exp(a, b >> 1);
  if (b & 1) {
    return a * (res * res % 998244353) % 998244353;
  }
  return res * res % 998244353;
}
void solve() {
  cin >> N >> K >> X;
  if (!X) {
    if (K == 0 || N > K) {
      cout << 0 << endl;
      return;
    }
    long long ans = 1;
    for (int i = 0; i < N; ++i) {
      ans = 1ll * ans * ((long long)998244353 + pw[K] - pw[i]) % 998244353;
    }
    cout << ans << endl;
    return;
  }
  d[K] = 1;
  for (int i = K - 1; i >= 0; --i) {
    c[i] = 1ll * pw[i] * d[i + 1] % 998244353;
    d[i] = 1ll * (pw[i] - 1) * d[i + 1] % 998244353;
  }
  long long ans = 0;
  long long pwn = exp(2, N);
  long long cur = 1;
  for (int i = 0; i < K; ++i) {
    ans += 1ll * ((K - i - 1) & 1 ? 998244353 - 1 : 1) *
           (1ll * c[i] * cur % 998244353) % 998244353;
    if (ans >= 998244353) ans -= 998244353;
    cur = cur * pwn % 998244353;
  }
  cout << ans << endl;
  return;
}
int main() {
  pw[0] = 1;
  for (int i = 1; i < 10000005; ++i) {
    pw[i] = pw[i - 1] << 1;
    if (pw[i] >= 998244353) pw[i] -= 998244353;
  }
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
