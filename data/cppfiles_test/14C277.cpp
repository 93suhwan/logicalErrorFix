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
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        int temp = ans[i][j];
        if (a[i + 1] == i - j + 1) temp++;
        ans[i + 1][j] = max(temp, ans[i + 1][j]);
        ans[i + 1][j + 1] = max(ans[i + 1][j + 1], ans[i][j]);
      }
    }
    int anss = INT_MAX;
    for (int i = 0; i <= n; i++) {
      if (ans[n][i] >= k) anss = min(anss, i);
    }
    if (anss == INT_MAX)
      cout << -1 << endl;
    else
      cout << anss << endl;
  }
  return 0;
}
