#include <bits/stdc++.h>
using namespace std;
int n, m, b[15], a[15][45];
unsigned long long st[2][10000005];
bool vs[45];
int main() {
  scanf("%d %d", &n, &m);
  if (n == 1) {
    puts("ACCEPTED");
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    for (int j = 1; j <= b[i]; ++j) scanf("%d", &a[i][j]);
  }
  st[0][++st[0][0]] = 0;
  for (int i = 1, fl = 1; i <= m; ++i, fl ^= 1) {
    while (st[fl ^ 1][0]) {
      int cnt = 0;
      unsigned long long t = st[fl ^ 1][st[fl ^ 1][0]--];
      for (int j = 1; j <= b[i]; ++j) cnt += t >> a[i][j] - 1 & 1;
      for (int j = 1; j <= b[i] - cnt; ++j)
        t &= (1ull << n) - (1ull << a[i][j] - 1) - 1;
      for (int j = b[i]; j > b[i] - cnt; --j) t |= 1ull << a[i][j] - 1;
      st[fl][++st[fl][0]] = t;
      for (int j = b[i] - cnt; j; --j)
        if (!(t >> a[i][j] - 1 & 1)) {
          if (vs[a[i][j]]) break;
          t |= 1ull << a[i][j] - 1, st[fl][++st[fl][0]] = t;
        }
    }
    for (int j = 1; j <= b[i]; ++j) vs[a[i][j]] = 1;
  }
  for (int i = 1; i <= n; ++i)
    if (!vs[i]) {
      puts("REJECTED");
      return 0;
    }
  while (st[m & 1][0]) {
    unsigned long long t = st[m & 1][st[m & 1][0]--];
    for (int i = 1; i < n; ++i)
      if (t >> i - 1 & 1 && !(t >> i & 1)) {
        puts("REJECTED");
        return 0;
      }
  }
  puts("ACCEPTED");
  return 0;
}
