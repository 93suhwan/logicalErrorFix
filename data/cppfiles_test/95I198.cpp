#include <bits/stdc++.h>
using namespace std;
int T, num[100], n, len, a, ans, now, len2, aa, nn;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &a, &n);
    aa = a;
    len = ans = 0;
    while (a) {
      num[++len] = a % 10;
      ans += num[len];
      a /= 10;
    }
    now = len2 = 1;
    nn = n;
    if (ans < n) {
      for (int i = 2; i <= len && ans < nn;) {
        while (i == 1 || num[i] == 0) i++;
        num[i - 1] += 10;
        num[i]--;
        i--;
        nn -= 9;
      }
    }
    ans = 0;
    for (int i = 1; i <= n - 1; i++) {
      while (num[len2] == 0) len2++, now *= 10;
      printf("%d ", now);
      ans += now;
    }
    printf("%d\n", aa - ans);
  }
  return 0;
}
