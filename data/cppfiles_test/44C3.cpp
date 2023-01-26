#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int X = 0;
  bool fl = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fl = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (fl) return ~(X - 1);
  return X;
}
char buf[1 << 21], ccc[20];
int pu, p2 = -1;
void flush() {
  fwrite(buf, 1, p2 + 1, stdout);
  p2 = -1;
}
void puc(char ch) {
  buf[++p2] = ch;
  if (p2 > 1 << 20) flush();
}
void pus(string k) {
  for (int i = 0; i < (int)k.size(); i++) buf[++p2] = k[i];
  if (p2 > 1 << 20) flush();
}
void write(int x) {
  if (p2 > 1 << 20) flush();
  if (x < 0) buf[++p2] = 45, x = -x;
  do {
    ccc[++pu] = (x % 10) | 48;
  } while (x /= 10);
  do {
    buf[++p2] = ccc[pu];
  } while (--pu);
}
int n, s[2005][2005], p[2005][2005], c[2005], ans[2005][2005];
int id[2005][2005];
int Gec() {
  char ch = getchar();
  while (ch != '.' && ch != 'S' && ch != 'G') ch = getchar();
  if (ch == '.') return -1;
  if (ch == 'S') return 1;
  return 0;
}
signed main() {
  n = read();
  if (n & 1) {
    pus("NONE\n");
    flush();
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) s[i][j] = Gec();
  for (int i = 0; i < n / 2; i++) {
    int x = i * 2, y = -1;
    ++y;
    while (x < n && y < n && x > -1 && y > -1) p[x][y] = i, --x, ++y;
    ++x;
    while (x < n && y < n && x > -1 && y > -1) p[x][y] = i, ++x, ++y;
    --y;
    while (x < n && y < n && x > -1 && y > -1) p[x][y] = i, ++x, --y;
    --x;
    while (x < n && y < n && x > -1 && y > -1) p[x][y] = i, --x, --y;
  }
  bool flg = 1;
  for (int i = 0; i < n; i += 2) {
    bool fl = flg;
    for (int j = 0; j < n; j += 2) {
      id[i][j] = id[i + 1][j] = id[i][j + 1] = id[i + 1][j + 1] = fl;
      fl ^= 1;
    }
    flg ^= 1;
  }
  memset(c, 0x3f3f3f3f, sizeof c);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (s[i][j] > -1) {
        int u = s[i][j] ^ id[i][j];
        if (c[p[i][j]] != 0x3f3f3f3f && u != c[p[i][j]]) {
          pus("NONE\n");
          flush();
          return 0;
        }
        c[p[i][j]] = u;
      }
    }
  for (int i = 0; i < n / 2; i++)
    if (c[i] >= 0x3f3f3f3f) {
      pus("MULTIPLE\n");
      flush();
      return 0;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans[i][j] = c[p[i][j]] ^ id[i][j];
  pus("UNIQUE\n");
  for (int i = 0; i < n; i++, puc('\n'))
    for (int j = 0; j < n; j++) puc(ans[i][j] ? 'S' : 'G');
  flush();
}
