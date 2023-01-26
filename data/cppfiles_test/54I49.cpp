#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long jie[200005];
long long qpow(long long a, long long b) {
  if (b) {
    long long k = qpow(a, b / 2);
    long long sum = k * k;
    sum %= mod;
    if (b & 1) sum *= a;
    sum %= mod;
    return sum;
  }
  return 1;
}
long long C(long long n, long long m) {
  return jie[n] * qpow(jie[m], mod - 2) % mod * qpow(jie[n - m], mod - 2) % mod;
}
int T;
int main() {
  cin >> T;
  jie[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    jie[i] = jie[i - 1] * i;
    jie[i] %= mod;
  }
  while (T--) {
    int n, k;
    cin >> n >> k;
    k;
    long long sum = 0, all = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i += 2) sum += C(n, i), sum %= mod;
    for (int i = 0; i <= n; i++) all += C(n, i), all %= mod;
    if (n == 0) {
      cout << 1 << endl;
      continue;
    }
    if (n % 2) {
      cout << qpow(all - sum + 1, k) << endl;
    } else {
      for (int i = 1; i <= k; i++) {
        ans += qpow(all - sum - 1, i - 1) * qpow(all, k - i);
        ans %= mod;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
