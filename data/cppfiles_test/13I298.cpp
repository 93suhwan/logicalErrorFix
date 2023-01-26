#include <bits/stdc++.h>
using namespace std;
char s[105][105];
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int r = n, c = m;
    int t = 0;
    if (r & 1) {
      for (int i = 1; i <= m; i += 2)
        s[n][i] = s[n][i + 1] = char(t + 'a'), t = (t + 1) % 26;
      r--;
      k -= m / 2;
    } else if (c & 1) {
      for (int i = 1; i <= n; i += 2)
        s[i][m] = s[i + 1][m] = char(t + 'a'), t = (t + 1) % 26;
      c--;
    }
    bool ok = k >= 0 && k <= r * c / 2 && (k % 2 == 0);
    cout << (ok ? "YES" : "NO") << "\n";
    int x = 1, y = 1;
    for (int i = 0; i < k; i += 2) {
      s[x][y] = s[x][y + 1] = char(t + 'a'), t = (t + 1) % 26;
      s[x + 1][y] = s[x + 1][y + 1] = char(t + 'a'), t = (t + 1) % 26;
      y += 2;
      if (y > c) y -= c, x += 2;
    }
    for (int i = 0; i < r * c / 2 - k; i += 2) {
      s[x][y] = s[x + 1][y] = char(t + 'a'), t = (t + 1) % 26;
      s[x][y + 1] = s[x + 1][y + 1] = char(t + 'a'), t = (t + 1) % 26;
      y += 2;
      if (y > c) y -= c, x += 2;
    }
    if (ok)
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << s[i][j];
        cout << "\n";
      }
  }
}
