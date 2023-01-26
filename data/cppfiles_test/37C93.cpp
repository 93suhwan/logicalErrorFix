#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
long long m, n;
void solve() {
  cin >> n >> m;
  bool visited[n + 5];
  memset(visited, 0, sizeof(visited));
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    visited[b] = 1;
  }
  long long node = -1;
  for (long long i = 1; i < n + 1; i++)
    if (!visited[i]) {
      node = i;
      break;
    }
  for (long long i = 1; i < n + 1; i++) {
    if (i == node) continue;
    cout << node << " " << i << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
