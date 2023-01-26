#include <bits/stdc++.h>
using namespace std;
int T, n, m, sum[405][405], a[405][405];
char s[405][405];
inline int get(int x1, int y1, int x2, int y2, int opt) {
  if (opt == 1)
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +
           sum[x1 - 1][y1 - 1];
  else
    return (x2 - x1 + 1) * (y2 - y1 + 1) -
           (sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +
            sum[x1 - 1][y1 - 1]);
}
inline int getdoor(int left, int right, int up, int down) {
  return get(up + 1, right, down - 1, right, 0) +
         get(up + 1, left, down - 1, left, 0) +
         get(up, left + 1, up, right - 1, 0) +
         get(down, left + 1, down, right - 1, 0) +
         get(up + 1, left + 1, down - 1, right - 1, 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = (1); i <= (n); i++) cin >> (s[i] + 1);
    int ans = 1e9;
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (m); j++)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                    (a[i][j] = (s[i][j] == '1'));
    for (int up = (1); up <= (n); up++)
      for (int down = (up + 4); down <= (n); down++) {
        int left = 1;
        ans = min(ans, getdoor(1, 4, up, down));
        for (int right = (5); right <= (m); right++) {
          ans = min(ans, min(getdoor(right - 3, right, up, down),
                             getdoor(left, right, up, down)));
          if (getdoor(left, right - 3, up, down) + !a[up][right - 3] +
                  !a[down][right - 3] >
              2 * get(up + 1, right - 3, down - 1, right - 3, 0))
            left = right - 3;
        }
      }
    cout << ans << '\n';
  }
  return 0;
}
