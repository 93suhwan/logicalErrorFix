#include <bits/stdc++.h>
using namespace std;
long long modular_pow(long long b, long long e, long long m) {
  if (m == 1) return 0;
  b %= m;
  long long r = 1;
  while (e > 0) {
    if (e & 1) r = (r * b) % m;
    b = (b * b) % m;
    e >>= 1;
  }
  return r;
}
long long npow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res = (res * x);
    n /= 2;
    x = (x * x);
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  if (n < 2) {
    cout << a[0] << "\n";
    return;
  }
  sort(a.begin(), a.end());
  long long i = 0, ans = LLONG_MIN, cnt = 0;
  while (i < n) {
    a[i] += cnt;
    ans = max(ans, a[i]);
    cnt += 0 - a[i++];
  }
  cout << ans << "\n";
}
signed main() {
  io();
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
