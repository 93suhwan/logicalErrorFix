#include <bits/stdc++.h>
using namespace std;
long long p[4000005];
int sz[4000005];
char s[4000005], t[4000005];
int main() {
  long long x;
  int i, k, tt, n, m, cnt;
  scanf("%d", &tt);
  while (tt--) {
    cnt = 0;
    scanf("%d %d %lld %s", &n, &m, &x, s + 1);
    for (i = 1; i <= n; ++i)
      if (s[i] == 'a')
        t[++cnt] = 'a';
      else if (t[cnt] != '*') {
        t[++cnt] = '*';
        sz[cnt] = m;
      } else
        sz[cnt] += m;
    p[cnt + 1] = 1;
    for (i = n = cnt, cnt = 0; i; --i)
      if (t[i] == 'a')
        p[i] = p[i + 1];
      else {
        if (p[i + 1] == -1 || x / p[i + 1] < (sz[i] + 1))
          p[i] = -1;
        else
          p[i] = p[i + 1] * (sz[i] + 1);
      }
    for (i = 1; i <= n; ++i) {
      if (t[i] == 'a')
        s[++cnt] = 'a';
      else {
        if (p[i + 1] == -1)
          continue;
        else
          for (k = 1; k <= sz[i]; ++k)
            if (x > p[i + 1]) {
              s[++cnt] = 'b';
              x -= p[i + 1];
            }
      }
    }
    s[cnt + 1] = 0;
    puts(s + 1);
  }
  return 0;
}
