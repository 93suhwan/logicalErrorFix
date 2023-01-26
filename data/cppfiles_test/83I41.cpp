#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
inline void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 ^ 48);
}
string a;
int t, n, b[5005], f[5005], g[5005][5010], tmp, tmp1, gac[5005], y[5005],
    h[5005], sb[5005], maxn;
inline void work() {
  memset(h, 0, sizeof(h));
  for (register int i = 1; i <= tmp; ++i) {
    h[gac[i]]++;
  }
  for (register int i = 1; i <= tmp1; ++i) {
    h[i] += h[i - 1];
  }
  for (register int i = tmp; i >= 1; --i) {
    y[h[gac[sb[i]]]--] = sb[i];
  }
}
inline void workall() {
  tmp1 = 75;
  for (register int i = 1; i <= tmp; ++i) {
    gac[i] = a[i - 1] - '0' + 1;
    sb[i] = i;
  }
  work();
  for (register int yy = 1, kk = 0; yy < tmp; tmp1 = yy, yy *= 2) {
    kk = 0;
    for (register int i = 1; i <= yy; ++i) {
      kk++;
      sb[kk] = tmp - yy + i;
    }
    for (register int i = 1; i <= tmp; ++i) {
      if (y[i] > yy) {
        kk++;
        sb[kk] = y[i] - yy;
      }
    }
    work();
    swap(sb, gac);
    gac[y[1]] = 1;
    kk = 1;
    for (register int i = 2; i <= tmp; ++i) {
      if (sb[y[i - 1]] == sb[y[i]] && sb[y[i - 1] + yy] == sb[y[i] + yy]) {
        gac[y[i]] = kk;
      } else {
        kk++;
        gac[y[i]] = kk;
      }
    }
  }
}
void clean() {
  memset(f, 0, sizeof(f));
  memset(b, 0, sizeof(b));
  memset(g, 0, sizeof(f));
  memset(y, 0, sizeof(y));
  memset(gac, 0, sizeof(gac));
  memset(h, 0, sizeof(h));
  memset(sb, 0, sizeof(sb));
}
void workalltime() {
  clean();
  int mans = 0;
  n = read();
  cin >> a;
  tmp = n;
  workall();
  for (int i = 0; i < n; i++) b[y[i + 1] - 1] = i;
  for (register int i = n - 1; i >= 0; i--) {
    for (register int j = n - 1; j >= 0; j--) {
      if (a[i] != a[j])
        g[i][j] = 0;
      else
        g[i][j] = g[i + 1][j + 1] + 1;
    }
  }
  maxn = n;
  f[0] = n;
  for (register int i = 1; i < n; ++i) {
    f[i] = n - i;
    for (register int j = 0; j < i; ++j) {
      if (b[i] > b[j]) {
        if (f[i] < f[j] + n - i - g[i][j]) {
          f[i] = f[j] + n - i - g[i][j];
        }
      }
    }
    if (f[i] > maxn) {
      maxn = f[i];
    }
  }
  print(maxn), puts("");
  int ende = 0;
  return;
}
int main() {
  cin >> t;
  while (t--) {
    workalltime();
  }
  return 0;
}
