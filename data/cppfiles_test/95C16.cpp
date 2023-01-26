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
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
const int N = 500010;
vector<int> a[N], lmax[N], lmin[N], rmax[N], rmin[N];
int id[N];
int n, m, dvd;
bool flag, ans[N];
int T;
int main() {
  T = read();
  for (int kase = (1); kase <= (T); ++kase) {
    bool flag = 0;
    n = read();
    m = read();
    for (int i = (1); i <= (n); ++i)
      a[i].resize(m + 1), lmax[i].resize(m + 1), rmax[i].resize(m + 1),
          lmin[i].resize(m + 1), rmin[i].resize(m + 1);
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (m); ++j)
        a[i][j] = lmax[i][j] = rmax[i][j] = lmin[i][j] = rmin[i][j] = read();
    for (int i = (1); i <= (n); ++i)
      for (int j = (2); j <= (m); ++j)
        lmax[i][j] = max(lmax[i][j - 1], lmax[i][j]),
        lmin[i][j] = min(lmin[i][j - 1], lmin[i][j]);
    for (int i = (1); i <= (n); ++i)
      for (int j = (m - 1); j >= (1); --j)
        rmax[i][j] = max(rmax[i][j + 1], rmax[i][j]),
        rmin[i][j] = min(rmin[i][j + 1], rmin[i][j]);
    for (int j = (1); j <= (m - 1); ++j) {
      if (flag) break;
      for (int i = (1); i <= (n); ++i) id[i] = i;
      sort(id + 1, id + n + 1,
           [&](int x, int y) { return (lmin[x][j] < lmin[y][j]); });
      vector<int> rmx;
      rmx.resize(n + 1);
      for (int i = (1); i <= (n); ++i) rmx[i] = rmax[i][j + 1];
      for (int i = (n - 1); i >= (1); --i)
        rmx[id[i]] = max(rmx[id[i]], rmx[id[i + 1]]);
      int prelmax = 0, prermin = (int)2e9;
      for (int ii = (1); ii <= (n - 1); ++ii) {
        int i = id[ii];
        prelmax = max(prelmax, lmax[i][j]);
        prermin = min(prermin, rmin[i][j + 1]);
        if (prelmax < lmin[id[ii + 1]][j] && prermin > rmx[id[ii + 1]]) {
          flag = 1;
          for (int i = (1); i <= (n); ++i) ans[i] = 1;
          for (int i = (1); i <= (ii); ++i) ans[id[i]] = 0;
          dvd = j;
          break;
        }
      }
    }
    if (flag) {
      puts("YES");
      for (int i = (1); i <= (n); ++i) putchar(ans[i] ? 'R' : 'B');
      putchar(32);
      write(dvd);
      putchar(10);
    } else
      puts("NO");
    for (int i = (1); i <= (n); ++i)
      a[i].clear(), lmax[i].clear(), lmin[i].clear(), rmax[i].clear(),
          rmin[i].clear();
    for (int i = (1); i <= (n); ++i)
      a[i].clear(), lmax[i].clear(), rmax[i].clear(), lmin[i].clear(),
          rmin[i].clear();
  }
}
