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
      b[0][i] = -10000000;
    else
      b[0][i] = INT_MIN;
    c[i] = INT_MIN;
  }
  for (int i = 0; i < n; i++) {
    if (a[i][0] == '.')
      b[i][0] = -10000000;
    else
      b[i][0] = INT_MIN;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] == '.' && b[i - 1][j] == -10000000)
        b[i][j] = -10000000;
      else if (a[i][j] == '.' && b[i][j - 1] == -10000000)
        b[i][j] = -10000000;
      else if (a[i][j] == '.' && b[i - 1][j] == INT_MIN &&
               b[i][j - 1] == INT_MIN)
        b[i][j] = j;
      else if (a[i][j] == 'X')
        b[i][j] = INT_MIN;
      else
        b[i][j] = min(b[i - 1][j], b[i][j - 1]);
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) c[j] = max(c[j], b[i][j]);
  }
  set<pair<int, int>> p;
  for (int i = 0; i < m; i++) {
    int t = 0;
    for (int j = i; j < m; j++) {
      if (c[j] <= i || c[j] == -10000000 || c[j] == INT_MIN)
        p.insert({i + 1, j + 1});
      else
        break;
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (p.find({l, r}) != p.end())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1, l = 1;
  while (t--) {
    solve();
  }
}
