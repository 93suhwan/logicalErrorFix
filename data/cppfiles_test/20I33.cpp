#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int n, m, a[N][N], sum[N][N], pref[N];
string str[N];
int get(int x, int y, int x2, int y2) {
  int res = sum[x2][y2] - sum[x2][y - 1] - sum[x - 1][y2] + sum[x - 1][y - 1];
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
      cin >> str[i];
      for (int j = 1; j <= m; j++) {
        a[i][j] = str[i][j - 1] - '0';
        sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      }
    }
    for (int i = 1; i < n; i++) {
      for (int i2 = i + 4; i2 <= n; i2++) {
        int mx = -1e9, j2 = 1, tmp;
        for (int j = 1; j <= m; j++) {
          while (j - j2 >= 3) {
            mx =
                max(mx, pref[j2] - ((i2 - i - 1) - get(i + 1, j2, i2 - 1, j2)));
            pref[j2] = 0;
            j2++;
          }
          pref[j] = get(i + 1, j, i2 - 1, j);
          pref[j] += !a[i][j], pref[j] += !a[i2][j];
          pref[j] += pref[j - 1];
          tmp = pref[j - 1] + ((i2 - i - 1) - get(i + 1, j, i2 - 1, j));
          cout << j << ' ' << tmp << ' '
               << ((i2 - i - 1) - get(i + 1, j, i2 - 1, j)) << " how\n";
          ans = min(ans, tmp - mx);
        }
        for (int j = m; j >= max(0, m - 5); j--) pref[j] = 0;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
