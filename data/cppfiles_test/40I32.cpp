#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, ans;
  int pre[2][100005];
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> pre[1][i];
    pre[0][n] = pre[1][n];
    for (int i = n - 1; i > 0; i--) pre[0][i] = pre[0][i + 1] + pre[1][n - 1];
    cin >> pre[1][1];
    for (int i = 2; i <= n; i++) {
      cin >> pre[1][i];
      pre[1][i] += pre[1][i - 1];
    }
    ans = min(pre[0][2], pre[1][n - 1]);
    for (int i = 2; i <= n; i++)
      ans = min(ans, max(pre[0][i + 1], pre[1][i - 1]));
    cout << ans << endl;
  }
  return 0;
}
