#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long n;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &x, &y);
    if (x > y) {
      printf("%lld\n", x + y);
    } else {
      n = y / x * x;
      n = n + (y - n) / 2;
      printf("%lld\n", n);
    }
  }
  return 0;
}
