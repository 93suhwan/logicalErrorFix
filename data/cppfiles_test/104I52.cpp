#include <bits/stdc++.h>
using namespace std;
int n, m, ans, lower, upper, a[200005], b[200005], l[200005], r[200005],
    ansa[200005], ansb[200005];
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 1) + (s << 3) + ch - '0';
    ch = getchar();
  }
  return s * f;
}
int main() {
  for (int t = read(); t; --t) {
    n = read(), m = read(), lower = upper = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = read(), b[i] = read();
      lower += max(a[i] - m, 0) + max(m - a[i], 0) - b[i];
      upper += a[i] - max(m - b[i], 0) - max(b[i] - m, 0);
    }
    if (lower >= 1) {
      printf("%d\n", lower);
      for (int i = 1; i <= n; ++i)
        printf("%d %d\n", a[i] - max(a[i] - m, 0), max(m - a[i], 0));
    } else if (upper <= -1) {
      printf("%d\n", -upper);
      for (int i = 1; i <= n; ++i)
        printf("%d %d\n", max(m - b[i], 0), b[i] - max(b[i] - m, 0));
    } else {
      int ans = upper % 1, nowl = 0, nowr = 0, nowtmp = 0;
      printf("%d\n", upper % 2);
      for (int i = 1; i <= n; ++i) {
        l[i] = l[i - 1] + max(a[i] - m, 0) + max(m - a[i], 0) - b[i];
        r[i] = r[i - 1] + a[i] - max(m - b[i], 0) - max(b[i] - m, 0);
      }
      for (int i = n; i >= 1; --i) {
        int nowl = max(a[i] - m, 0) + max(m - a[i], 0) - b[i];
        int nowr = a[i] - max(m - b[i], 0) - max(b[i] - m, 0);
        int nowans;
        if (l[i - 1] + nowtmp > ans) {
          nowans = ans - (l[i - 1] + nowtmp);
        } else if (r[i - 1] + nowtmp < ans) {
          nowans = ans - (r[i - 1] + nowtmp);
        } else {
          if (nowl <= 0 && nowr >= 0) nowans = nowr % 2;
          nowans = abs(nowl) < abs(nowr) ? nowl : nowr;
        }
        nowtmp += nowans;
        int he = a[i] + b[i] - m;
        int nowa = (he + nowans) / 2, nowb = he - nowa;
        ansa[i] = a[i] - nowa, ansb[i] = b[i] - nowb;
      }
      for (int i = 1; i <= n; i++) printf("%d %d\n", ansa[i], ansb[i]);
    }
  }
  return 0;
}
