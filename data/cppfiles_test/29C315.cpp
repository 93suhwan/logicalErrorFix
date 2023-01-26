#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long ksm(long long a, long long b, long long p) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return res;
}
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    long long x = 0, y = 0;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      if (a[i] == 1)
        x++;
      else if (a[i] == 0)
        y++;
    }
    printf("%lld\n", ksm(2, y, 1e18) * x);
  }
  return 0;
}
