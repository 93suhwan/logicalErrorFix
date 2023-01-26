#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  if (a == b) {
    cout << "0\n";
    return;
  }
  int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0') a0++;
    if (a[i] == '1') a1++;
    if (b[i] == '0') b0++;
    if (b[i] == '1') b1++;
  }
  int ans = inf;
  if (a1 == b1) {
    int cur = 0;
    for (int i = 0; i < n; i++)
      if (b[i] == '1' && a[i] == '0') cur += 2;
    ans = min(ans, cur);
  }
  if (a0 + 1 == b1) {
    int c10 = 0, c11 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '0') c10++;
      if (a[i] == '1' && b[i] == '1') c11++;
    }
    if (c11 != 0)
      ans = min(ans, 2 * c11 - 1);
    else
      ans = min(ans, 3);
  }
  if (ans == inf) ans = -1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}
