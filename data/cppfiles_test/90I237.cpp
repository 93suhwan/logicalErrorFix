#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
long long a[70];
char s[N];
int main() {
  long long _, x, y;
  scanf("%lld", &_);
  a[0] = 1ll;
  for (long long i = 1; i <= 30; i++) {
    a[i] = a[i - 1] * 2ll;
  }
  while (_--) {
    scanf("%lld%lld", &x, &y);
    if (x > y) {
      printf("%lld\n", x * y + y);
    } else if (x == y) {
      printf("%lld\n", x);
    } else {
      if (y % x) {
        for (int i = 0; i <= 30; i++) {
          if (y - a[i] == 0) {
            printf("%lld\n", y);
            break;
          }
          if ((y - a[i]) % x == y % (y - a[i])) {
            printf("%lld\n", y - a[i]);
            break;
          }
        }
      } else {
        printf("%lld\n", x);
      }
    }
  }
  return 0;
}
