#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, P = 998244353;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m, k, pw[N];
int l[2][N], h[2][N], cntl, cnth, totl, toth, lim[2];
struct PT {
  int x, y;
  PT(int _x, int _y) {
    x = _x;
    y = _y;
  }
  bool operator<(const PT &q) const {
    if (x != q.x) return x < q.x;
    return y < q.y;
  }
};
map<PT, int> F;
void change(int x, int y, int col, int k) {
  if (l[0][x] || l[1][x]) --totl;
  if (l[0][x] && l[1][x]) --cntl;
  if (h[0][y] || h[1][y]) --toth;
  if (h[0][y] && h[1][y]) --cnth;
  lim[(col) ^ ((x + y) & 1)] += k;
  if (y & 1)
    l[col][x] += k;
  else
    l[col ^ 1][x] += k;
  if (x & 1)
    h[col][y] += k;
  else
    h[col ^ 1][y] += k;
  if (l[0][x] || l[1][x]) ++totl;
  if (l[0][x] && l[1][x]) ++cntl;
  if (h[0][y] || h[1][y]) ++toth;
  if (h[0][y] && h[1][y]) ++cnth;
}
int main() {
  n = read();
  m = read();
  k = read();
  pw[0] = 1;
  for (int i = 1; i <= max(n, m); ++i) pw[i] = (pw[i - 1] + pw[i - 1]) % P;
  for (int i = 1; i <= k; ++i) {
    int x = read(), y = read(), tp = read();
    if (tp == -1) {
      int nw = F[PT(x, y)];
      if (nw) {
        F[PT(x, y)] = 0;
        change(x, y, nw - 1, -1);
      }
    } else {
      int nw = F[PT(x, y)];
      if (nw) change(x, y, nw - 1, -1);
      F[PT(x, y)] = tp + 1;
      change(x, y, tp, 1);
    }
    int res = 0;
    if (!cnth) res += pw[m - toth];
    if (!cntl) res += pw[n - totl];
    printf("%d\n", (res - (lim[0] == 0) - (lim[1] == 0)) % P);
  }
  return 0;
}
