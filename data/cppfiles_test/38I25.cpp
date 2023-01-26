#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int> > dp(n, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    if (a[i][0] == '.') {
      dp[i][0] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (a[0][i] == '.') {
      dp[0][i] = 1;
    }
  }
  vector<int> b(m, 0);
  vector<int> p(m + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i != 0 && j != 0) {
        if (a[i][j] == '.' && a[i - 1][j] != '.' && a[i][j - 1] != '.') {
          b[j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    p[i + 1] = p[i] + b[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (p[r] - p[l] > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
