#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
const int N = 109;
int c[N][N];
int mod = 1e9 + 7;
vector<vector<int>> adj;
int d[N][N];
void calc(int node, int par, int dep, int root) {
  d[root][dep]++;
  for (int ch : adj[node])
    if (ch != par) calc(ch, node, dep + 1, root);
}
void solve() {
  int n, k;
  cin >> n >> k;
  adj = vector<vector<int>>(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  if (k == 2) {
    cout << c[n][k] << "\n";
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    memset(d, 0, sizeof d);
    int cnt = adj[i].size();
    for (int ch : adj[i]) calc(ch, i, 0, ch);
    for (int di = 0; di <= n; di++) {
      long long prod = 1;
      for (int ch : adj[i]) {
        prod *= d[ch][di];
        prod %= mod;
      }
      ans += (1ll * prod * c[cnt][k]) % mod;
      ans %= mod;
    }
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  c[0][0] = 1;
  for (int i = 1; i < N; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
  int t;
  cin >> t;
  while (t--) solve();
}
