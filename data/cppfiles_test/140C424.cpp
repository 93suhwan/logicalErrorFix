#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    map<long long, long long> used;
    for (long long i = 1; i * i <= n; i++) {
      if (i * i * i <= n) {
        ++ans;
        used[i * i * i]++;
      }
      if (!used[i * i]) ++ans;
    }
    cout << ans << "\n";
  }
}
