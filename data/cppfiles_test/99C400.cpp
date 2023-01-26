#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    long long x, n, res = 0;
    scanf("%lld%lld", &x, &n);
    if (x % 2 == 0) {
      long long f = n % 4;
      if (f == 0)
        f = 0;
      else if (f == 1)
        f = (n / 4 * 4) * -1 - 1;
      else if (f == 2)
        f = 1;
      else if (f == 3)
        f = (n / 4 * 4 + 4);
      res = x + f;
    } else {
      long long f = n % 4;
      if (f == 0)
        f = 0;
      else if (f == 1)
        f = n / 4 * 4 + 1;
      else if (f == 2)
        f = -1;
      else if (f == 3)
        f = (n / 4 * 4 + 4) * -1;
      res = x + f;
    }
    printf("%lld\n", res);
  }
}
