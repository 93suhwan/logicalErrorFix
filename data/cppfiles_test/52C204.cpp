#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long b, long long p) {
  if (p == 0) return 1;
  if (p == 1) return b;
  long long a = bigmod(b, p / 2);
  a *= a;
  a %= 1000000007;
  if (p % 2 == 1) a *= b;
  a %= 1000000007;
  return a;
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long p = 1;
    long long ans = 0;
    while (k > 0) {
      ans += p * (k % 2);
      k /= 2;
      p *= n;
      p %= 1000000007;
      ans %= 1000000007;
    }
    cout << ans << "\n";
  }
}
