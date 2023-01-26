#include <bits/stdc++.h>
using namespace std;
int n, m, k, sz[400005], fa[400005];
pair<int, int> a[400005], q[200005];
long long res, ans[200005], sum[400005];
map<int, vector<int> > mp;
int Find(int x) { return (x == fa[x]) ? x : fa[x] = Find(fa[x]); }
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  for (int i = n + 1; i <= n + m; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &q[i].first);
    q[i].second = i;
  }
  sort(a + 1, a + 1 + n + m);
  for (int i = 1; i <= n + m; i++) {
    if (a[i].second <= n) res = res + a[i].first;
    sz[i] = (a[i].second <= n);
    sum[i] = sum[i - 1] + a[i].first;
    fa[i] = i;
    if (i > 1) mp[a[i].first - a[i - 1].first].push_back(i - 1);
  }
  sort(q + 1, q + 1 + k);
  auto it = mp.begin();
  for (int i = 1; i <= k; i++) {
    if (q[i].first == q[i - 1].first) {
      ans[q[i].second] = res;
      continue;
    }
    while (it != mp.end() && it->first <= q[i].first) {
      for (auto x : it->second) {
        int fv = Find(x), fu = Find(x + 1);
        res = res - (sum[fv] - sum[fv - sz[fv]] + sum[fu] - sum[fu - sz[fu]]);
        fa[fv] = fu, sz[fu] += sz[fv];
        res = res + (sum[fu] - sum[fu - sz[fu]]);
      }
      it++;
    }
    ans[q[i].second] = res;
  }
  for (int i = 1; i <= k; i++) printf("%lld\n", ans[i]);
  return 0;
}
