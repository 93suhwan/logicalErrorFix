#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 998244353;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
int n, m, k, pw[N], cx[N][2], cy[N][2], c[2], c1, c2;
map<pair<int, int>, bool> mp;
inline void work(int x, int y, int v) {
  if (!cx[x][0] && !cx[x][1]) n += v;
  if (!cy[y][0] && !cy[y][1]) m += v;
  if (cx[x][0] && cx[x][1]) c1 += v;
  if (cy[y][0] && cy[y][1]) c2 += v;
}
inline void del(int x, int y, bool t) {
  work(x, y, -1);
  --cx[x][(y & 1) ^ t];
  --cy[y][(x & 1) ^ t];
  --c[(abs(x - y) & 1) ^ t];
  work(x, y, 1);
}
inline void ins(int x, int y, bool t) {
  work(x, y, -1);
  ++cx[x][(y & 1) ^ t];
  ++cy[y][(x & 1) ^ t];
  ++c[(abs(x - y) & 1) ^ t];
  work(x, y, 1);
}
inline void print() {
  int ans = add(c1 ? 0 : pw[n], c2 ? 0 : pw[m]);
  ans = dec(ans, (c[0] == 0) + (c[1] == 0));
  printf("%d\n", ans);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  pw[0] = 1;
  for (int i = 1; i <= max(n, m); ++i) pw[i] = add(pw[i - 1], pw[i - 1]);
  while (k--) {
    int x, y, t;
    scanf("%d%d%d", &x, &y, &t);
    auto now = make_pair(x, y);
    if (mp.count(now)) {
      del(x, y, mp[now]);
      mp.erase(now);
    }
    if (t >= 0) ins(x, y, t), mp[now] = t;
    print();
  }
  return 0;
}
