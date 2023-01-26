#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111111, mod = 998244353;
template <typename T>
inline void read(T &x) {
  x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (f) x = -x;
}
int n, k, a[maxn], rt, cnt, ch[maxn * 20][2];
void insert(int &x, int v, int dep) {
  if (!x) x = ++cnt;
  if (dep == -1) return;
  insert(ch[x][(v >> dep) & 1], v, dep - 1);
}
struct wtf {
  vector<int> s, mx, mn;
};
wtf dfs(int x, int dep) {
  if (dep == -1) {
    wtf w;
    w.s = vector<int>(1, 1e9);
    w.mx = w.mn = vector<int>(1, 0);
    return w;
  }
  int lim = (1 << dep);
  vector<int> s(lim * 2, 1e9), mx(lim * 2, 0), mn(lim * 2, 1e9);
  wtf l, r;
  for (int _ = (0); _ <= (1); _++)
    if (ch[x][_]) {
      wtf w = dfs(ch[x][_], dep - 1);
      if (_)
        r = w;
      else
        l = w;
      for (int i = (0); i <= (lim - 1); i++) {
        s[i] = min(s[i], w.s[i]);
        s[i + lim] = min(s[i + lim], w.s[i]);
        mx[i] = max(mx[i], w.mx[i] ^ (_ * lim));
        mx[i + lim] = max(mx[i + lim], w.mx[i] ^ ((_ ^ 1) * lim));
        mn[i] = min(mn[i], w.mn[i] ^ (_ * lim));
        mn[i + lim] = min(mn[i + lim], w.mn[i] ^ ((_ ^ 1) * lim));
      }
    }
  if (ch[x][0] && ch[x][1]) {
    for (int i = (0); i <= (lim - 1); i++)
      s[i] = min(s[i], r.mn[i] - l.mx[i] + lim);
    for (int i = (0); i <= (lim - 1); i++)
      s[i + lim] = min(s[i + lim], l.mn[i] - r.mx[i] + lim);
  }
  return (wtf){s, mx, mn};
}
int main() {
  read(n);
  read(k);
  for (int i = (1); i <= (n); i++) read(a[i]);
  for (int i = (1); i <= (n); i++) insert(rt, a[i], k - 1);
  vector<int> ans = dfs(rt, k - 1).s;
  for (int i = (0); i <= ((1 << k) - 1); i++) printf("%d ", ans[i]);
}
