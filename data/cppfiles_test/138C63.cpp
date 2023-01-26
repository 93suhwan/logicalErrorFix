#include <bits/stdc++.h>
using namespace std;
int n, m, q;
pair<int, int> a[400004];
long long ans[200004], d[400004], sum;
int fa[400004], l[400004], r[400004], s[400004];
vector<pair<int, int> > v, ask;
int F(int x) { return fa[x] == x ? x : fa[x] = F(fa[x]); }
long long got(int v) { return d[r[v]] - d[r[v] - s[v]]; }
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n + m; i++) scanf("%d", &a[i].first), a[i].second = i;
  sort(a + 1, a + n + m + 1);
  for (int i = 1; i <= n + m; i++) {
    d[i] = d[i - 1] + a[i].first;
    fa[i] = i, s[i] = (a[i].second <= n), l[i] = r[i] = i;
    if (s[i] == 1) sum += a[i].first;
    if (i > 1) v.push_back({a[i].first - a[i - 1].first, i});
  }
  for (int i = 1; i <= q; i++) {
    int k;
    scanf("%d", &k);
    ask.push_back({k, i});
  }
  sort(v.begin(), v.end());
  sort(ask.begin(), ask.end());
  int it = 0;
  for (auto qr : ask) {
    while (it < v.size() && v[it].first <= qr.first) {
      int p = v[it].second;
      int U = F(p - 1), V = F(p);
      sum -= got(U) + got(V);
      fa[U] = V, s[V] += s[U], l[V] = l[U];
      sum += got(V);
      it++;
    }
    ans[qr.second] = sum;
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
