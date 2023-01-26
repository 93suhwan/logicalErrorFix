#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int nnu[25];
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) {
    putchar('0');
    return;
  }
  int tp = 0;
  while (x) nnu[++tp] = x % 10, x /= 10;
  while (tp) putchar(nnu[tp--] + '0');
  return;
}
char s[500005];
int a[500005];
signed main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  scanf("%s", s + 1);
  int X = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] != s[i - 1]) X++;
  int L = 0, R = n - X;
  int pos = s[1] == 'L';
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] != s[i - 1])
      write(a[++R]), putchar(' '), putchar(s[i]), putchar('\n');
    else
      write(a[++L]), putchar(' '), putchar(pos ? 'R' : 'L'), pos ^= 1,
          putchar('\n');
}
