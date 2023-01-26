#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
const int N(1e6 + 10);
int n, q;
int a[N];
int buk[N];
int ans[N];
int t[N << 3];
vector<int> G[N];
vector<tuple<int, int, int> > qr[N];
multiset<int> st[N];
inline void upd(int p, int l, int r, int x, int v) {
  if (l == r) return t[p] += v, void();
  if (x <= ((l + r) >> 1))
    upd(p << 1, l, ((l + r) >> 1), x, v);
  else
    upd(p << 1 | 1, ((l + r) >> 1) + 1, r, x, v);
  t[p] = t[p << 1] + t[p << 1 | 1];
}
inline int qry(int p, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) return t[p];
  int res = 0;
  if (ql <= ((l + r) >> 1)) res += qry(p << 1, l, ((l + r) >> 1), ql, qr);
  if (qr > ((l + r) >> 1))
    res += qry(p << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr);
  return res;
}
inline int kth(int p, int l, int r, int k) {
  if (l == r) return l;
  if (t[p << 1] >= k) return kth(p << 1, l, ((l + r) >> 1), k);
  return kth(p << 1 | 1, ((l + r) >> 1) + 1, r, k - t[p << 1]);
}
inline void dfs(int u) {
  if (buk[a[u]])
    upd(1, 1, n, buk[a[u]], -1), st[buk[a[u]]].erase(st[buk[a[u]]].find(a[u]));
  ++buk[a[u]];
  if (buk[a[u]]) st[buk[a[u]]].insert(a[u]), upd(1, 1, n, buk[a[u]], 1);
  for (tuple<int, int, int> p : qr[u]) {
    int l, k, id;
    tie(l, k, id) = p;
    if (l > 1) k += qry(1, 1, n, 1, l - 1);
    if (t[1] < k)
      ans[id] = -1;
    else
      ans[id] = (*st[kth(1, 1, n, k)].begin());
  }
  for (int v : G[u]) dfs(v);
  if (buk[a[u]])
    upd(1, 1, n, buk[a[u]], -1), st[buk[a[u]]].erase(st[buk[a[u]]].find(a[u]));
  --buk[a[u]];
  if (buk[a[u]]) st[buk[a[u]]].insert(a[u]), upd(1, 1, n, buk[a[u]], 1);
}
inline void work() {
  n = read(), q = read();
  for (int i = (0); i <= (n << 3); i++) t[i] = 0;
  for (int i = (1); i <= (n); i++)
    a[i] = read(), G[i].clear(), qr[i].clear(), st[i].clear();
  int v, l, k;
  for (int i = (2); i <= (n); i++) v = read(), G[v].push_back(i);
  for (int i = (1); i <= (q); i++)
    v = read(), l = read(), k = read(), qr[v].emplace_back(l, k, i);
  dfs(1);
  for (int i = (1); i <= (q); i++) printf("%d ", ans[i]);
  puts("");
}
int main() {
  int tasks = read();
  while (tasks--) work();
  return 0;
}
