#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10, LIM = 5e5;
int q, op, x, y, tot, cur, fa[MAXN * 2], rt[MAXN], tag[MAXN * 2], col[MAXN * 2];
int ans[MAXN];
int Find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = Find(fa[x]);
}
int main() {
  tot = LIM;
  for (int i = (1); i <= (tot); i++) fa[i] = i, rt[i] = i, col[i] = i;
  cin >> q;
  for (int i = (1); i <= (q); i++) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      tot++;
      cur++;
      tag[tot] = cur;
      fa[tot] = Find(rt[x]);
    } else {
      cin >> x >> y;
      if (x == y) continue;
      fa[Find(rt[x])] = Find(rt[y]);
      tot++;
      fa[tot] = tot;
      rt[x] = tot;
      col[tot] = x;
    }
  }
  for (int i = (1); i <= (tot); i++) {
    if (!tag[i]) continue;
    int u = Find(i);
    ans[tag[i]] = col[u];
  }
  for (int i = (1); i <= (cur); i++) printf("%d ", ans[i]);
  return 0;
}
