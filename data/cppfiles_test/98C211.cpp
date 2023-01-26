#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int f = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
int t, n;
char s[55];
signed main() {
  t = read();
  while (t--) {
    n = read();
    scanf("%s", s + 1);
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
      int cnta = 0, cntb = 0;
      for (int j = i; j <= n; j++) {
        cnta += s[j] == 'a';
        cntb += s[j] == 'b';
        if (cnta == cntb) {
          printf("%d %d\n", i, j);
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) puts("-1 -1");
  }
  return 0;
}
