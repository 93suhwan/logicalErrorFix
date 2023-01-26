#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
long long a[MAXN], b[MAXN];
vector<long long> path[MAXN], t[MAXN];
long long idx[MAXN];
bool vis[MAXN];
stack<long long> s;
void dfs(long long u) {
  vis[u] = 1;
  for (long long v : path[u])
    if (!vis[v]) dfs(v);
  s.push(u);
}
void _dfs(long long u) {
  vis[u] = 1;
  for (long long v : t[u])
    if (!vis[v]) _dfs(v);
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long _t;
  cin >> _t;
  while (_t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
      cin >> a[i], path[i].clear(), t[i].clear();
    for (long long i = 1; i <= n; i++) cin >> b[i];
    for (long long i = 1; i <= n; i++) idx[i] = i;
    sort(idx + 1, idx + n + 1,
         [&](long long p, long long q) { return a[p] > a[q]; });
    for (long long i = 1; i < n; i++)
      path[idx[i]].push_back(idx[i + 1]), t[idx[i + 1]].push_back(idx[i]);
    sort(idx + 1, idx + n + 1,
         [&](long long p, long long q) { return b[p] > b[q]; });
    for (long long i = 1; i < n; i++)
      path[idx[i]].push_back(idx[i + 1]), t[idx[i + 1]].push_back(idx[i]);
    for (long long i = 1; i <= n; i++) vis[i] = 0;
    while (!s.empty()) s.pop();
    for (long long i = 1; i <= n; i++)
      if (!vis[i]) dfs(i);
    for (long long i = 1; i <= n; i++) vis[i] = 0;
    _dfs(s.top());
    for (long long i = 1; i <= n; i++) cout << vis[i];
    cout << '\n';
  }
}
