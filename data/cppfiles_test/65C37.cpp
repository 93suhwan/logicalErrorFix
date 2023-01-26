#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * w;
}
const int maxn = 2e5 + 50;
int n, a[maxn], pre[maxn], ans[maxn];
char ch[maxn];
char str[maxn];
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  scanf("%s", str + 1);
  for (int l = 1, r = n; l <= r;) {
    int p = r - l + 1;
    ans[p] = (str[p] == str[p - 1] ? l++ : r--);
  }
  for (int i = n, p = n; i >= 1; i--) {
    p = min(p, i);
    while (p && str[p] == str[i]) p--;
    p++;
    pre[i] = p;
  }
  int cnt[2] = {0};
  for (int i = 1; i <= n; i++) {
    if (i == pre[i]) {
      printf("%d %c\n", a[ans[i]], str[i] == 'L' ? 'L' : 'R');
      cnt[str[i] == 'R']++;
      continue;
    }
    int ty = (str[i] == 'R');
    if (cnt[ty] == cnt[ty ^ 1]) {
      printf("%d %c\n", a[ans[i]], ty == 1 ? 'R' : 'L'), cnt[ty]++;
    } else
      printf("%d %c\n", a[ans[i]], ty == 1 ? 'L' : 'R'), cnt[ty ^ 1]++;
  }
  return 0;
}
