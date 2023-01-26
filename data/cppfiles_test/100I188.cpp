#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[0] << endl;
    return;
  }
  sort(a, a + n);
  if (n == 2) {
    if (a[0] < 0)
      cout << a[1] - a[0] << endl;
    else
      cout << a[0] << endl;
    return;
  }
  int ans1 = a[n - 2] - a[n - 3];
  int ans2 = a[n - 1] - a[n - 2];
  int ans = ans1 > ans2 ? ans1 : ans2;
  cout << ans << endl;
}
