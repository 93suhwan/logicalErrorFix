#include <bits/stdc++.h>
using namespace std;
const int N = 10010, INF = 1e8;
int n;
int a[N];
int f[N][5010];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= 2000; j++) f[i][j] = INF;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 2000; j++) {
        if (f[i - 1][j] > INF / 2) continue;
        f[i][max(0, j - a[i])] =
            min(f[i][max(0, j - a[i])], f[i - 1][j] + a[i]);
        f[i][j + a[i]] = min(f[i][j + a[i]], max(0, f[i - 1][j] - a[i]));
      }
    int ans = INF;
    for (int i = 0; i <= 2000; i++) ans = min(ans, f[n][i] + i);
    cout << ans << endl;
  }
  return 0;
}
