#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) ans[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        ans[i][j] = max(ans[i - 1][j], ans[i][j]);
        ans[i][j + 1] = max(ans[i][j + 1], ans[i - 1][j] + (j + 1 == a[i]));
      }
    }
    int anss = INT_MAX;
    for (int i = 0; i <= n; i++) {
      if (ans[n][i] >= k) anss = min(anss, n - i);
    }
    if (anss == INT_MAX)
      cout << -1 << endl;
    else
      cout << anss << endl;
  }
  return 0;
}
