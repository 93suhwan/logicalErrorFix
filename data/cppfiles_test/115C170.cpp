#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e18;
long long qpow(long long a, long long n, long long p = mod) {
  long long re = 1;
  while (n) {
    if (n & 1) re = (re * a) % p;
    n >>= 1;
    a = (a * a) % p;
  }
  return re % p;
}
long long a[200005], h;
int n;
int check(long long k) {
  long long sum = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] + k <= a[i + 1]) {
      sum += k;
    } else {
      sum += a[i + 1] - a[i];
    }
  }
  sum += k;
  return sum >= h;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %lld", &n, &h);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    long long l = 1, r = 1e18 + 5;
    while (l < r) {
      long long mid = (l + r) / 2;
      if (check(mid) == 0) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    printf("%lld\n", l);
  }
}
