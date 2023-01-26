#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int M = 1e5 + 10;
const int mod = 1e9 + 7;
string s[N];
int vis[N];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int _, n, m, l, r, q;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> row;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j && i) {
        if (s[i][j] == '.' && s[i][j - 1] == 'X' && s[i - 1][j] == 'X') {
          if (!vis[j]) {
            row.push_back(j);
            vis[j] = 1;
          }
        }
      }
    }
  }
  sort(row.begin(), row.end());
  cin >> q;
  while (q--) {
    cin >> l >> r;
    int h = lower_bound(row.begin(), row.end(), l) - row.begin();
    if (h < row.size() && row[h] <= r) {
      cout << "NO" << '\n';
    } else
      cout << "YES" << '\n';
  }
  return 0;
}
