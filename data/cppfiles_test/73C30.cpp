#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 7e5 + 5e4 + 7;
constexpr int inf = 0x3f3f3f3f;
int n, m;
struct Edge {
  int u, v;
} edge[500007];
int vis[maxn];
template <typename T, const size_t MAX = 300007>
class Link_Cut_Tree {
 public:
  inline void addtag(int rt, int x) {
    tag[rt] = x;
    if (rt > n) cov[rt] = x;
    if (is[rt]) has[rt] = x;
  }
  T cov[MAX], tag[MAX], has[MAX], is[MAX];
  int sta[MAX], top;
  inline void clear(int N) {
    for (int i = 0; i <= N; ++i) {
      cov[i] = tag[i] = has[i] = 0;
      is[i] = 0;
      tag[i] = -1;
      revtag[i] = 0;
      son[i][0] = son[i][1] = Fa[i] = 0;
    }
  }
  inline void Splay(int x) {
    int y = x;
    top = 0;
    sta[++top] = y;
    while (!isroot(y)) {
      sta[++top] = Fa[y];
      y = Fa[y];
    }
    while (top) push_down(sta[top--]);
    while (!isroot(x)) {
      y = Fa[x];
      int z = Fa[y];
      if (!isroot(y)) Rotate((chk(x) ^ chk(y)) ? x : y);
      Rotate(x);
    }
  }
  inline void makeroot(int x) {
    Access(x);
    Splay(x);
    Rev(x);
  }
  inline void Split(int x, int y) {
    makeroot(x);
    Access(y);
    Splay(y);
  }
  inline void Link(int x, int y) {
    makeroot(x);
    if (findroot(y) != x) Fa[x] = y;
  }
  inline void cut(int x, int y) {
    makeroot(x);
    if (findroot(y) == x && Fa[y] == x && !son[y][0]) {
      Fa[y] = son[x][1] = 0;
      push_up(x);
    }
  }
  inline void push_up(int x) {
    is[x] = (is[son[x][0]] | is[son[x][1]] | (x > n));
    has[x] = (has[son[x][0]] | has[son[x][1]] | cov[x]);
  }
  inline bool same(int u, int v) {
    makeroot(u);
    return findroot(v) == u;
  }

 private:
  int Fa[MAX], son[MAX][2], revtag[MAX];
  inline bool isroot(int x) { return son[Fa[x]][0] != x && son[Fa[x]][1] != x; }
  inline void Rev(int x) {
    swap(son[x][0], son[x][1]);
    revtag[x] ^= 1;
  }
  inline void push_down(int x) {
    if (revtag[x]) {
      if (son[x][0]) Rev(son[x][0]);
      if (son[x][1]) Rev(son[x][1]);
      revtag[x] ^= 1;
    }
    if (tag[x] != -1) {
      if (son[x][0]) addtag(son[x][0], tag[x]);
      if (son[x][1]) addtag(son[x][1], tag[x]);
      tag[x] = -1;
    }
  }
  inline int chk(int x) { return son[Fa[x]][1] == x; }
  inline void Rotate(int x) {
    int y = Fa[x], z = Fa[y];
    int sx = chk(x), sy = chk(y), s = son[x][sx ^ 1];
    if (!isroot(y)) {
      son[z][sy] = x;
    }
    son[x][sx ^ 1] = y;
    son[y][sx] = s;
    if (s) Fa[s] = y;
    Fa[y] = x;
    Fa[x] = z;
    push_up(y);
    push_up(x);
  }
  inline void Access(int x) {
    for (int y = 0; x; x = Fa[y = x]) {
      Splay(x);
      son[x][1] = y;
      push_up(x);
    }
  }
  inline int findroot(int x) {
    Access(x);
    Splay(x);
    while (son[x][0]) {
      push_down(x);
      x = son[x][0];
    }
    Splay(x);
    return x;
  }
};
Link_Cut_Tree<int, maxn> LCT;
inline bool addedge(int pos) {
  int u = edge[pos].u, v = edge[pos].v;
  if (LCT.same(u, v)) {
    LCT.Split(u, v);
    if (LCT.has[v]) return false;
    LCT.addtag(v, pos);
    return true;
  } else {
    vis[pos] = 1;
    LCT.Link(u, pos + n);
    LCT.Link(pos + n, v);
    return true;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  ll ret = 0;
  LCT.clear(n + m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &edge[i].u, &edge[i].v);
    LCT.is[i + n] = 1;
  }
  int r = 0;
  for (int i = 1; i <= m; ++i) {
    while (r < m && addedge(r + 1)) ++r;
    ret += r - i + 1;
    if (vis[i]) {
      int pos = i + n;
      LCT.Split(pos, pos);
      if (LCT.cov[pos]) {
        int id = LCT.cov[pos];
        LCT.Split(edge[id].u, edge[id].v);
        LCT.addtag(edge[id].v, 0);
        LCT.cut(edge[i].u, i + n);
        LCT.cut(edge[i].v, i + n);
        LCT.Link(edge[id].u, id + n);
        LCT.Link(edge[id].v, id + n);
        vis[id] = 1;
      } else {
        LCT.cut(i + n, edge[i].u);
        LCT.cut(i + n, edge[i].v);
      }
    } else {
      LCT.Split(edge[i].u, edge[i].v);
      LCT.addtag(edge[i].v, 0);
    }
  }
  printf("%lld\n", ret);
  return 0;
}
