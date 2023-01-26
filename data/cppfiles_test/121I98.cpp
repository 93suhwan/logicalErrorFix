#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, one_a = 0, one_b = 0, ans = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') one_a++;
    if (b[i] == '1') one_b++;
    if (a[i] == b[i]) ans++;
  }
  if (one_a != one_b && (n - one_a) + 1 != one_b) {
    cout << -1 << endl;
    return;
  }
  ans = min(ans, n - ans);
  cout << ans << endl;
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
