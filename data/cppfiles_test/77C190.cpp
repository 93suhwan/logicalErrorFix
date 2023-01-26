#include <bits/stdc++.h>
int Ruusupuu;
FILE* rsp_5u;
using namespace std;
const int N = 4e6 + 10;
inline int read() {
  int w = 0;
  bool fg = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') fg |= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9')
    w = (w << 1) + (w << 3) + (ch ^ 48), ch = getchar();
  return fg ? -w : w;
}
int n, p, a[N], b[N], c[N], sum[N];
inline int A(int a, int b) { return (a + b >= p) ? (a + b - p) : (a + b); }
inline int E(int a, int b) { return (a - b < 0) ? (a - b + p) : (a - b); }
inline int T(int a, int b) { return (1ll * a * b) - ((1ll * a * b) / p) * p; }
inline int qpow(int x, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = T(ans, x);
    x = T(x, x), b >>= 1;
  }
  return ans;
}
void sc() { n = read(), p = read(); }
void work() {
  a[n] = 1;
  for (register int i = n; i >= 1; i--) {
    b[i] = A(b[i], b[i + 1]);
    a[i] = A(a[i], b[i]);
    for (register int j = 2; j * i <= n; j++) {
      int l = j * i, r = min(n, (i + 1) * j - 1);
      a[i] = A(a[i], E(sum[l], sum[r + 1]));
    }
    b[i - 1] = A(b[i - 1], a[i]);
    sum[i] = A(sum[i + 1], a[i]);
  }
  printf("%d\n", a[1]);
}
signed main() {
  sc();
  work();
  return 0;
}
