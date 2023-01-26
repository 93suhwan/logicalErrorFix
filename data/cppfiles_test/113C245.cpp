#include <bits/stdc++.h>
using namespace std;
const int maxv = 1e6 + 10;
const int mod = 9999973;
const int maxNum = 0x7fffffff - 10;
const double eps = 1e-6;
const double PI = 3.1415926535;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (!x) putchar('0');
  char F[200];
  int tmp = x > 0 ? x : -x;
  if (x < 0) putchar('-');
  int cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar(F[--cnt]);
  putchar('\n');
}
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long x1, x2, p1, p2, p, cnt1 = 0, cnt2 = 0, temp;
    scanf("%lld%lld%lld%lld", &x1, &p1, &x2, &p2), p = min(p1, p2);
    p1 -= p, p2 -= p;
    temp = x1;
    while (temp) temp /= 10, cnt1++;
    temp = x2;
    while (temp) temp /= 10, cnt2++;
    if (p1 + cnt1 < p2 + cnt2)
      printf("<\n");
    else if (p1 + cnt1 > p2 + cnt2)
      printf(">\n");
    else {
      if (x1 * pow(10, p1) < x2 * pow(10, p2))
        printf("<\n");
      else if (x1 * pow(10, p1) > x2 * pow(10, p2))
        printf(">\n");
      else
        printf("=\n");
    }
  }
  return 0;
}
