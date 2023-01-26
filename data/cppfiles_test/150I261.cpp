#include <bits/stdc++.h>
using namespace std;
constexpr size_t MAXN = 1e3 + 5;
int a[MAXN], b[MAXN][4];
inline int Cal(int x, int y, int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = 1e8;
    for (int j = 0; j <= x; j++)
      for (int k = 0; k <= y; k++)
        if ((a[i] - j - k * 2) % 3 == 0) tmp = min(tmp, (a[i] - j - k * 2) / 3);
    if (tmp == 1e8) return tmp;
    ans = max(ans, tmp);
  }
  return ans + x + y;
}
inline void Solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 1e8;
  for (int i = 0; i <= 3; i++)
    for (int j = 0; j <= 3; j++) ans = min(ans, Cal(i, j, n));
  cout << ans << '\n';
}
signed main(void) {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) Solve();
}
