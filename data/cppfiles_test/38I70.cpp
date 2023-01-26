#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto& s : g) {
    cin >> s;
  }
  vector<int> sum(m, 0), sum2(m, 0);
  vector<int> ok(m, 1);
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (g[i][j] != 'X') {
        ok[j] = 0;
        break;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (g[i][j] == 'X') continue;
      if (g[i - 1][j] == 'X' && g[i][j - 1] == 'X') {
        sum[j] = 1;
      }
    }
  }
  sum2[0] = ok[0];
  for (int i = 1; i < m; i++) {
    sum[i] += sum[i - 1];
    sum2[i] += sum2[i - 1] + ok[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      if (ok[l - 1]) {
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
      continue;
    }
    if (sum[r - 1] - sum[l - 1] > 0) {
      cout << "NO\n";
      continue;
    }
    if (sum2[r - 1] - sum2[l - 1] + ok[l - 1] == r - l + 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}
