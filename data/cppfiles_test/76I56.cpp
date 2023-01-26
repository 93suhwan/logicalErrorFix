#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int nnu[25];
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) {
    putchar('0');
    return;
  }
  int tp = 0;
  while (x) nnu[++tp] = x % 10, x /= 10;
  while (tp) putchar(nnu[tp--] + '0');
  return;
}
unordered_map<int, int> vis[500005];
mt19937 rnd(time(0));
int id[500005];
vector<int> an;
inline int rd(int l, int r) { return rnd() % (r - l + 1) + l; }
inline bool check(int x) {
  for (int i : an)
    if (!vis[i][x]) return 0;
  return 1;
}
inline bool judge(int x) {
  for (int i : an)
    if (vis[i][x]) return 0;
  return 1;
}
signed main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    vis[x][y] = vis[y][x] = 1;
  }
  if (n < 5) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) id[i] = i;
  for (int u = 1; u <= 20; u++) {
    for (int i = 1; i <= n; i++) swap(id[i], id[rd(i, n)]);
    int m = 0;
    for (int i = 1; i <= n; i++) {
      if (check(i)) m++, an.push_back(i);
      if (m == 5) {
        for (int j : an) write(j), putchar(' ');
        return 0;
      }
    }
    an.clear();
  }
  for (int u = 1; u <= 20; u++) {
    for (int i = 1; i <= n; i++) swap(id[i], id[rd(i, n)]);
    int m = 0;
    for (int i = 1; i <= n; i++) {
      if (judge(i)) m++, an.push_back(i);
      if (m == 5) {
        for (int j : an) write(j), putchar(' ');
        return 0;
      }
    }
    an.clear();
  }
  puts("-1");
}
