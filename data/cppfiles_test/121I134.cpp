#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, one_a = 0, one_b = 0, ans = 0, flag_e = 0, flag_u = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') one_a++;
    if (b[i] == '1') one_b++;
    if (a[i] == b[i]) {
      if (a[i] == '1') flag_e = 1;
      ans++;
    }
    if (a[i] != b[i] && a[i] == '1') flag_u = 1;
  }
  if (ans == n) ans = 0;
  if (one_a != one_b && (n - one_a) + 1 != one_b) {
    cout << -1 << endl;
    return;
  }
  if (ans <= (n - ans) && flag_e == 1)
    cout << ans << endl;
  else if (flag_u == 0)
    cout << ans << endl;
  else if (ans >= (n - ans) && flag_u == 1)
    cout << (n - ans) << endl;
  else if (flag_e == 0)
    cout << (n - ans) << endl;
  else
    cout << "how" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
