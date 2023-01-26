#include <bits/stdc++.h>
using namespace std;
char s[200005], t[200005];
int lst[30], nxt[200005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(lst, 0, sizeof(lst));
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    if (n < m) {
      puts("NO");
      continue;
    }
    for (int i = 1; i <= n; i++)
      nxt[i] = lst[s[i] - 'a' + 1], lst[s[i] - 'a' + 1] = i;
    bool flag = true;
    for (int i = lst[t[m] - 'a' + 1]; i >= m; i = nxt[i]) {
      int lt = i;
      flag = true;
      for (int j = m - 1; j; j--) {
        int k = lst[t[j] - 'a' + 1];
        while ((k >= lt || (lt - k) % 2 == 0) && k) k = nxt[k];
        if (k <= 0) {
          flag = false;
          break;
        }
        lt = k;
      }
      if (flag) {
        puts("YES");
        break;
      }
    }
    if (!flag) puts("NO");
  }
  return 0;
}
