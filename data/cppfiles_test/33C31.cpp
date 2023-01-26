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
const int N = 1e5 + 5;
const int M = 513;
int f[N][M], a[N], n, m, st[N];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  m = 512;
  memset(f, 10, sizeof(f));
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < m; k++) f[i][k] = f[i - 1][k];
    f[i][a[i]] = min(f[i][a[i]], a[i]);
    for (int k = 0; k < m; k++) {
      if (f[i - 1][k] < a[i]) f[i][a[i] ^ k] = min(f[i][a[i] ^ k], a[i]);
    }
  }
  int top = 0;
  st[++top] = 0;
  for (int i = 1; i < m; i++) {
    if (f[n][i] < 1e8) {
      st[++top] = i;
    }
  }
  cout << top << endl;
  for (int i = 1; i <= top; i++) {
    cout << st[i] << " ";
  }
  return 0;
}
