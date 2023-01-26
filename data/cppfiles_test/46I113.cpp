#include <bits/stdc++.h>
using namespace std;
int n, x, p;
long long ans, f[1005];
struct node {
  int id, cnt;
} s[1005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if (i & 1)
      s[++p] = {i, x};
    else {
      while (p && x >= s[p].cnt) {
        f[i] += f[s[p].id - 1];
        ans += f[s[p].id - 1] + s[p].cnt;
        x -= s[p--].cnt;
      }
      if (p && x) ans += x, s[p].cnt -= x, x = 0;
      if (x)
        f[i] = 0;
      else
        ++f[i];
    }
  }
  printf("%lld", ans);
  return 0;
}
