#include <bits/stdc++.h>
using namespace std;
const long long N = 2010;
long long T;
long long a[N];
long long n, k, x;
char s[N];
signed main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld%lld%s", &n, &k, &x, s + 1);
    long long cnt = 0, sum = 0;
    for (long long i = 1; i <= n; i++) {
      if (s[i] == '*')
        sum++;
      else if (sum)
        a[++cnt] = sum * k + 1, sum = 0;
    }
    if (sum) a[++cnt] = sum * k + 1, sum = 0;
    long double P = 1.0;
    long long L = 0;
    for (long long i = cnt; i >= 1; i--) {
      P *= a[i];
      if (P >= x) {
        L = i;
        break;
      }
    }
    cnt = sum = 0;
    for (long long i = 1; i <= n; i++) {
      if (s[i] == '*')
        sum++;
      else {
        if (sum && ++cnt >= L) {
          assert(a[cnt]);
          P /= a[cnt];
          for (long long k = 1; k < (x - 1) / ((long long)P) + 1; k++)
            putchar('b');
          x -= (x - 1) / ((long long)P) * ((long long)P);
        }
        putchar('a'), sum = 0;
      }
    }
    if (sum && ++cnt >= L) {
      P /= a[cnt];
      for (long long k = 1; k < (x - 1) / ((long long)P) + 1; k++) putchar('b');
      x -= (x - 1) / ((long long)P) * ((long long)P);
    }
    puts("");
  }
  return 0;
}
