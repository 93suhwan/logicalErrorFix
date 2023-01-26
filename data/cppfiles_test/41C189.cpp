#include <bits/stdc++.h>
using namespace std;
int ct[3][3][3][200010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, i, j, k, l, r, x, ans, INF = 1LL << 60;
  string s;
  cin >> n >> m >> s;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        if ((i == j) || (j == k) || (k == i)) continue;
        ct[i][j][k][0] = 0;
        for (x = 1; x <= n; x++) {
          ct[i][j][k][x] = ct[i][j][k][x - 1];
          if ((x % 3 == 0) && (s[x - 1] - 'a' != i)) continue;
          if ((x % 3 == 1) && (s[x - 1] - 'a' != j)) continue;
          if ((x % 3 == 2) && (s[x - 1] - 'a' != k)) continue;
          ct[i][j][k][x]++;
        }
      }
    }
  }
  while (m--) {
    cin >> l >> r;
    if (l == r)
      ans = 0;
    else if (l + 1 == r) {
      if (s[l - 1] == s[r - 1])
        ans = 1;
      else
        ans = 0;
    } else {
      ans = INF;
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
          for (k = 0; k < 3; k++) {
            if ((i == j) || (j == k) || (k == i)) continue;
            x = ct[i][j][k][r] - ct[i][j][k][l - 1];
            ans = min(ans, r - l + 1 - x);
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
