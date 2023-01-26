#include <bits/stdc++.h>
using namespace std;
const int MAXN = 7e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
struct EDGE {
  int head[MAXN], siz;
  int nxt[MAXN << 1], to[MAXN << 1], id[MAXN << 1];
  void add(int x, int y, int i) {
    nxt[++siz] = head[x];
    to[siz] = y, id[siz] = i, head[x] = siz;
  }
} e;
int n, m, q;
int ind[MAXN], _a[MAXN], _b[MAXN];
bool vis[MAXN];
vector<int> G[MAXN], GG[MAXN];
vector<int> Ans[MAXN];
template <typename T>
inline bool read(T &a) {
  a = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + (c ^ 48);
    c = getchar();
  }
  return a *= f, true;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
void findTree(int x) {
  if (vis[x]) return;
  vis[x] = true;
  for (auto to : GG[x]) {
    if (vis[to]) continue;
    G[x].push_back(to), G[to].push_back(x);
    findTree(to);
  }
}
bool DFS(int x, int f, int g, int id) {
  if (x == g) {
    Ans[id].push_back(x);
    return true;
  }
  for (auto to : G[x]) {
    if (to == f) continue;
    if (DFS(to, x, g, id)) {
      Ans[id].push_back(x);
      return true;
    }
  }
  return false;
}
void get(int x, int y, int i) { DFS(x, 0, y, i); }
void Go(int x) {
  ind[x] = 0;
  for (int &i = e.head[x]; i; i = e.nxt[i]) {
    if (vis[i]) continue;
    vis[i] = vis[i ^ 1] = true;
    get(x, e.to[i], e.id[i]);
    Go(e.to[i]);
  }
}
signed main() {
  read(n), read(m);
  e.siz = 1;
  for (int i = 1, x, y; i <= m; ++i) {
    read(x), read(y);
    GG[x].push_back(y), GG[y].push_back(x);
  }
  findTree(1);
  read(q);
  for (int i = 1, a, b; i <= q; ++i) {
    read(a), read(b);
    _a[i] = a, _b[i] = b;
    ind[a]++, ind[b]++;
    e.add(a, b, i), e.add(b, a, i);
  }
  int oddcnt = 0;
  for (int i = 1; i <= n; ++i)
    if (ind[i] & 1) oddcnt++;
  if (oddcnt) {
    puts("NO");
    assert(oddcnt % 2 == 0);
    printf("%d\n", (oddcnt >> 1));
    return 0;
  }
  puts("YES");
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; ++i) {
    if (!ind[i]) continue;
    Go(i);
  }
  for (int i = 1; i <= q; ++i) {
    if (Ans[i][0] != _a[i]) reverse(Ans[i].begin(), Ans[i].end());
    printf("%ld\n", Ans[i].size());
    for (auto x : Ans[i]) printf("%d ", x);
    putchar('\n');
  }
  return 0;
}
