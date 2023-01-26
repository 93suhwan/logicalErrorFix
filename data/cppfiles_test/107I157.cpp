#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) <= 1 && a + b + 2 <= n) {
    if (a <= b) {
      int i = 3 - 2 * (a < b), j = 2 + 2 * (a < b), k = min(a, b);
      cout << 1 + (a < b) << " ";
      for (; max(i, j) <= n && k > 0; i += 2, j += 2, k--)
        cout << i << " " << j << " ";
      for (int t = min(i, j) + 2 * (a < b); t <= n; t++) cout << t << " ";
    } else {
      int i = n - 1, j = n, k = max(a, b);
      for (; min(i, j) > 0 && k > 0; i -= 2, j -= 2, k--)
        cout << i << " " << j << " ";
      for (int t = max(i, j); t > 0; t--) cout << t << " ";
    }
  } else {
    cout << -1 << endl;
  }
}
