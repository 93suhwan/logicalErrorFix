#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int n, m, tot;
char a[2333][2333];
int res[2333], typ[2333][2333], v[2333][2333];
void addc(int x, int y) {
  if (res[x] != -1 && res[x] != y) puts("NONE"), exit(0);
  res[x] = y;
}
signed main() {
  n = read();
  for (register int i = (1); i <= (n); ++i) cin >> (a[i] + 1);
  if (n & 1) puts("NONE"), exit(0);
  for (register int _ = (1); _ <= (n / 2); ++_) {
    int i = (_ * 2 - 1);
    int x = 1, y = i, c = 0;
    ++tot;
    while (y > 1) ++x, --y, c ^= 1, typ[x][y] = tot, v[x][y] = c;
    ++x, typ[x][y] = tot, v[x][y] = c;
    while (x < n) ++x, ++y, c ^= 1, typ[x][y] = tot, v[x][y] = c;
    ++y, typ[x][y] = tot, v[x][y] = c;
    while (y < n) --x, ++y, c ^= 1, typ[x][y] = tot, v[x][y] = c;
    --x, typ[x][y] = tot, v[x][y] = c;
    while (x > 1) --x, --y, c ^= 1, typ[x][y] = tot, v[x][y] = c;
    --y, typ[x][y] = tot, v[x][y] = c;
  }
  for (register int i = (1); i <= (tot); ++i) res[i] = -1;
  for (register int i = (1); i <= (n); ++i)
    for (register int j = (1); j <= (n); ++j)
      if (a[i][j] != '.') {
        int val = (a[i][j] == 'G');
        addc(typ[i][j], (v[i][j] ^ val));
      }
  for (register int i = (1); i <= (tot); ++i)
    if (res[i] == -1) puts("MULTIPLE"), exit(0);
  puts("UNIQUE");
  for (register int i = (1); i <= (n); ++i)
    for (register int j = (1); j <= (n); ++j)
      putchar((res[typ[i][j]] ^ v[i][j]) ? 'G' : 'S'), (j == n) && (puts(""));
  return 0;
}
