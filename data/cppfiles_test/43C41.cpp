#include <bits/stdc++.h>
using namespace std;
const int N = 200000, C = 21;
int n, cq, a[N + 9];
struct side0 {
  int x, y, lim;
  side0(int X = 0, int Y = 0, int Lim = 0) : x(X), y(Y), lim(Lim) {}
} b[N + 9];
struct side {
  int next, y, v;
} e[N * 2 + 9];
int lin[N + 9], cs;
void Ins(int x, int y, int v) {
  e[++cs].next = lin[x];
  lin[x] = cs;
  e[cs].y = y;
  e[cs].v = v;
}
void Ins2(int x, int y, int v) {
  Ins(x, y, v);
  Ins(y, x, v);
}
struct question {
  int k, v, id;
  question(int K = 0, int V = 0, int Id = 0) : k(K), v(V), id(Id) {}
} q[N + 9];
void into() {
  scanf("%d%d", &n, &cq);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    int x, y, c, t;
    scanf("%d%d%d%d", &x, &y, &c, &t);
    b[i] = side0(x, y, c);
    Ins2(x, y, t);
  }
  for (int i = 1; i <= cq; ++i) {
    int v, x;
    scanf("%d%d", &v, &x);
    q[i] = question(x, v, i);
  }
}
int dep[N + 9], gr[N + 9][C], mx[N + 9][C];
int dfs[N + 9], co;
void Dfs_gr(int k, int fa, int v) {
  dep[k] = dep[fa] + 1;
  gr[k][0] = fa;
  mx[k][0] = v;
  for (int i = 1; i < C; ++i) {
    gr[k][i] = gr[gr[k][i - 1]][i - 1];
    mx[k][i] = max(mx[k][i - 1], mx[gr[k][i - 1]][i - 1]);
  }
  dfs[k] = ++co;
  for (int i = lin[k]; i; i = e[i].next)
    if (e[i].y != fa) Dfs_gr(e[i].y, k, e[i].v);
}
int Query_max(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int res = 0;
  for (int i = C - 1; i >= 0; --i)
    if (dep[gr[x][i]] >= dep[y]) {
      res = max(res, mx[x][i]);
      x = gr[x][i];
    }
  if (x == y) return res;
  for (int i = C - 1; i >= 0; --i)
    if (gr[x][i] != gr[y][i]) {
      res = max({res, mx[x][i], mx[y][i]});
      x = gr[x][i];
      y = gr[y][i];
    }
  return max({res, mx[x][0], mx[y][0]});
}
int uni[N + 9], pos[N + 9];
int Query_uni(int k) { return k == uni[k] ? k : uni[k] = Query_uni(uni[k]); }
struct cmp {
  bool operator()(const int &x, const int &y) const { return dfs[x] < dfs[y]; }
};
set<int, cmp> s[N + 9];
int Query_next(set<int, cmp> &s, int x) {
  auto it = s.upper_bound(x);
  return *(it == s.end() ? s.begin() : it);
}
int Query_last(set<int, cmp> &s, int x) {
  auto it = s.upper_bound(x);
  return *(it == s.begin() ? --s.end() : --it);
}
int now[N + 9], ans[N + 9][2];
void Get_ans() {
  sort(b + 1, b + n,
       [&](const side0 &a, const side0 &b) { return a.lim > b.lim; });
  sort(q + 1, q + cq + 1,
       [&](const question &a, const question &b) { return a.v > b.v; });
  for (int i = 1; i <= n; ++i) {
    uni[i] = pos[i] = i;
    s[i].insert(i);
    now[i] = 0;
  }
  for (int i = 1, j = 1; i <= n; ++i) {
    for (; j <= cq && q[j].v > b[i].lim; ++j) {
      int &t = ans[q[j].id][1], k = q[j].k, fk = Query_uni(k);
      ans[q[j].id][0] = a[pos[fk]];
      t = max(t, now[fk]);
      if (a[k] != a[pos[fk]]) {
        t = max(t, Query_max(k, Query_next(s[fk], k)));
        t = max(t, Query_max(k, Query_last(s[fk], k)));
      }
    }
    if (i < n) {
      int x = Query_uni(b[i].x), y = Query_uni(b[i].y);
      if (a[pos[x]] < a[pos[y]]) {
        uni[x] = y;
        s[x].clear();
      } else if (a[pos[x]] > a[pos[y]]) {
        uni[y] = x;
        s[y].clear();
      } else {
        if (s[x].size() < s[y].size()) swap(x, y);
        uni[y] = x;
        now[x] = max(now[x], now[y]);
        for (int k : s[y]) {
          now[x] = max(now[x], Query_max(k, Query_next(s[x], k)));
          now[x] = max(now[x], Query_max(k, Query_last(s[x], k)));
          s[x].insert(k);
        }
        s[y].clear();
      }
    }
  }
}
void work() {
  Dfs_gr(1, 0, 0);
  Get_ans();
}
void outo() {
  for (int i = 1; i <= cq; ++i) printf("%d %d\n", ans[i][0], ans[i][1]);
}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
