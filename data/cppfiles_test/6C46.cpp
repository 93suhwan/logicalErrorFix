#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int tmp[100005];
int sl = 0;
int dp[100005];
int zs = 0;
int sz[1200005];
int dd[100005];
int cl[100005];
vector<int> g[100005];
int sol() {
  zs = 0;
  for (int i = 1; i <= sl; ++i) {
    int u = tmp[i];
    for (auto &v : g[u]) {
      cl[v]++;
      if (cl[v] == 1) sz[++zs] = v;
    }
  }
  sort(sz + 1, sz + zs + 1);
  int cnt = 0;
  for (int i = zs; i >= 1; --i) {
    dd[sz[i]] =
        (dd[sz[i]] + (1ll * cl[sz[i]] * cl[sz[i]]) % 1000000007) % 1000000007;
    cnt = 0;
    for (auto &v : g[sz[i]])
      if (v != sz[i]) dd[v] = (dd[v] - dd[sz[i]] + 1000000007) % 1000000007;
  }
  int res = 0;
  for (int i = 1; i <= zs; ++i) {
    res = (res + (1ll * dd[sz[i]] * sz[i]) % 1000000007) % 1000000007;
    dd[sz[i]] = 0;
    cl[sz[i]] = 0;
  }
  return res;
}
int main() {
  ios ::sync_with_stdio(false);
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= 100000; ++i)
    for (int j = 1; j * j <= i; ++j)
      if (i % j == 0) {
        g[i].push_back(j);
        if (j * j != i) g[i].push_back(i / j);
      }
  for (int i = 1; i <= n; ++i) {
    sl = 0;
    for (int j = 1; i * j <= n; ++j) tmp[++sl] = a[i * j];
    dp[i] = sol();
  }
  for (int i = n; i >= 1; --i)
    for (int j = 2; i * j <= n; ++j)
      dp[i] = (dp[i] - dp[i * j] + 1000000007) % 1000000007;
  for (int i = 1; i <= n; ++i)
    ans = (ans + (1ll * i * dp[i]) % 1000000007) % 1000000007;
  cout << ans;
}
