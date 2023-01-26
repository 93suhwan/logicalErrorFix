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
char a[101], b[101];
int main() {
  T = read();
  while (T--) {
    n = read();
    scanf("%s%s", a + 1, b + 1);
    for (register int i = 1; i <= n; ++i)
      if (a[i] == '1' && b[i] == '1') {
        puts("NO");
        goto over;
      }
    puts("YES");
  over:;
  }
  return 0;
}
