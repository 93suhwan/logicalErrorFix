#include <bits/stdc++.h>
using namespace std;
int t, n, a[2][100009], p1[100009], p2[100009], ans;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[0][i];
    for (int i = 1; i <= n; i++) cin >> a[1][i];
    for (int i = 1; i <= n + 1; i++) {
      p1[i] = 0;
      p2[i] = 0;
    }
    for (int i = n; i >= 1; i--) p1[i] = p1[i + 1] + a[0][i];
    for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] + a[1][i];
    ans = (1 << 30);
    for (int i = 1; i <= n; i++) ans = min(ans, max(p1[i + 1], p2[i - 1]));
    cout << ans << endl;
  }
  return 0;
}
