#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
bool vis[N];
struct Node {
  int xx, yy, tim, id;
} p[N];
int n, k;
vector<int> to[N];
inline int Read() {
  char ch;
  int f = 1;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') f = -1;
  int x = ch ^ 48;
  while ((ch = getchar()) >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void Print(const int x, const char ch = '\n', const bool flg = 1) {
  if (x < 0) {
    putchar('-');
    return Print(-x, ch, flg);
  }
  if (x >= 10) Print(x / 10, ch, 0);
  putchar(x % 10 + 48);
  if (flg) putchar(ch);
  return;
}
inline void Dfs(const int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (register int i = 0; i < to[u].size(); i++) {
    int v = to[u][i];
    Dfs(v);
  }
  return;
}
inline bool Check(const int mid) {
  int j = 1;
  for (register int i = 1; i <= n; i++) vis[i] = 0;
  while (j <= n && p[j].tim <= mid) Dfs(p[j++].id);
  while (j <= n && vis[p[j].id]) j++;
  if (j > n) return 1;
  for (register int i = 0; i <= mid; i++) {
    Dfs(p[j].id);
    while (j <= n && vis[p[j].id]) j++;
    if (j > n) return 1;
  }
  return 0;
}
inline bool Cmp(const Node x, const Node y) { return x.tim < y.tim; }
inline bool Cmp1(const Node x, const Node y) {
  return x.xx < y.xx || (x.xx == y.xx && x.yy < y.yy);
}
inline bool Cmp2(const Node x, const Node y) {
  return x.yy < y.yy || (x.yy == y.yy && x.xx < y.xx);
}
inline void Init() {
  n = Read();
  k = Read();
  for (register int i = 1; i <= n; i++) {
    p[i].xx = Read();
    p[i].yy = Read();
    p[i].tim = Read();
    p[i].id = i;
    to[i].clear();
  }
  sort(p + 1, p + n + 1, Cmp1);
  for (register int i = 1; i <= n; i++) {
    if (i > 1 && p[i].xx == p[i - 1].xx && p[i].yy - p[i - 1].yy <= k)
      to[p[i].id].push_back(p[i - 1].id);
    if (i < n && p[i].xx == p[i + 1].xx && p[i + 1].yy - p[i].yy <= k)
      to[p[i].id].push_back(p[i + 1].id);
  }
  sort(p + 1, p + n + 1, Cmp2);
  for (register int i = 1; i <= n; i++) {
    if (i > 1 && p[i].yy == p[i - 1].yy && p[i].xx - p[i - 1].xx <= k)
      to[p[i].id].push_back(p[i - 1].id);
    if (i < n && p[i].yy == p[i + 1].yy && p[i + 1].xx - p[i].xx <= k)
      to[p[i].id].push_back(p[i + 1].id);
  }
  sort(p + 1, p + n + 1, Cmp);
  return;
}
int ll, rr;
inline void Solve() {
  ll = 0, rr = n;
  while (ll < rr) {
    int mid = ll + rr >> 1;
    if (Check(mid))
      rr = mid;
    else
      ll = mid + 1;
  }
  Print(ll);
  return;
}
int T;
int main() {
  for (T = Read(); T; T--) {
    Init();
    Solve();
  }
  return 0;
}
