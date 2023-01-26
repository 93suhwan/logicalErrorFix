#include <bits/stdc++.h>
using namespace std;
class Math {
 public:
  long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
  long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
  void set_sieve(vector<bool> &sieve, long long n) {
    for (long long i = 2; i * i <= n; i++)
      if (sieve[i])
        for (long long j = i * i; j <= n; j += i) sieve[j] = false;
  }
  long long pow(long long x, long long n) {
    long long ans = 1;
    while (n > 0) {
      if (n & 1) ans *= x;
      x *= x;
      n = n >> 1;
    }
    return ans;
  }
  long long pow(long long x, long long n, long long m) {
    long long ans = 1;
    while (n > 0) {
      if (n & 1) ans = (ans * x) % m;
      x = (x * x) % m;
      n = n >> 1;
    }
    return ans;
  }
  long long modinv(long long x, long long p) { return pow(x, p - 2); }
} Math;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] > i + cnt) {
      cnt += a[i] - i - cnt;
    }
  }
  cout << cnt << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
