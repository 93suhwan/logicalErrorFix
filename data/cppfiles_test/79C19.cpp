#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 20;
bool vis[N];
long long a[N], b[N], p[N];
long long n;
struct node {
  long long x, y, f;
  bool operator<(const node& tmp) const {
    if (tmp.f != f) return f > tmp.f;
    return x > tmp.x;
  }
};
long long pm;
long long bfs() {
  pm = n + 1;
  queue<node> q;
  q.push({n, n, 1});
  vis[n] = 1;
  while (q.size()) {
    auto tp = q.front();
    q.pop();
    for (long long i = tp.x - a[tp.x]; i <= pm; i++) {
      long long pre = i;
      if (pre <= 0) {
        p[0] = tp.y;
        return tp.y + 1;
      }
      if (vis[pre + b[pre]] || pre > n) continue;
      p[pre] = tp.y;
      q.push({pre + b[pre], pre, tp.f + 1});
      vis[pre + b[pre]] = 1;
    }
    pm = min(pm, tp.x - a[tp.x]);
  }
  return -1;
}
long long cnt = 0;
void dfs(long long root) {
  if (root == n || p[root] == 0) {
    if (cnt == 0)
      printf("-1\n");
    else
      printf("%lld\n", cnt);
    return;
  }
  cnt++;
  dfs(p[root]);
  printf("%lld ", root);
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld", a + i);
  for (long long i = 1; i <= n; i++) scanf("%lld", b + i);
  bfs();
  dfs(0);
}
