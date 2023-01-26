#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
char get(int x, int y) {
  x %= 5;
  y %= 5;
  return 'a' + x * 5 + y;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int mn = (n % 2 == 1 ? m / 2 : 0);
    int mx = n * m / 2 - (m % 2 == 1 ? n / 2 : 0);
    if (mn <= k && k <= mx && (k - mn) % 2 == 0) {
      cout << "YES\n";
      vector<string> ans(n, string(m, '?'));
      if (n % 2 == 1) {
        for (int i = 0; i < m; i += 2) {
          ans[n - 1][i] = ans[n - 1][i + 1] = get(n - 1, i);
        }
        k -= mn;
      }
      for (int i = 0; i + 1 < n; i += 2) {
        for (int j = 0; j < m; j++) {
          ans[i][j] = ans[i + 1][j] = get(i, j);
        }
      }
      for (int j = 0; j < m; j += 2) {
        for (int i = 0; i + 1 < n; i += 2) {
          if (k > 0) {
            ans[i][j] = ans[i][j + 1] = get(i, j);
            ans[i + 1][j] = ans[i + 1][j + 1] = get(i + 1, j);
            k -= 2;
          }
        }
      }
      for (int i = 0; i < n; i++) cout << ans[i] << "\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
