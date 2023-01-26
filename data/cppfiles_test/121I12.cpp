#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  int n, cnt, cnt1, i, x, y;
  string a, b;
  bool ok;
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    cnt = ok = cnt1 = x = y = 0;
    for (i = 0; i < n; i++) {
      if (a[i] != b[i]) cnt++;
      if (a[i] == '1') ok = true;
      if (a[i] == '1') x++;
      if (b[i] == '1') y++;
    }
    if (cnt != n && (ok || cnt == 0)) {
      if (n - x + 1 == y)
        cout << min(cnt, n - cnt) << '\n';
      else
        cout << cnt << '\n';
    } else
      cout << -1 << '\n';
  }
}
