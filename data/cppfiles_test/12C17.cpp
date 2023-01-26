#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 2005;
const int inf = 1e9;
char tmp[N];
int go[N][N];
int n, m;
long long a[N], f[N], g[N];
long long sqr(long long x) { return x * x; }
void solve(long long *dp) {
  static int q[N], ql, qr;
  ql = 1, qr = 0;
  auto slope = [&](int x, int y) {
    return (a[x] + sqr(x) - a[y] - sqr(y)) / 2. / (x - y);
  };
  for (int i = 0; i <= n; i++) {
    while (ql < qr && slope(q[qr - 1], q[qr]) >= slope(q[qr], i)) qr--;
    q[++qr] = i;
    while (ql < qr && slope(q[ql], q[ql + 1]) <= i) ql++;
    dp[i] = a[q[ql]] + sqr(i - q[ql]);
  }
}
int main() {
  n = read(), m = read();
  for (int i = 0; i <= n; i++) {
    scanf("%s", tmp);
    for (int j = 0; j <= m; j++) {
      if (tmp[j] == '1')
        go[i][j] = 0;
      else
        go[i][j] = inf;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) ckmin(go[i][j], go[i][j - 1] + 1);
    for (int j = m - 1; j >= 0; j--) ckmin(go[i][j], go[i][j + 1] + 1);
  }
  long long ans = 0;
  for (int j = 0; j <= m; j++) {
    for (int i = 0; i <= n; i++) a[i] = sqr(go[i][j]);
    solve(f);
    reverse(a, a + n + 1);
    solve(g);
    reverse(g, g + n + 1);
    for (int i = 0; i <= n; i++) {
      ans += min(f[i], g[i]);
    }
  }
  print(ans, '\n');
  return 0;
}
