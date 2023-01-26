#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a[6], ans = 0;
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  if (a[2] == a[4] || a[3] == a[5]) {
    cout << ans << "\n";
  } else if (a[4] > a[2]) {
    cout << (a[4] - a[2]) << "\n";
  } else if (a[5] > a[3]) {
    cout << (a[5] - a[3]) << "\n";
  } else {
    cout << a[0] << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
