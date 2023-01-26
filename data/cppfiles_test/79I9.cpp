#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 20;
bool vis[N];
long long a[N], b[N], p[N];
long long n;
long long bfs() {
  queue<pair<long long, long long> > q;
  q.push({n, n});
  vis[n] = 1;
  while (q.size()) {
    auto tp = q.front();
    q.pop();
    vis[tp.first] = 1;
    for (long long i = 0; i <= a[tp.first]; i++) {
      long long pre = tp.first - i;
      if (pre <= 0) {
        p[0] = tp.second;
        return tp.second + 1;
      }
      if (vis[pre + b[pre]] || pre > n) continue;
      p[pre] = tp.second;
      q.push({pre + b[pre], pre});
      vis[pre + b[pre]] = 1;
    }
  }
  return -1;
}
long long cnt = 0;
void dfs(long long root) {
  if (root == n || p[root] == 0) {
    if (cnt == 0)
      printf("%lld\n", -1);
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
