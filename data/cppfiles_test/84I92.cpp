#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, sgn = 0;
  char s = getchar();
  while (!isdigit(s)) sgn |= s == '-', s = getchar();
  while (isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(long long x) {
  if (x < 0)
    putchar('-'), print(-x);
  else {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
  }
}
template <class T>
void cmin(T &a, T b) {
  a = a < b ? a : b;
}
template <class T>
void cmax(T &a, T b) {
  a = a > b ? a : b;
}
const int N = 1e5 + 5;
const int K = 18;
long long T, n, k, f[K][N];
long long cst(long long l, long long r) {
  return (r / l) * (r / l - 1) / 2 + r - l + 1;
}
void solve(int l, int r, int pl, int pr, long long *f, long long *g) {
  int m = l + r >> 1, lim = min(pr, m - 1), p = pl;
  g[m] = f[pl] + cst(pl + 1, m);
  for (int i = pl + 1; i <= lim; i++)
    if (f[i] + cst(i + 1, m) < g[m]) g[m] = f[i] + cst(i + 1, m), p = i;
  if (l < m) solve(l, m - 1, max(0, pl - 10), min(m - 2, p + 10), f, g);
  if (m < r) solve(m + 1, r, max(0, p - 10), min(r - 1, pr + 10), f, g);
}
int main() {
  memset(f[0], 0x3f, sizeof(f[0][0]) * (N)), f[0][0] = 0, cin >> T;
  for (int i = 1; i < K; i++) solve(1, N - 1, 0, N - 2, f[i - 1], f[i]);
  while (T--) {
    cin >> n >> k;
    if (k >= K)
      cout << n << endl;
    else if (n <= (1 << k) - 1)
      cout << n << endl;
    else
      cout << f[k][n] << endl;
  }
  return 0;
}
