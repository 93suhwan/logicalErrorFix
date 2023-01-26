#include <bits/stdc++.h>
using namespace std;
using ii = pair<long long, long long>;
void solve() {
  long long a[3];
  for (long long i = 0; i < 3; i++) {
    cin >> a[i];
  }
  sort(a, a + 3);
  if (a[1] == a[2]) swap(a[0], a[2]);
  if (a[0] == a[1]) {
    if (a[1] == a[2]) {
      if (a[1] % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      return;
    }
    if (a[2] % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else {
    if (a[2] == a[0] + a[1])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
