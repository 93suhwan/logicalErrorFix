#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
char ans[maxn][maxn];
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int ok = 1;
    int tot = n * m / 2;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ans[i][j] = '#';
      }
    }
    int nn = n, mm = m;
    if (n % 2) {
      k -= m / 2;
      tot -= m / 2;
      int cnt = 1;
      for (int j = 1; j <= m; j += 2) {
        if (cnt % 2)
          ans[n][j] = ans[n][j + 1] = 'o';
        else
          ans[n][j] = ans[n][j + 1] = 'p';
        cnt++;
      }
      n--;
    }
    if (m % 2) {
      tot -= n / 2;
      int cnt = 1;
      for (int i = 1; i <= n; i += 2) {
        if (cnt % 2)
          ans[i][m] = ans[i + 1][m] = 'x';
        else
          ans[i][m] = ans[i + 1][m] = 'y';
        cnt++;
      }
      m--;
    }
    if (k < 0 || k % 2 || k > tot) {
      cout << "NO\n";
      continue;
    }
    int cnt = 1;
    for (int j = 1; j <= m; j += 2) {
      cnt++;
      for (int i = 1; i <= n; i++) {
        if (k != 0) {
          if ((i + cnt) & 1)
            ans[i][j] = ans[i][j + 1] = 'a';
          else
            ans[i][j] = ans[i][j + 1] = 'b';
          k--;
        }
        if (!k) break;
      }
      if (!k) break;
    }
    for (int i = 1; i <= n; i += 2) {
      cnt++;
      for (int j = 1; j <= m; j++) {
        if (ans[i][j] == '#') {
          if ((j + cnt) & 1)
            ans[i][j] = ans[i + 1][j] = 'k';
          else
            ans[i][j] = ans[i + 1][j] = 'v';
        }
      }
    }
    cout << "YES\n";
    for (int i = 1; i <= nn; i++) {
      for (int j = 1; j <= mm; j++) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
