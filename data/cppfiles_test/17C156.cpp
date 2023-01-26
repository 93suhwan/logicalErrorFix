#include <bits/stdc++.h>
using namespace std;
char getch() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
void read(int &x) {
  x = 0;
  char c = getch();
  while (c < '0' || c > '9') c = getch();
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getch();
  }
}
const int Maxn = 50000 + 10;
int T, n;
int a[Maxn][5];
int main() {
  read(T);
  while (T--) {
    read(n);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= 5; ++j) read(a[i][j]);
    int maxn = 1;
    for (int i = 2; i <= n; ++i) {
      int tim = 0;
      for (int j = 1; j <= 5; ++j)
        if (a[i][j] < a[maxn][j]) tim++;
      if (tim >= 3) maxn = i;
    }
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
      if (i == maxn) continue;
      int tim = 0;
      for (int j = 1; j <= 5; ++j)
        if (a[i][j] < a[maxn][j]) tim++;
      if (tim >= 3) {
        flag = 1;
        break;
      }
    }
    if (!flag)
      printf("%d\n", maxn);
    else
      puts("-1");
  }
  return 0;
}
