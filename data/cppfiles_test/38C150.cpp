#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> s(n - 1, vector<int>(m - 1));
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      s[i][j] = (a[i + 1][j] == 'X' && a[i][j + 1] == 'X') +
                (i ? s[i - 1][j] : 0) + (j ? s[i][j - 1] : 0) -
                (i && j ? s[i - 1][j - 1] : 0);
    }
  }
  auto sum = [&](int c, int cc) {
    return (n - 2 >= 0
                ? ((cc ? s[n - 2][cc - 1] : 0) - (c ? s[n - 2][c - 1] : 0))
                : 0);
  };
  int q;
  cin >> q;
  while (q--) {
    int c, cc;
    cin >> c >> cc;
    --c;
    --cc;
    cout << (sum(c, cc) > 0 ? "NO" : "YES") << '\n';
  }
  return 0;
}
