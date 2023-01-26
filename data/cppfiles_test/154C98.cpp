#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  reverse(a, a + 3);
  if (a[0] == a[1] && a[2] % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  if (a[1] == a[2] && a[0] % 2 == 0) {
    cout << "YES" << endl;
    return;
  }
  if (a[0] == a[1] + a[2]) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
