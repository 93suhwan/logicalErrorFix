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
  long long n, m;
  pair<long long, long long> p1, p2;
  cin >> n >> m >> p1.first >> p1.second >> p2.first >> p2.second;
  long long x = 0, y = 0;
  if (p1.first > p2.first)
    x = 2 * n - (p1.first + p2.first);
  else
    x = p2.first - p1.first;
  if (p1.second > p2.second)
    y = 2 * m - (p1.second + p2.second);
  else
    y = p2.second - p1.second;
  cout << min(x, y) << "\n";
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
