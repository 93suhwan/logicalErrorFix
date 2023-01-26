#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], s[2 * maxn], par[2 * maxn];
long long res, ans[maxn], all[2 * maxn], sum[2 * maxn];
pair<int, int> query[maxn], item[2 * maxn], sub[2 * maxn];
int n, m, q;
int fin(int u) {
  if (par[u] != u) par[u] = fin(par[u]);
  return par[u];
}
void join(int u, int v) {
  u = fin(u);
  v = fin(v);
  if (u == v) return;
  if (par[u] > par[v]) swap(u, v);
  par[u] = v;
  res -= all[u];
  res -= all[v];
  s[v] += s[u];
  all[v] = sum[v] - sum[v - s[v]];
  res += all[v];
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    item[i] = pair<int, int>(a[i], 0);
    res += a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    item[i + n] = pair<int, int>(b[i], 1);
  }
  sort(item + 1, item + m + n + 1);
  for (int i = 1; i <= m + n; ++i) {
    sum[i] = sum[i - 1] + item[i].first;
    par[i] = i;
    if (item[i].second) {
      all[i] = 0;
      s[i] = 0;
    } else {
      all[i] = item[i].first;
      s[i] = 1;
    }
  }
  for (int i = 1; i < m + n; ++i)
    sub[i] = pair<int, int>(item[i + 1].first - item[i].first, i);
  for (int i = 1; i <= q; ++i) {
    cin >> query[i].first;
    query[i].second = i;
  }
  sort(sub + 1, sub + m + n);
  sort(query + 1, query + q + 1);
  int j = 1;
  for (int i = 1; i <= q; ++i) {
    while (j < m + n && sub[j].first <= query[i].first) {
      join(sub[j].second + 1, sub[j].second);
      j++;
    }
    ans[query[i].second] = res;
  }
  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}
