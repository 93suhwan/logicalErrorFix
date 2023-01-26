#include <bits/stdc++.h>
using namespace std;
int t, n, k, p[2010];
long long x, b[2010], ned[2010];
char s[2010];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%lld", &n, &k, &x);
    scanf("%s", s + 1);
    long long now = 0;
    int cnt = 0;
    for (int i = n; i >= 1; i--) cnt += (s[i] == 'a');
    if (x == 1) {
      for (int i = 1; i <= cnt; i++) putchar('a');
      putchar('\n');
      continue;
    }
    int lst = 0, tot = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'a' && lst != i - 1) {
        b[++tot] = i - lst - 1, p[tot] = lst;
        lst = i;
      }
      if (s[i] == 'a') lst = i;
    }
    if (lst != n) b[++tot] = n - lst, p[tot] = lst;
    now = 1;
    for (int i = tot; i >= 1; i--) {
      now *= (b[i] * 1ll * k + 1ll);
      if (now >= x) {
        now /= (b[i] * 1ll * k + 1ll);
        for (int j = 1; j <= p[i]; j++)
          if (s[j] == 'a') putchar('a');
        int jn;
        for (jn = 1; now * 1ll * jn + now <= x; jn++) putchar('b');
        long long res = x - (now * 1ll * max(1, jn - 1));
        memset(ned, 0, sizeof(ned));
        if (res) {
          res--;
          int lst = n + 1;
          for (int j = n; j >= p[i] + b[i] + 1; j--) {
            if (s[j] == 'a') {
              ned[j] = min(res, 1ll * k * (lst - j - 1));
              res -= k * (lst - j - 1) + 1;
              lst = j;
            }
          }
        }
        for (int j = p[i] + b[i] + 1; j <= n; j++) {
          if (s[j] == 'a') {
            putchar('a');
            for (int l = 1; l <= ned[j]; l++) putchar('b');
          }
        }
        putchar('\n');
        break;
      }
    }
  }
  return 0;
}
