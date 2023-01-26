#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5, mod = 1e9 + 7;
int t, l[N], r[N], cnt[N], par[N], d[N], n, m, q;
pair<int, int> a[N];
long long ans, p[N];
int find(int u) { return (par[u] == u ? u : par[u] = find(par[u])); }
void merge(int u, int v) {
  u = find(u);
  v = find(v);
  par[v] = u;
  ans -= p[r[v]] - p[r[v] - cnt[v]];
  ans -= p[r[u]] - p[r[u] - cnt[u]];
  r[u] = max(r[u], r[v]);
  l[u] = min(l[u], l[v]);
  cnt[u] += cnt[v];
  ans += p[r[u]] - p[r[u] - cnt[u]];
}
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first, ans += a[i].first, a[i].second = 1;
  for (int i = n + 1; i <= n + m; i++) cin >> a[i].first, a[i].second = 0;
  sort(a + 1, a + n + m + 1);
  n += m;
  vector<pair<int, int> > x, qy;
  for (int i = 1; i <= n; i++) {
    l[i] = i;
    r[i] = par[i] = i;
    cnt[i] = a[i].second;
    p[i] = p[i - 1] + a[i].first;
    if (i - 1) x.push_back({a[i].first - a[i - 1].first, i});
  }
  cout << endl;
  sort(x.rbegin(), x.rend());
  for (int i = 1; i <= q; i++) {
    int k;
    cin >> k;
    qy.push_back({k, i});
  }
  sort(qy.begin(), qy.end());
  for (int i = 0; i < qy.size(); i++) {
    while (x.size() && x.back().first <= qy[i].first) {
      pair<int, int> y = x.back();
      x.pop_back();
      merge(y.second - 1, y.second);
    }
    d[qy[i].second] = ans;
  }
  for (int i = 1; i <= q; i++) cout << d[i] << " ";
}
