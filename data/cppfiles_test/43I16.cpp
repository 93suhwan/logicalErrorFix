#include <bits/stdc++.h>
using namespace std;
const int N = 200005, K = 20;
int n, Q, e[N], lc[N * 2], rc[N * 2], cap[N * 2], toll[N * 2], fa[N * 2][K],
    mx[N * 2], cnt[N * 2], sub_res[N * 2], w1[N * 2][K], w2[N * 2][K],
    w3[N * 2][K];
struct ufs {
  int n;
  vector<int> fa;
  ufs(int n) : n(n) {
    fa.assign(n, 0);
    for (int i = (0); i <= (n - 1); ++i) fa[i] = i;
  }
  int fd(int k1) { return fa[k1] == k1 ? k1 : fa[k1] = fd(fa[k1]); }
  int chk(int k1, int k2) { return fd(k1) == fd(k2); }
  int mer(int k1, int k2) {
    k1 = fd(k1), k2 = fd(k2);
    if (k1 == k2) return 0;
    fa[k1] = k2;
    return 1;
  }
};
void dfs1(int k1, int k2) {
  fa[k1][0] = k2;
  for (int i = (1); i <= (K - 1); ++i) fa[k1][i] = fa[fa[k1][i - 1]][i - 1];
  if (k2) w1[k1][0] = toll[k2];
  for (int i = (1); i <= (K - 1); ++i)
    if (fa[k1][i]) w1[k1][i] = max(w1[k1][i - 1], w1[fa[k1][i - 1]][i - 1]);
  if (k1 <= n) {
    mx[k1] = e[k1];
    cnt[k1] = 1;
    return;
  }
  dfs1(lc[k1], k1), dfs1(rc[k1], k1);
  mx[k1] = max(mx[lc[k1]], mx[rc[k1]]);
  sub_res[k1] = max({toll[k1], mx[lc[k1]] == mx[k1] ? sub_res[lc[k1]] : 0,
                     mx[rc[k1]] == mx[k1] ? sub_res[rc[k1]] : 0});
  cnt[k1] = (mx[lc[k1]] == mx[k1] ? cnt[lc[k1]] : 0) +
            (mx[rc[k1]] == mx[k1] ? cnt[rc[k1]] : 0);
}
void dfs2(int k1, int k2) {
  if (k2) {
    int other = lc[k2] == k1 ? rc[k2] : lc[k2];
    w2[k1][0] = max(toll[k2], sub_res[other]), w3[k1][0] = mx[other];
  }
  for (int i = (1); i <= (K - 1); ++i)
    if (fa[k1][i]) {
      w3[k1][i] = max(w3[k1][i - 1], w3[fa[k1][i - 1]][i - 1]);
      if (w3[k1][i] == w3[k1][i - 1]) w2[k1][i] = max(w2[k1][i], w2[k1][i - 1]);
      if (w3[k1][i] == w3[fa[k1][i - 1]][i - 1])
        w2[k1][i] = max(w2[k1][i], max(w1[k1][i], w2[fa[k1][i - 1]][i - 1]));
    }
  if (k1 <= n) {
    return;
  }
  dfs2(lc[k1], k1), dfs2(rc[k1], k1);
}
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = (1); i <= (n); ++i) scanf("%d", &e[i]);
  vector<tuple<int, int, int, int> > es;
  for (int i = (2); i <= (n); ++i) {
    int a, b, c, t;
    scanf("%d%d%d%d", &a, &b, &c, &t);
    es.emplace_back(c, a, b, t);
  }
  sort(es.begin(), es.end());
  reverse(es.begin(), es.end());
  ufs o(n * 2);
  int cur = n;
  for (auto x : es) {
    int a, b, c, t;
    tie(c, a, b, t) = x;
    if (!o.chk(a, b)) {
      ++cur;
      cap[cur] = c, toll[cur] = t;
      lc[cur] = o.fd(a);
      rc[cur] = o.fd(b);
      o.mer(lc[cur], cur);
      o.mer(rc[cur], cur);
    }
  }
  dfs1(cur, 0);
  dfs2(cur, 0);
  for (int _ = (1); _ <= (Q); ++_) {
    int v, x;
    scanf("%d%d", &v, &x);
    int k1 = x;
    int len = 0;
    for (int i = (K - 1); i >= (0); --i)
      if (fa[k1][i] && cap[fa[k1][i]] >= v) k1 = fa[k1][i], len += 1 << i;
    printf("%d ", mx[k1]);
    int k2 = x;
    int ans = mx[x] == mx[k1] ? sub_res[x] : 0, base = 0;
    for (int i = (K - 1); i >= (0); --i)
      if (fa[k2][i] && len >= (1 << i) &&
          (mx[k2] < mx[k1] || (mx[k2] == mx[k1] && cnt[k2] < cnt[k1]))) {
        if (w3[k2][i] == mx[k1]) ans = max(ans, max(w2[k2][i], base));
        base = max(base, w1[k2][i]);
        k2 = fa[k2][i];
        len -= 1 << i;
      }
    if (fa[k2][0] && len &&
        (mx[k2] < mx[k1] || (mx[k2] == mx[k1] && cnt[k2] < cnt[k1])) &&
        w3[k2][0] == mx[k1])
      ans = max(ans, max(w2[k2][0], base));
    printf("%d\n", ans);
  }
  return 0;
}
