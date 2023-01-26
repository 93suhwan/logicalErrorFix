#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long llINF = 9223372036854775807;
const int N = 1e5 + 10;
const double pi = acos(-1.0);
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long qpow(long long b, long long e, long long m = mod) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long n;
long long a[N], res[N];
void solve() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  long long g;
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i += 2) {
      res[i] = -a[i + 1];
      res[i + 1] = a[i];
    }
  } else {
    for (int i = 1; i <= n - 3; i += 2) {
      res[i] = -a[i + 1];
      res[i + 1] = a[i];
    }
    long long z = lcm(a[n - 2], a[n - 1]);
    z = lcm(z, a[n]);
    res[n - 2] = z / a[n - 2], res[n - 1] = z / a[n - 1],
            res[n] = -2 * z / a[n];
  }
  for (int i = 1; i <= n; i++) {
    if (i < n)
      printf("%lld ", res[i]);
    else
      printf("%lld\n", res[i]);
  }
}
int main() {
  int _ = 1;
  scanf("%d", &_);
  while (_--) {
    solve();
  }
  return 0;
}
