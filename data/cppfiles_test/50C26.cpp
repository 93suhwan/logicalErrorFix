#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
long long l[maxn], r[maxn];
int op[maxn], root, id[maxn * 100], tot, idtot, ls[maxn * 100], rs[maxn * 100],
    ban[maxn * 100], fa[maxn * 100], n;
vector<int> has[maxn], g[maxn * 100];
void add(int &rt, long long l, long long r, long long ql, long long qr) {
  if (!rt) rt = ++tot;
  if (l >= ql && r <= qr) {
    id[rt] = ++idtot;
    return;
  }
  long long mid = l + r >> 1;
  if (ql <= mid) add(ls[rt], l, mid, ql, qr);
  if (qr >= mid + 1) add(rs[rt], mid + 1, r, ql, qr);
}
void getedge(int L, int R, int cur, int limt) {
  if (!L || !R) return;
  if (cur > limt) {
    getedge(ls[L], ls[R], cur - 1, limt);
    getedge(rs[L], rs[R], cur - 1, limt);
    return;
  }
  if (cur == limt) {
    getedge(ls[L], rs[R], cur - 1, limt);
    return;
  }
  if (id[L] && id[R]) {
    g[id[L]].push_back(id[R]);
    g[id[R]].push_back(id[L]);
    return;
  }
  if (id[L]) {
    getedge(L, ls[R], cur - 1, limt);
    getedge(L, rs[R], cur - 1, limt);
    return;
  }
  if (id[R]) {
    getedge(ls[L], R, cur - 1, limt);
    getedge(rs[L], R, cur - 1, limt);
    return;
  }
  getedge(ls[L], ls[R], cur - 1, limt);
  getedge(rs[L], rs[R], cur - 1, limt);
}
void getpoint(int rt, long long l, long long r, int i, long long ql,
              long long qr) {
  if (l >= ql && r <= qr) {
    has[i].push_back(id[rt]);
    ban[id[rt]] = 1;
    return;
  }
  long long mid = l + r >> 1;
  if (ql <= mid) getpoint(ls[rt], l, mid, i, ql, qr);
  if (qr >= mid + 1) getpoint(rs[rt], mid + 1, r, i, ql, qr);
}
int fd(int rt) { return rt == fa[rt] ? rt : (fa[rt] = fd(fa[rt])); }
void merge(int u, int v) {
  if (fd(u) == fd(v)) return;
  fa[fd(u)] = fd(v);
}
void insert(int x) {
  fa[x] = x;
  for (auto u : g[x]) {
    if (fa[u]) merge(x, u);
  }
}
int getbl(long long x) {
  int u = root;
  if (id[u]) return id[u];
  for (int i = n - 1; i >= 0; --i) {
    if ((x >> i) & 1) {
      u = rs[u];
    } else
      u = ls[u];
    if (id[u]) return id[u];
  }
}
int main() {
  int m;
  vector<long long> x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    char s[5];
    scanf("%s%lld%lld", s, l + i, r + i);
    if (s[0] == 'b') {
      x.push_back(l[i] - 1);
      x.push_back(r[i]);
    } else
      op[i] = 1;
  }
  long long mx = (1ll << n) - 1;
  x.push_back(-1);
  x.push_back(mx);
  sort(x.begin(), x.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  for (int i = 1; i < x.size(); ++i) add(root, 0, mx, x[i - 1] + 1, x[i]);
  for (int i = 0; i < n; ++i) getedge(root, root, n - 1, i);
  for (int i = 0; i < m; ++i)
    if (!op[i]) getpoint(root, 0, mx, i, l[i], r[i]);
  for (int i = 1; i <= idtot; ++i)
    if (!ban[i]) insert(i);
  vector<int> ans;
  for (int i = m - 1; i >= 0; --i) {
    l[i] = getbl(l[i]), r[i] = getbl(r[i]);
    if (op[i]) {
      ans.push_back(fd(l[i]) == fd(r[i]));
    } else {
      for (auto u : has[i]) {
        insert(u);
      }
    }
  }
  for (int i = (int)ans.size() - 1; i >= 0; --i) printf("%d\n", ans[i]);
}
