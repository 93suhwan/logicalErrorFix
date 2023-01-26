#include <bits/stdc++.h>
using namespace std;
const int N = 50;
const int inf = 1 << 30;
long long read() {
  long long a = 0;
  char b = 1, c;
  do
    if ((c = getchar()) == 45) b = -1;
  while (c < 48 || c > 57);
  do a = (a << 3) + (a << 1) + (c & 15);
  while ((c = getchar()) > 47 && c < 58);
  return a * b;
}
void write(long long x, char c) {
  if (x < 0) putchar(45), x = -x;
  char a[20], s = 0;
  do a[++s] = x % 10 | 48;
  while (x /= 10);
  do putchar(a[s]);
  while (--s);
  putchar(c);
}
int a[N], siz[N], b[N][N], q[N];
int main() {
  int m = read(), n = read();
  for (int i = 1; i <= m; ++i) a[i] = i;
  for (int i = 1; i <= n; ++i) {
    siz[i] = read();
    for (int j = 1; j <= siz[i]; ++j) b[i][j] = read();
  }
  mt19937 mtrand(time(0));
  for (int T = 1 << 15; T--;) {
    shuffle(a + 1, a + 1 + m, mtrand);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= siz[i]; ++j) q[j] = a[b[i][j]];
      sort(q + 1, q + 1 + siz[i]);
      for (int j = 1; j <= siz[i]; ++j) a[b[i][j]] = q[j];
    }
    for (int i = 2; i <= m; ++i) {
      if (a[i] ^ a[i - 1] + 1) {
        puts("REJECTED");
        return 0;
      }
    }
  }
  puts("ACCEPTED");
}
