#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
vector<int> vec[maxn];
int f[maxn], vis[maxn];
int dfs(int u) {
  if (vis[u]) {
    return (f[u] == inf) ? -1 : f[u];
  }
  vis[u] = 1;
  int k = 1;
  for (int i : vec[u]) {
    int t = dfs(i);
    if (t == -1) return -1;
    if (u > i)
      k = max(k, dfs(i));
    else
      k = max(k, dfs(i) + 1);
  }
  return f[u] = k;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i <= n + 2; i++) vec[i].clear();
  for (int i = 0; i <= n + 2; i++) f[i] = inf, vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      vec[i].push_back(x);
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int k = dfs(i);
      if (k == -1) {
        cout << -1 << endl;
        return;
      }
      res = max(res, k);
    }
  }
  cout << res << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
