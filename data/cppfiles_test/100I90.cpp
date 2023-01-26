#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    long long x, n;
    scanf("%lld%lld", &x, &n);
    if (!n) {
      printf("%d\n", x);
      continue;
    }
    long long ans = x;
    if ((n - 1) % 2 == 0) {
      if ((n - 1) % 4 == 0) {
        if (x % 2 == 0) {
          ans -= 1;
          ans -= (n / 4) * 4;
        } else {
          ans += 1;
          ans += (n / 4) * 4;
        }
      } else {
        if (x % 2 == 0) {
          ans -= 1;
          ans -= ((n - 2) / 4) * 4;
          ans += 2 * n - 1;
        } else {
          ans += 1;
          ans += ((n - 2) / 4) * 4;
          ans -= 2 * n - 1;
        }
      }
    } else {
      n--;
      if ((n - 1) % 4 == 0) {
        if (x % 2 == 0) {
          ans -= 1;
          ans -= (n / 4) * 4;
        } else {
          ans += 1;
          ans += (n / 4) * 4;
        }
      } else {
        if (x % 2 == 0) {
          ans -= 1;
          ans -= ((n - 2) / 4) * 4;
          ans += 2 * n - 1;
        } else {
          ans += 1;
          ans += ((n - 2) / 4) * 4;
          ans -= 2 * n - 1;
        }
      }
      if (ans % 2)
        ans += n + 1;
      else
        ans -= n + 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
