#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 5;
const int modu = 1e9 + 7;
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
int a[maxn], n, k;
int f[maxn][maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j) f[i][j] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= i; ++j) {
        f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]);
        if (j == a[i]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
      }
    bool flag = true;
    for (int i = n; i >= 1; --i)
      if (f[n][i] >= k) {
        cout << n - i << "\n";
        flag = false;
        break;
      }
    if (flag) cout << "-1\n";
  }
  return 0;
}
