#include <bits/stdc++.h>
using namespace std;
inline int read() {
  bool ok = 0;
  int res = 0;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    ok = 1;
  else
    res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  return ok ? ~res + 1 : res;
}
int t, n, m, k, x, y, len;
char s[110];
int main() {
  t = read();
  while (t--) {
    scanf("%s", s + 1);
    len = strlen(s + 1);
    int c1 = 0, c2 = 0;
    for (int i = 1; i < len; ++i) {
      if (s[i] == 'a' && s[i + 1] == 'b') ++c1;
      if (s[i] == 'b' && s[i + 1] == 'a') ++c2;
    }
    if (c1 != c2) {
      int cnt1 = 1, cnt2 = 1, x = 1, y = len;
      while (s[x + 1] == s[x]) ++x, ++cnt1;
      while (s[y - 1] == s[y]) --y, ++cnt2;
      if (cnt1 < cnt2) {
        for (int i = 1; i <= x; ++i) {
          if (s[i] == 'a')
            s[i] = 'b';
          else
            s[i] = 'a';
        }
      } else {
        for (int i = len; i >= y; --i) {
          if (s[i] == 'a')
            s[i] = 'b';
          else
            s[i] = 'a';
        }
      }
    }
    printf("%s\n", s + 1);
  }
  return 0;
}
