#include <bits/stdc++.h>
using namespace std;
long long n, ver1, ver2, w, x, y, z, ans;
int main() {
  scanf("%lld", &n);
  w = 0;
  x = 0;
  y = 0;
  z = 0;
  for (long long i = 0; i < n; i++) {
    scanf("%lld%lld", &ver1, &ver2);
    if (ver1 % 4 == 0 && ver2 % 4 == 0) {
      w++;
    }
    if (ver1 % 4 != 0 && ver2 % 4 == 0) {
      x++;
    }
    if (ver1 % 4 == 0 && ver2 % 4 != 0) {
      y++;
    }
    if (ver1 % 4 != 0 && ver2 % 4 != 0) {
      z++;
    }
  }
  ans = w * (w - 1) * (x + y + z) + x * (x - 1) * (w + y + z) +
        y * (y - 1) * (w + x + z) + z * (z - 1) * (w + x + y);
  ans = ans + w * (w - 1) * (w - 2) / 3 + x * (x - 1) * (x - 2) / 3 +
        y * (y - 1) * (y - 2) / 3 + z * (z - 1) * (z - 2) / 3;
  ans = ans / 2;
  printf("%lld\n", ans);
}
