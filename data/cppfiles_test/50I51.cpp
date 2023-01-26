#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 200007;
long long a[N];
long long x, y;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long re = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return re;
}
long long inv(long long a, long long mod) {
  exgcd(a, mod, x, y);
  return (x % mod + mod) % mod;
}
int main() {
  int n, k;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] %= mod;
  }
  long long ans = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      ans = ans * inv(a[i - 1], mod) % mod;
      long long cnt = ((a[i - 1] - 1) * a[i]) % mod;
      ans = ans * cnt % mod;
    } else {
      ans = (ans * (a[i] - 1)) % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
