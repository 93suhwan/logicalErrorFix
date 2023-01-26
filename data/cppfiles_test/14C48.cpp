#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const long long mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1, 0);
  vector<vector<int>> d(n + 10, vector<int>(n + 10, 0));
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      d[i][j] = max(d[i][j], d[i - 1][j] + (a[i] == i - j));
      d[i][j + 1] = max(d[i][j + 1], d[i - 1][j]);
    }
  }
  for (int i = 0; i <= n; i++) {
    if (d[n][i] >= k) {
      cout << i << "\n";
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
