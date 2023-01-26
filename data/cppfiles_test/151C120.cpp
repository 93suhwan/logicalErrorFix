#include <bits/stdc++.h>
using namespace std;
int n;
struct Node {
  int val, nxt;
} node[500005];
int tot = 0;
int st[500005];
int ed[500005];
int ans[500005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int op, x, y;
    cin >> op >> x;
    if (op == 1) {
      node[++tot].val = ++n;
      if (!st[x]) {
        st[x] = ed[x] = tot;
        continue;
      }
      node[tot].nxt = st[x];
      st[x] = tot;
    } else {
      cin >> y;
      if (y == x) continue;
      if (!st[x]) continue;
      if (!st[y]) {
        st[y] = st[x];
        ed[y] = ed[x];
        st[x] = ed[x] = 0;
        continue;
      }
      node[ed[y]].nxt = st[x];
      ed[y] = ed[x];
      st[x] = ed[x] = 0;
    }
  }
  for (int i = 1; i < 500005; i++) {
    int now = st[i];
    while (now) {
      ans[node[now].val] = i;
      now = node[now].nxt;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
