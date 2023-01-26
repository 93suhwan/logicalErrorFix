#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
const long long M = 1e18 + 7;
const long long MOD = 1e9 + 7;
const int MX = 2e5 + 5;
vector<int> adj[MX];
vector<int> vis(MX);
vector<pair<long long, long long>> pr(MX);
long long dp[MX][2];
void dfs(int u, int p) {
  for (auto x : adj[u]) {
    if (x != p) {
      dfs(x, u);
    }
  }
}
void solve() {
  int n;
  cin >> n;
  int ans = n / 10;
  if (n % 10 == 9) ans++;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
