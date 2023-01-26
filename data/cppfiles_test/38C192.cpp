#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = 2 * acos(0.0);
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &element : a) cin >> element;
  int q;
  vector<vector<int> > ans(n, vector<int>(m));
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X') ans[i][j] = 1;
      ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
    }
  }
  cin >> q;
  while (q--) {
    int x1, x2;
    cin >> x1 >> x2;
    x1--;
    x2--;
    if (x2 - x1 >= 1) {
      int curr = ans[n - 1][x2] - ans[n - 1][x1];
      if (curr > 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      cout << "YES\n";
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
