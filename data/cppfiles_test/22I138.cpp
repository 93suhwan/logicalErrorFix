#include <bits/stdc++.h>
using namespace std;
namespace IO_BUFF {
const int BS = (1 << 24) + 5;
char Buffer[BS], *HD, *TL;
inline int gc() {
  if (HD == TL) TL = (HD = Buffer) + fread(Buffer, 1, BS, stdin);
  return (HD == TL) ? EOF : *HD++;
}
inline int inn() {
  int x, ch;
  while ((ch = gc()) < '0' || ch > '9')
    ;
  x = ch ^ '0';
  while ((ch = gc()) >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ '0');
  return x;
}
char ss[19999999], tt[20];
int ssl, ttl;
inline int print(int x) {
  if (x < 0) ss[++ssl] = '-', x = (-x);
  if (!x) ss[++ssl] = '0';
  for (ttl = 0; x; x /= 10) tt[++ttl] = char(x % 10 + '0');
  for (; ttl; ttl--) ss[++ssl] = tt[ttl];
  return ss[++ssl] = '\n';
}
inline int Flush() {
  return fwrite(ss + 1, sizeof(char), ssl, stdout), ssl = 0, 0;
}
int read() {
  char c = getchar();
  int x = 1;
  int s = 0;
  while (c < '0' || c > '9') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
}  // namespace IO_BUFF
using namespace IO_BUFF;
const int N = 2e5 + 5;
const int B = 400;
int n, m, x[N], y[N], lo[N], lx[N], tong[N], las[N];
int a[N], b[B + 5][N];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    x[i] = read();
    y[i] = read();
    tong[i] = n + 1;
  }
  for (int i = 1; i <= m; i++) {
    lo[i] = read();
    lx[i] = read();
  }
  for (int i = m; i >= 1; i--) {
    if (lo[i] == 1)
      las[i] = tong[lx[i]];
    else
      tong[lx[i]] = i - 1;
  }
  for (int i = 1; i <= m; i++) {
    int u = lx[i];
    if (lo[i] == 1) {
      if (x[u] + y[u] > B) {
        for (int k = i; k <= las[i]; k += (x[u] + y[u])) {
          if (k + x[u] < las[i]) {
            a[k + x[u]]++;
            a[min(k + x[u] + y[u], las[i] + 1)]--;
          }
        }
      } else {
        for (int k = i + x[u]; k <= min(las[i], i + x[u] + y[u] - 1); k++) {
          b[x[u] + y[u]][k]++;
          int fz = k + ((las[i] - k) / (x[u] + y[u]) + 1) * (x[u] + y[u]);
          if (fz > las[i] + x[u] + y[u]) fz -= (x[u] + y[u]);
          b[x[u] + y[u]][min(fz, m + 1)]--;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  for (int i = 1; i <= m; i++) {
    for (int k = 1; k <= B; k++) {
      if (i - k > 0) b[k][i] += b[k][i - k];
    }
  }
  for (int i = 1; i <= m; i++) {
    int tmp = a[i];
    for (int k = 1; k <= B; k++) {
      tmp = tmp + b[k][i];
    }
    cout << tmp << '\n';
  }
  return 0;
}
