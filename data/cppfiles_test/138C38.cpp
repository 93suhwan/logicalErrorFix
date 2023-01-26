#include <bits/stdc++.h>
using namespace std;
int fa[400001], cnt[400001];
pair<int, int> a[400001], k[200001], b[400001];
long long s[400001], ans[200001];
long long sum;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merg(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) {
    sum -= s[u] - s[u - cnt[u]] + s[v] - s[v - cnt[v]];
    cnt[u] += cnt[v];
    fa[v] = u;
    sum += s[u] - s[u - cnt[u]];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    cin >> a[i].first, a[i].second = 1, sum += a[i].first;
  for (int i = 1; i <= m; ++i) cin >> a[n + i].first;
  for (int i = 1; i <= q; ++i) cin >> k[i].first, k[i].second = i;
  sort(a + 1, a + 1 + n + m);
  sort(k + 1, k + 1 + q);
  for (int i = 1; i <= n + m; ++i) {
    fa[i] = i;
    s[i] = s[i - 1] + a[i].first;
    cnt[i] = a[i].second;
    b[i].first = a[i].first - a[i - 1].first;
    b[i].second = i;
  }
  sort(b + 1, b + 1 + n + m);
  int idx = 1;
  for (int i = 1; i <= q; ++i) {
    for (; idx <= n + m && b[idx].first <= k[i].first;
         merg(b[idx].second, b[idx].second - 1), ++idx)
      ;
    ans[k[i].second] = sum;
  }
  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}
