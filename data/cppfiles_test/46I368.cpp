#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N], vis[N][N], pos[N];
int main() {
  ios::sync_with_stdio(0);
  long long ans = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i += 2) {
    if (a[i] != a[i + 1]) pos[i] = 1;
  }
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; i += 2) {
    int t = i;
    while (!pos[t + 2] && t + 2 <= n) t += 2;
    cout << "t:" << t << '\n';
    if (t == i)
      vis[i][i + 1] = 0;
    else {
      for (int j = i + 1; j <= t + 1; j += 2) vis[i][j] = 1;
    }
    vis[i][i] = 0;
  }
  if (n % 2 == 0 && a[n] == a[n - 1]) vis[n - 1][n] = 1;
  for (int i = 1; i <= n; i += 2) {
    ans += min(a[i], a[i + 1]);
    if (i <= n - 3 && min(a[i] - a[i + 1], a[i + 3] - a[i + 2]) >= 0)
      ans += min(a[i] - a[i + 1], a[i + 3] - a[i + 2]) + 1;
    for (int j = i + 5; j <= n; j += 2) {
      if (vis[i + 2][j - 2] && a[i] >= a[i + 1] && a[j] >= a[j - 1])
        ans += 1 + min(a[i] - a[i + 1], a[j] - a[j - 1]);
    }
  }
  cout << ans << '\n';
  return 0;
}
