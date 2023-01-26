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
  vector<int> sum(m, 0);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (g[i][j] == 'X') continue;
      if (g[i - 1][j] == 'X' && g[i][j - 1] == 'X') {
        sum[j] = 1;
      }
    }
  }
  for (int i = 1; i < m; i++) {
    sum[i] += sum[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    if (sum[r] - sum[l] == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
