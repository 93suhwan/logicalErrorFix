#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
const int MOD = 988244353;
int mul(int a, int b) { return (long long)a * b % MOD; }
int sub(int a, int b) {
  a -= b;
  return a < 0 ? a + MOD : a;
}
int a[N], ans[N];
vector<pair<int, int>> g[N];
bool edg[N];
void dfs(int u, int p, int k) {
  for (auto x : g[u]) {
    if (x.first != p) {
      dfs(x.first, u, k);
    }
  }
  for (auto x : g[u]) {
    if (x.first != p) {
      if (!edg[x.second]) {
        edg[x.second] = true;
        a[u]++;
      }
    }
  }
  for (auto x : g[u]) {
    if (x.first == p) {
      if (a[u] % k != 0) {
        edg[x.second] = true;
        a[u]++;
      }
    }
  }
}
int check(int n, int k) {
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
  dfs(0, -1, k);
  for (int i = 0; i < n; i++) {
    if (a[i] % k != 0) {
      return 0;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (!edg[i]) {
      return 0;
    }
  }
  return 1;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) g[i].clear();
  for (int i = 0; i < n; i++) {
    ans[i] = 0;
    edg[i] = false;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  int S = 0;
  for (int k = n; k >= 2; k--) {
    if (k == n || (n - 1) % k != 0) {
      ans[k] = 0;
      continue;
    }
    ans[k] = check(n, k);
    for (int j = k + k; j <= n; j += k) {
      if (ans[j] == 1) ans[k] = 0;
    }
    S += ans[k];
  }
  int sol1 = 1;
  for (int i = 0; i < n - 1; i++) {
    sol1 = mul(sol1, 2);
  }
  ans[1] = sub(sol1, S);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
