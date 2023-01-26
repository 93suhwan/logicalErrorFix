#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, ans, temp, sum, k;
  string sans;
  t = 1;
  cin >> t;
  while (t--) {
    sans = "NO";
    ans = temp = sum = 0;
    cin >> n >> k;
    vector<long long> a(n + 1, 0);
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum <= k) {
      cout << 0 << "\n";
      continue;
    }
    if (sum == k + 1) {
      cout << 1 << "\n";
      continue;
    }
    sort((a).begin() + 1, (a).end());
    long long diff = sum - k;
    ans = sum - k;
    sum = 0;
    for (i = n; i > 1; i--) {
      sum += a[i];
      long long x;
      if (sum - (n - i + 1) * a[1] >= diff)
        x = 0;
      else
        x = max(ceil_div(diff - sum + (n - i + 1) * a[1], n - i + 2), 0LL);
      ans = min(ans, x + n - i + 1);
    }
    cout << ans << "\n";
  }
  return 0;
}
