#include <bits/stdc++.h>
using namespace std;
int a[100100];
long long lcm[100100];
long long gcd(long long x, long long y) {
  while (y) {
    long long t = x % y;
    x = y;
    y = t;
  }
  return x;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    if (x <= y)
      printf("%lld\n", x + y >> 1);
    else
      printf("%lld\n", x + y);
  }
  return 0;
}
