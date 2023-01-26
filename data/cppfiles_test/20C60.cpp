#include <bits/stdc++.h>
inline long long read() {
  long long x = 0;
  bool flag = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') flag = 1, ch = getchar();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  if (flag) x = -x;
  return x;
}
inline long long qabs(long long x) { return x < 0 ? -x : x; }
inline long long qpow(long long x, int y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % 1000000007;
    x = x * x % 1000000007;
    y >>= 1;
  }
  return ret;
}
struct edge {
  int nxt, v;
} e[405 << 1];
int head[405], tot;
void addedge(int u, int v) {
  e[++tot] = (edge){head[u], v};
  head[u] = tot;
}
int n, m, a[405][405], s[405][405], b[405], c[405];
char s1[405][405];
int q[405];
int main() {
  int T = read();
  while (T--) {
    n = read();
    m = read();
    for (int i = (1); i <= (n); ++i) scanf("%s", s1[i] + 1);
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (m); ++j) a[i][j] = s1[i][j] == '1';
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (m); ++j) s[i][j] = s[i - 1][j] + a[i][j];
    int ans = n * m;
    for (int l = (1); l <= (n); ++l)
      for (int r = (l + 4); r <= (n); ++r) {
        int min = 1000000007;
        for (int i = (1); i <= (m); ++i) {
          b[i] = s[r - 1][i] - s[l][i] + (a[l][i] == 0) + (a[r][i] == 0);
          c[i] = r - l - 1 - (s[r - 1][i] - s[l][i]);
        }
        int cur = 0;
        for (int i = (2); i <= (m - 1); ++i) {
          cur += b[i];
          if (i >= 3) {
            min = std::min(cur + c[i - 2], min + b[i]);
            ans = std::min(ans, min + c[i + 1]);
            cur -= b[i - 1];
          }
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
