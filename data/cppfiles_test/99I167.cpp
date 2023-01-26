#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
char s[maxn];
int a[maxn][maxn];
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
    int n;
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) a[i][j] = 0;
    int pre = 0, l = 0, num = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '1') continue;
      num++;
      if (!l) l = i;
      a[i][pre] = 1, a[pre][i] = -1;
      pre = i;
    }
    a[l][pre] = 1, a[pre][l] = -1;
    if (num == 1) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= n; i++, puts("")) {
      for (int j = 1; j <= n; j++) {
        if (i == j)
          putchar('X');
        else if (a[i][j] == 0)
          putchar('=');
        else if (a[i][j] == 1)
          putchar('+');
        else
          putchar('-');
      }
    }
  }
  return 0;
}
