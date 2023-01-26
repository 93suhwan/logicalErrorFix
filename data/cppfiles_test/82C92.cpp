#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
char s[maxn];
int sum[maxn];
set<int> t[4 * maxn];
int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') y = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * y;
}
int main() {
  int T;
  T = read();
  while (T--) {
    int n, q;
    n = read();
    q = read();
    scanf("%s", s + 1);
    for (int i = 0; i <= 4 * n; i++) t[i].clear();
    for (int i = 1; i <= n; i++) {
      int x = (s[i] == '+' ? 0 : 1);
      x ^= ((i & 1) ^ 1);
      if (!x)
        sum[i] = sum[i - 1] + 1;
      else
        sum[i] = sum[i - 1] - 1;
      t[sum[i] + sum[i - 1] + 2 * n].insert(i);
    }
    for (int i = 1; i <= q; i++) {
      int l, r;
      l = read();
      r = read();
      if (sum[r] == sum[l - 1])
        puts("0");
      else if ((r - l + 1) & 1) {
        puts("1");
        printf("%d\n", *t[sum[r] + sum[l - 1] + 2 * n].lower_bound(l));
      } else {
        puts("2");
        printf("%d %d\n", *t[sum[r - 1] + sum[l - 1] + 2 * n].lower_bound(l),
               r);
      }
    }
  }
  return 0;
}
