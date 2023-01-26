#include <bits/stdc++.h>
using namespace std;
long long PosMod(long long a) { return a >= 0 ? a : a + 998244353; }
long long AddMod(long long a, long long b) {
  return PosMod((a + b) % 998244353);
}
long long MultMod(long long a, long long b) {
  return PosMod((a * b) % 998244353);
}
long long powll(long long a, long long n) {
  long long r = 1;
  for (long long b = n; b > 0; b >>= 1, a = MultMod(a, a))
    if (b & 1) r = MultMod(r, a);
  return r;
}
vector<vector<int>> adj;
bool fail;
int dfs(int here, int p, int targetK) {
  if (fail) return 0;
  int incoming = 0;
  for (int there : adj[here]) {
    if (there == p) continue;
    incoming += dfs(there, here, targetK);
  }
  if (incoming % targetK == 0)
    return 1;
  else if ((incoming + 1) % targetK == 0 && here != 1)
    return 0;
  else {
    fail = true;
    return 0;
  }
}
int n;
void solve() {
  cin >> n;
  adj = vector<vector<int>>(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  vector<long long> f = vector<long long>(n + 1);
  f[1] = powll(2, (long long)n - 1);
  for (int k = 2; k <= n - 1; k++) {
    if ((n - 1) % k != 0) continue;
    fail = false;
    dfs(1, 0, k);
    f[k] = fail ? 0 : 1;
  }
  vector<long long> h = vector<long long>(n + 1);
  h[1] = f[1];
  for (int i = 2; i <= n; i++) {
    long long val = f[i];
    if (val > 0) {
      for (int k = 2; i * k <= n; k++) {
        if (f[i * k]) val = 0;
      }
    }
    h[i] = val;
    h[1] -= val;
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", h[i]);
  }
  printf("\n");
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
