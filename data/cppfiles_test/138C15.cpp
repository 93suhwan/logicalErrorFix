#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int fa[400010], sz[400010];
long long res, ans[200010], sum[400010];
pair<int, int> q[200010], a[400010];
map<int, vector<int> > mp;
int find(int x) {
  if (x != fa[x]) return fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 1; i <= n + m; i++) scanf("%d", &a[i].first), a[i].second = i;
  sort(a + 1, a + n + m + 1);
  for (int i = 1; i <= n + m; i++) {
    if (a[i].second <= n) res += a[i].first;
    sz[i] = (a[i].second <= n);
    sum[i] = sum[i - 1] + a[i].first, fa[i] = i;
    if (i > 1) mp[a[i].first - a[i - 1].first].push_back(i - 1);
  }
  for (int i = 1; i <= t; i++) scanf("%d", &q[i].first), q[i].second = i;
  sort(q + 1, q + t + 1);
  auto it = mp.begin();
  for (int i = 1; i <= t; i++) {
    if (q[i].first == q[i - 1].first) {
      ans[q[i].second] = res;
      continue;
    }
    while (it != mp.end() && it->first <= q[i].first) {
      for (auto k : it->second) {
        int fu = find(k), fv = find(k + 1);
        res -= (sum[fv] - sum[fv - sz[fv]] + sum[fu] - sum[fu - sz[fu]]);
        sz[fv] += sz[fu], fa[fu] = fv;
        res += (sum[fv] - sum[fv - sz[fv]]);
      }
      it++;
    }
    ans[q[i].second] = res;
  }
  for (int i = 1; i <= t; i++) printf("%lld\n", ans[i]);
  return 0;
}
