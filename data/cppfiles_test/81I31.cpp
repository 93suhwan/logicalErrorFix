#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
struct EDGE {
  int u, v, next, w;
} E[maxn * 3];
int p[maxn * 2], eid;
inline void init() {
  memset(p, -1, sizeof(p));
  eid = 0;
}
inline void insert(int u, int v, int w) {
  E[eid].u = u;
  E[eid].v = v;
  E[eid].w = w;
  E[eid].next = p[u];
  p[u] = eid++;
}
int a[maxn], b[maxn], t[maxn * 2];
int dp[maxn * 2], cnt[maxn * 2];
vector<int> g[maxn];
int main() {
  init();
  int n, d, cc = 0;
  scanf("%d%d", &n, &d);
  t[++cc] = d;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", a + i, b + i);
    if (a[i] < d) continue;
    t[++cc] = a[i];
    t[++cc] = b[i];
  }
  sort(t + 1, t + cc + 1);
  int mm = unique(t + 1, t + cc + 1) - t - 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < d) continue;
    a[i] = lower_bound(t + 1, t + mm + 1, a[i]) - t;
    b[i] = lower_bound(t + 1, t + mm + 1, b[i]) - t;
    if (a[i] < b[i]) {
      insert(a[i], b[i], 1);
    } else {
      ans++;
    }
  }
  for (int i = 1; i <= mm; i++) {
    insert(i, i + 1, 0);
  }
  for (int u = 1; u <= mm; u++) {
    for (int i = p[u]; i != -1; i = E[i].next) {
      int v = E[i].v, w = E[i].w;
      dp[v] = max(dp[v], dp[u] + w + cnt[v]);
    }
  }
  printf("%d", dp[mm + 1] + ans);
  return 0;
}
