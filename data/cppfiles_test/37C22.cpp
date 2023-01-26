#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MONKE = 0;
const ll mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> edges(n - 1);
  vector<vector<int>> adj(n);
  for (auto &[l, r] : edges) {
    cin >> l >> r;
    adj[l - 1].push_back(r - 1);
    adj[r - 1].push_back(l - 1);
  }
  vector<ll> f(n + 1);
  f[1] = 1;
  for (int i = 1; i < n; i++) f[1] = (f[1] + f[1]) % mod;
  function<int(int, int, int)> dfs = [&](int node, int par, int val) {
    int cnt = 0;
    for (auto e : adj[node]) {
      if (e == par) continue;
      int res = dfs(e, node, val);
      if (res == -1) return -1;
      cnt += res;
    }
    if (cnt % val == 0) return 1;
    if (cnt % val == val - 1) return 0;
    return -1;
  };
  for (int i = 2; i < n; i++) {
    if ((n - 1) % i == 0) {
      f[i] = (dfs(0, -1, i) > 0);
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = i + i; j < n; j += i) f[i] -= f[j];
    if (i == 1) f[i] = (f[i] + mod) % mod;
  }
  for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
  return MONKE;
}
