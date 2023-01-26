#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, r;
vector<long long> edge[N];
long long parent[N], depth[N], cnt[N];
vector<long long> tmp;
bool visited[N];
void dfs(long long u) {
  for (long long v : edge[u]) {
    if (v == parent[u]) continue;
    parent[v] = u;
    depth[v] = depth[u] + 1;
    dfs(v);
  }
}
bool cmp_depth(long long x, long long y) { return depth[x] > depth[y]; }
bool cmp_cnt(long long x, long long y) { return cnt[x] > cnt[y]; }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> r;
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1);
  for (long long i = 1; i <= n; ++i)
    if (edge[i].size() == 1 && i != 1) tmp.push_back(i);
  sort(tmp.begin(), tmp.end(), cmp_depth);
  for (long long i = 0; i < tmp.size(); ++i) {
    long long u = tmp[i];
    visited[u] = true;
    cnt[tmp[i]] = 1;
    while (parent[u] != 0 && !visited[parent[u]]) {
      u = parent[u];
      visited[u] = true;
      ++cnt[tmp[i]];
    }
  }
  sort(tmp.begin(), tmp.end(), cmp_cnt);
  long long b = n, ans = -1e18;
  for (long long i = 0; i <= r; ++i) {
    if (b >= n / 2) {
      ans = max(ans, i * (n - i) - (n / 2) * (n - (n / 2)));
    } else {
      ans = max(ans, i * (n - i) - b * (n - b));
    }
    if (i < tmp.size()) b -= cnt[tmp[i]];
  }
  cout << ans;
}
