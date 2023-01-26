#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector<vector<int> > a(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      a[i + 1][j + 1] = a[i][j + 1] + a[i + 1][j] - a[i][j];
      if (i > 0 && j > 0 && s[i - 1][j] == 'X' && s[i][j - 1] == 'X')
        ++a[i + 1][j + 1];
    }
  int Q;
  cin >> Q;
  for (int t = 0; t < Q; ++t) {
    int x1, x2;
    cin >> x1 >> x2;
    --x1;
    --x2;
    if (a[n][x2 + 1] - a[n][x1 + 1])
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
