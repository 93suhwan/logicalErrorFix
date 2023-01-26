#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long t = 1;
long long MOD = 1000000007;
long long fast_ex(long long a, long long b) {
  long long tmp = a;
  long long ans = 1;
  for (long long i = 0; i < 64; i++) {
    if (b & (1ll << i)) {
      ans *= tmp;
      ans %= MOD;
    }
    tmp *= tmp;
    tmp %= MOD;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b) {
    return gcd(b, a % b);
  }
  return a;
}
long long n;
long long a[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  for (long long _ = 0; _ < t; _++) {
    cin >> n;
    long long ans = -(1ll << 60);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (i) {
        ans = max(ans, a[i] * a[i - 1]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
