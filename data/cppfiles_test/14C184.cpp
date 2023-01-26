#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
int t, n, k;
int a[N];
int f[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    memset(f, 0, sizeof f);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    f[0][0] = 0;
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        f[i][j] = max(f[i - 1][j - 1], f[i - 1][j] + (i - j == a[i] ? 1 : 0));
        if (f[i][j] >= k) ans = min(ans, j);
      }
    }
    if (ans == 0x3f3f3f3f)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
