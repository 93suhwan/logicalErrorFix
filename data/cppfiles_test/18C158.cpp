#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, INF = 2e9 + 2, NN = 2e6;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int n, d, M;
bool a[NN + 1], v[NN + 1];
void dfs(int i, int D) {
  if (v[i]) return;
  v[i] = 1, M = max(M, D);
  int j = (i + n - d) % n;
  if (a[j] == 1) dfs(j, D + 1);
}
void solve() {
  cin >> n >> d;
  M = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (v[i] || a[i] == 1) continue;
    dfs(i, 0);
  }
  for (int i = 0; i < n; i++) {
    if (!v[i]) {
      cout << -1;
      return;
    }
  }
  cout << M;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve();
    if (tt < t) cout << endl;
  }
  return 0;
}
