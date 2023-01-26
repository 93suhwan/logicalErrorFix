#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void chkmin(T &x, T y) {
  if (x > y) x = y;
}
namespace orzjk {
const int SZ = 1e6;
char buf[SZ], *p1 = buf, *p2 = buf;
char nc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SZ, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
char fub[SZ], *p3 = fub, *p4 = fub + SZ;
void pc(char c) {
  p3 == p4 && (fwrite(fub, 1, SZ, stdout), p3 = fub);
  *p3++ = c;
}
void flush() { fwrite(fub, 1, p3 - fub, stdout), p3 = fub; }
}  // namespace orzjk
using orzjk::nc;
using orzjk::pc;
int read() {
  int x = 0, f = 1;
  char c = nc();
  while (c < 48) c == '-' && (f = -1), c = nc();
  while (c > 47) x = x * 10 + (c ^ 48), c = nc();
  return x * f;
}
void write(int x) {
  static char st[11];
  if (!x) return pc(48), void();
  char *p = st;
  if (x < 0) x = -x, pc('-');
  for (; x; x /= 10) *p++ = x % 10 | 48;
  do {
    pc(*--p);
  } while (p != st);
}
int n, A[1 << 19];
bool flg[1 << 19];
set<int> unu;
struct node {
  int px, py;
};
vector<node> dir, ind;
bool vis_ind[1 << 19];
bool vis_dir[1 << 19];
int par[1 << 19], cnt[1 << 19], sz[1 << 19];
bool hav[1 << 19];
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
void unite(int x, int y) {
  if ((x = find(x)) != (y = find(y))) {
    sz[y] += sz[x], cnt[y] += cnt[x], par[x] = y;
  }
}
namespace Match {
const int M = 1e6;
int Head[610], Next[M], Go[M], Pre[610], Nxt[610], F[610], S[610], Q[610],
    Vis[610], *Top = Q, Cnt = 0, Tim = 0, n, x, y;
inline void addedge(int x, int y) {
  Go[++Cnt] = y;
  Next[Cnt] = Head[x];
  Head[x] = Cnt;
}
int find(int x) { return x == F[x] ? x : F[x] = find(F[x]); }
int lca(int x, int y) {
  for (Tim++, x = find(x), y = find(y);; x ^= y ^= x ^= y)
    if (x) {
      if (Vis[x] == Tim) return x;
      Vis[x] = Tim;
      x = find(Pre[Nxt[x]]);
    }
}
void blossom(int x, int y, int l) {
  while (find(x) != l) {
    Pre[x] = y;
    if (S[Nxt[x]] == 1) *Top++, S[*Top = Nxt[x]] = 0;
    F[x] = l, F[Nxt[x]] = l;
    y = Nxt[x];
    x = Pre[y];
  }
}
void Match(int x) {
  for (int i = 1; i <= n; i++) F[i] = i;
  memset(S, -1, sizeof S);
  memset(Q, 0, sizeof Q);
  S[*(Top = Q + 1) = x] = 0;
  for (int *i = Q + 1; *i; *i++)
    for (int T = Head[*i]; T; T = Next[T]) {
      int g = Go[T];
      if (S[g] == -1) {
        Pre[g] = *i, S[g] = 1;
        if (!Nxt[g]) {
          for (int u = g, v = *i, lst; v; u = lst, v = Pre[u])
            lst = Nxt[v], Nxt[v] = u, Nxt[u] = v;
          return;
        }
        *Top++, S[*Top = Nxt[g]] = 0;
      } else if (!S[g] && find(g) != find(*i)) {
        int l = lca(g, *i);
        blossom(g, *i, l);
        blossom(*i, g, l);
      }
    }
}
void solve() {
  for (int i = 1; i <= n; i++)
    if (!Nxt[i]) Match(i);
}
}  // namespace Match
bool vis[1 << 19];
int fa[1 << 19], from[1 << 19];
int h[1 << 19], ecnt = 1;
struct edges {
  int nxt, to, tid, chk;
} E[1 << 20];
void addline(int u, int v, int tid, int chk) {
  E[++ecnt] = {h[u], v, tid, chk}, h[u] = ecnt;
}
int zzh = -1;
void dfs(int u, int in) {
  vis[u] = 1;
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (!vis[v]) {
      vis_dir[E[i].tid] = E[i].chk;
      from[v] = E[i].tid;
      fa[v] = u;
      dfs(v, i);
    } else if (i != (in ^ 1)) {
      zzh = i;
    }
  }
}
void solve() {
  n = read();
  for (int i = (1), iend = (n); i <= iend; ++i) A[i] = read(), par[i] = i;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    if (i > 1 && !A[i - 1]) flg[A[i]] = 1;
    if (i < n && !A[i + 1]) flg[A[i]] = 1;
    if (i < n && A[i] && A[i] == A[i + 1]) flg[A[i]] = 1;
  }
  flg[0] = 1;
  for (int i = (1), iend = (n); i <= iend; ++i)
    if (!flg[i]) unu.insert(i);
  for (int i = (1), iend = (n); i <= iend; ++i)
    if (!A[i]) {
      int j = i;
      while (j < n && !A[j + 1]) j++;
      if (i == 1) {
        int k = i;
        while (k + 1 <= j)
          A[k] = A[k + 1] = *unu.begin(), unu.erase(unu.begin()), k += 2;
        if (k == j) {
          if (A[k + 1]) {
            A[k] = A[k + 1];
          } else {
            A[k] = *unu.begin();
          }
        }
      }
      if (j == n) {
        int k = j;
        while (k - 1 >= i)
          A[k] = A[k - 1] = *unu.begin(), unu.erase(unu.begin()), k -= 2;
        if (k == i) {
          if (A[k - 1]) {
            A[k] = A[k - 1];
          } else {
            A[k] = *unu.begin();
          }
        }
      }
      i = j;
    }
  for (int i = (1), iend = (n); i <= iend; ++i)
    if (!A[i]) {
      int j = i;
      while (j < n && !A[j + 1]) j++;
      int len = j - i + 1;
      if (len % 2 == 0) {
        ind.push_back({i - 1, j + 1});
      } else {
        dir.push_back({i - 1, j + 1});
      }
      i = j;
    }
  for (int i = (1), iend = (n); i <= iend; ++i) sz[i] = 1;
  for (int i = (1), iend = (n); i <= iend; ++i)
    if (A[i] && A[i] == A[i + 1]) cnt[A[i]] = hav[A[i]] = 1;
  for (node p : dir) unite(A[p.px], A[p.py]), cnt[find(A[p.px])]++;
  Match::n = min(n, 600);
  map<pair<int, int>, int> mp;
  for (int i = (0), iend = (ind.size() - 1); i <= iend; ++i) {
    node p = ind[i];
    int u = A[p.px], v = A[p.py];
    if (find(u) != find(v) && sz[find(u)] > cnt[find(u)] &&
        sz[find(v)] > cnt[find(v)]) {
      mp[{find(u), find(v)}] = i;
      mp[{find(v), find(u)}] = i;
      Match::addedge(find(u), find(v));
      Match::addedge(find(v), find(u));
    }
  }
  Match::solve();
  vector<int> vec;
  for (int _ = (1), _end = (Match::n); _ <= _end; ++_)
    if (Match::Nxt[_] && _ < Match::Nxt[_]) {
      int tid = mp[{_, Match::Nxt[_]}];
      int i = ind[tid].px, j = ind[tid].py;
      A[i + 1] = A[i];
      A[j - 1] = A[j];
      vec.push_back(A[i]);
      vec.push_back(A[j]);
      for (int k = (i + 2), kend = (j - 2); k <= kend; ++k)
        A[k] = A[k + 1] = *unu.begin(), unu.erase(unu.begin()), k++;
      vis_ind[tid] = 1;
    }
  for (int i = (0), iend = (dir.size() - 1); i <= iend; ++i) {
    node p = dir[i];
    int u = A[p.px], v = A[p.py];
    addline(u, v, i, 0);
    addline(v, u, i, 1);
  }
  for (int rt : vec) {
    assert(!vis[rt]);
    zzh = -1;
    dfs(rt, 0);
  }
  for (int rt = (1), rtend = (n); rt <= rtend; ++rt)
    if (!vis[rt]) {
      zzh = -1;
      dfs(rt, 0);
      if (zzh != -1) {
        int u = E[zzh ^ 1].to;
        for (int cur = u; cur != rt; cur = fa[cur]) {
          vis_dir[from[cur]] ^= 1;
        }
        vis_dir[E[zzh].tid] = E[zzh].chk ^ 1;
      }
    }
  for (int _ = (0), _end = (dir.size() - 1); _ <= _end; ++_) {
    int i = dir[_].px, j = dir[_].py;
    if (!vis_dir[_]) {
      for (int k = (i + 1), kend = (j - 2); k <= kend; ++k)
        A[k] = A[k + 1] = *unu.begin(), unu.erase(unu.begin()), k++;
      A[j - 1] = A[j];
    } else {
      for (int k = (i + 2), kend = (j - 1); k <= kend; ++k)
        A[k] = A[k + 1] = *unu.begin(), unu.erase(unu.begin()), k++;
      A[i + 1] = A[i];
    }
  }
  for (int _ = (0), _end = (ind.size() - 1); _ <= _end; ++_)
    if (!vis_ind[_]) {
      int i = ind[_].px, j = ind[_].py;
      for (int k = (i + 1), kend = (j - 1); k <= kend; ++k)
        A[k] = A[k + 1] = *unu.begin(), unu.erase(unu.begin()), k++;
    }
  for (int i = (1), iend = (n); i <= iend; ++i) printf("%d ", A[i]);
}
signed main() {
  solve();
  orzjk::flush();
  return 0;
}
