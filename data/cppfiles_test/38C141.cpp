#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int c[m], t = 0;
  int b[n][m];
  for (int i = 0; i < m; i++) {
    if (a[0][i] == '.')
      b[0][i] = 0;
    else
      b[0][i] = INT_MIN;
    c[i] = INT_MIN;
  }
  for (int i = 0; i < n; i++) {
    if (a[i][0] == '.')
      b[i][0] = 0;
    else
      b[i][0] = INT_MIN;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X')
        b[i][j] = j;
      else if ((a[i - 1][j] == 'X' || a[i][j - 1] == 'X'))
        b[i][j] = max(b[i - 1][j], b[i][j - 1]);
      else
        b[i][j] = min(b[i - 1][j], b[i][j - 1]);
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) c[j] = max(c[j], b[i][j]);
  }
  int pre[m];
  pre[0] = c[0];
  for (int i = 1; i < m; i++) {
    pre[i] = max(pre[i - 1], c[i]);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (pre[r - 1] > l - 1 && pre[l - 1] <= l - 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1, l = 1;
  while (t--) {
    solve();
  }
}
