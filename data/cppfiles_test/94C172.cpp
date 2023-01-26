#include <bits/stdc++.h>
using namespace std;
void in(int &n) {
  n = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || '9' < c) {
    if (c == '-') f *= -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    n = n * 10 + (c - '0');
    c = getchar();
  }
  n *= f;
}
void llin(long long &n) {
  n = 0;
  long long f = 1;
  char c = getchar();
  while (c < '0' || '9' < c) {
    if (c == '-') f *= -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    n = n * 10 + (c - '0');
    c = getchar();
  }
  n *= f;
}
long long pw10[25], a[25], b[25], sum[25];
int main() {
  pw10[0] = 1;
  for (int i = 1; i <= 18; i++) pw10[i] = pw10[i - 1] * 10ll;
  int t;
  in(t);
  while (t--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(sum, 0, sizeof(sum));
    int n;
    long long m;
    in(n);
    llin(m);
    m++;
    for (int i = 1; i <= n; i++) {
      int x;
      in(x);
      a[x] = 1;
      for (int j = x + 1; j <= 18; j++) a[j] = a[j - 1] * 10ll;
    }
    sum[0] = a[0] * 9ll;
    for (int i = 1; i <= 18; i++) sum[i] = sum[i - 1] + 9ll * a[i];
    while (m) {
      if (m <= sum[0]) {
        long long tmp = m;
        tmp = tmp / a[0] + ((tmp % a[0]) != 0);
        b[0] = tmp;
        m -= tmp * a[0];
        continue;
      }
      for (int i = 0; i < 18; i++) {
        if (sum[i] <= m && m <= sum[i + 1]) {
          long long tmp = m - sum[i];
          tmp = tmp / a[i + 1] + ((tmp % a[i + 1]) != 0);
          b[i + 1] = tmp;
          m -= tmp * a[i + 1];
          break;
        }
      }
    }
    long long ans = 0;
    for (int i = 18; i >= 0; i--) ans = ans * 10ll + b[i];
    printf("%lld\n", ans);
  }
  return 0;
}
