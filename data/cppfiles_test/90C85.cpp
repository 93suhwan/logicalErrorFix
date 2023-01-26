#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
long long a[70];
char s[N];
int main() {
  long long _, x, y;
  scanf("%lld", &_);
  a[0] = 1ll;
  for (long long i = 1; i <= 60; i++) {
    a[i] = a[i - 1] + 1;
  }
  while (_--) {
    scanf("%lld%lld", &x, &y);
    if (x > y) {
      printf("%lld\n", x * y + y);
    } else if (x == y) {
      printf("%lld\n", x);
    } else {
      printf("%lld\n", (y / x * x + y) / 2ll);
    }
  }
  return 0;
}
