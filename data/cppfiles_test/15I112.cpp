#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
const int N = 109;
int c[N][N];
int mod = 1e9 + 7;
vector<vector<int>> adj;
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
    vector<bool> vis(n, 0);
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    for (int sz = 1; !q.empty(); sz = q.size()) {
      ans += c[sz][k];
      if (ans > mod) ans -= mod;
      while (sz--) {
        int cur = q.front();
        q.pop();
        for (int ch : adj[cur]) {
          if (!vis[ch]) {
            vis[ch] = 1;
            q.push(ch);
          }
        }
      }
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
