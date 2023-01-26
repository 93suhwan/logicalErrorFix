#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
char s[MAXN];
int main() {
  int tn, n, m, sn, ans[2];
  scanf("%d", &tn);
  while (tn--) {
    scanf("%d%d%s", &n, &m, s);
    ans[0] = ans[1] = 1;
    sn = strlen(s);
    for (int i = 0, r = 0, c = 0, r0 = 0, r1 = 0, c0 = 0, c1 = 0; i < sn; ++i) {
      switch (s[i]) {
        case 'L':
          --c;
          c0 = min(c0, c);
          break;
        case 'R':
          ++c;
          c1 = max(c1, c);
          break;
        case 'U':
          --r;
          r0 = min(r0, r);
          break;
        case 'D':
          ++r;
          r1 = max(r1, r);
          break;
        default:
          break;
      }
      if (r1 - r0 + 1 <= n && c1 - c0 + 1 <= m)
        ans[0] = 1 - r0, ans[1] = 1 - c0;
      else
        break;
    }
    printf("%d %d\n", ans[0], ans[1]);
  }
  return 0;
}
