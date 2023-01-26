#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int res = 0, flag = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * flag;
}
int T, n;
char s[100001];
int main() {
  T = read();
  while (T--) {
    n = read();
    scanf("%s", s + 1);
    int ans = (1e9);
    for (register int i = 0; i <= 25; ++i) {
      int l = 1, r = n, res = 0;
      while (l <= r) {
        if (s[l] == s[r])
          ++l, --r;
        else if (s[l] == 'a' + i)
          ++res, ++l;
        else if (s[r] == 'a' + i)
          ++res, --r;
        else {
          res = (1e9);
          break;
        }
      }
      (ans = min(ans, res));
    }
    if (ans > n)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  return 0;
}
