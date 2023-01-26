#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 2 * N;
int n, k;
vector<int> g[N];
bool st[N];
int pre[N], d[N], dep[N];
void dfs(int u, int fa) {
  pre[u] = fa;
  for (int j : g[u]) {
    if (j == fa) continue;
    dep[j] = dep[u] + 1;
    dfs(j, u);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b), g[b].push_back(a);
    d[a]++, d[b]++;
  }
  dfs(1, 0);
  vector<pair<int, int> > a;
  for (int i = 2; i <= n; i++)
    if (d[i] == 1) a.push_back({-dep[i], i});
  int t = (n + 1) / 2;
  if (a.size() <= k) {
    if (a.size() <= t)
      printf("%lld\n", 1ll * t * (n - t));
    else
      printf("%lld\n", 1ll * (n - a.size()) * (int)a.size());
    return 0;
  }
  sort(a.begin(), a.end());
  st[0] = true;
  dep[0] = -1;
  for (int i = 0; i < a.size(); i++) {
    int j = a[i].second;
    while (!st[j]) {
      st[j] = true;
      j = pre[j];
    }
    a[i].first = -(dep[a[i].second] - dep[j]);
  }
  sort(a.begin(), a.end());
  int s = 0;
  for (int i = 0; i < k; i++) s -= a[i].first;
  int s1 = n - s;
  int s2 = n - k - s1;
  int t1 = k - s1, m = s2 + t1;
  printf("%lld\n", 1ll * s2 * t1);
  return 0;
}
