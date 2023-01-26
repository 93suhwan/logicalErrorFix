#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a[3], m;
  cin >> a[0] >> a[1] >> a[2] >> m;
  int minsum = 0, maxsum = 0;
  maxsum = a[0] + a[1] + a[2] - 3;
  sort(a, a + 3);
  a[2] = a[2] - a[0];
  a[0] = 0;
  sort(a, a + 3);
  a[2] = a[2] - a[1];
  a[1] = 0;
  minsum = a[2] / 2;
  if (m >= minsum && m <= maxsum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
