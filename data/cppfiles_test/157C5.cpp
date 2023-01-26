#include <bits/stdc++.h>
using namespace std;
int n, k, c[5100][5100];
string s;
int sum[5100];
signed main() {
  for (int i = 0; i <= 5000; i++) c[i][0] = 1;
  for (int i = 1; i <= 5000; i++)
    for (int j = 1; j <= 5000; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      if (c[i][j] >= 998244353) c[i][j] -= 998244353;
    }
  cin >> n >> k;
  cin >> s;
  s = "$" + s;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (s[i] == '1');
  }
  int ans = 1;
  if (sum[n] >= k)
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        if (sum[j] - sum[i - 1] <= k) {
          int v1 = sum[j] - sum[i - 1], v0 = j - i + 1 - v1;
          v1 -= (s[j] == '0') + (s[i] == '0');
          v0 -= (s[j] == '1') + (s[i] == '1');
          if (v0 >= 0 && v1 >= 0) {
            ans += c[v0 + v1][v0];
            if (ans >= 998244353) ans -= 998244353;
          }
        }
      }
  cout << ans << endl;
  return 0;
}
