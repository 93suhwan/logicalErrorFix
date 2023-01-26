#include <bits/stdc++.h>
using namespace std;
long long int inf = 1e18;
long long int mod = 1e9 + 7;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long int power(long long int x, long long int y, long long int p) {
  if (x == 0) return 0;
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int pwr(long long int x, long long int y) {
  if (x == 0) return 0;
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int ncr(long long int n, long long int r) {
  if (r > n) {
    return 0;
  }
  if (r > n - r) {
    r = n - r;
  }
  long long int ans = 1;
  for (long long int i = 1; i <= r; i++) {
    ans *= (n - i + 1);
    ans %= mod;
    ans *= modInverse(i, mod);
    ans %= mod;
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int TESTS, i, j, k, flag, t1, t2, t3, t4, t5, t6, t7, t8, t9;
  cin >> TESTS;
  while (TESTS--) {
    long long int a, b;
    cin >> a >> b;
    t1 = min(a, b);
    long long int left = (a + b) - (2 * t1);
    set<long long int> out;
    t2 = left / 2;
    out.insert(t2);
    out.insert(a + b - t2);
    for (i = 1; i <= t1; i++) {
      t2 += 2;
      out.insert(t2);
      out.insert(a + b - t2);
    }
    cout << out.size() << "\n";
    for (auto c : out) cout << c << " ";
    cout << "\n";
  }
}
