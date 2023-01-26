#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a, long long b) {
  if (!b) return 1;
  long long tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % 998244353 * a % 998244353 : tmp * tmp % 998244353;
}
long long k, A, h, b[6], ans[100], base[100];
void dfs(long long deep, long long sum, long long has, long long bas) {
  if (deep == k + 1) {
    long long tot = (1 + (1 << k)) * (1 << k) / 2;
    if (sum >= tot) return;
    long long pos = tot - sum;
    has = (has + pos * A % 998244353) % 998244353;
    if (has == h) {
      ans[pos] = 1;
      for (long long i = k; i >= 1; i--) {
        long long cur = 0;
        for (long long j = (1 << k); j >= 1; j--) {
          if (!ans[j] && j + cur <= b[i]) {
            ans[j] = base[i];
            cur += j;
          }
        }
      }
      for (long long i = 1; i <= (1 << k); i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
      exit(0);
    }
    return;
  }
  long long mi = 0, mx = 0;
  for (long long i = 1; i <= (1 << k); i += (1 << deep)) {
    mi += i;
    mx += i + (1 << deep) - 1;
  }
  if (deep == k) bas = 2;
  base[deep] = bas;
  for (long long i = mi; i <= mx; i++) {
    b[deep] = i;
    dfs(deep + 1, sum + i, (has + qpow(A, bas) * i % 998244353) % 998244353,
        bas - 2);
  }
}
signed main() {
  cin >> k >> A >> h;
  dfs(1, 0, 0, (1 << (k - 1)) + 1);
  cout << -1 << endl;
}
