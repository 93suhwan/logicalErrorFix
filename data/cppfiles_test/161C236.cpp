#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  map<pair<int, int>, bool> mp;
  vector<int> l1(n), r1(n);
  for (int i = 0; i < n; i++) {
    cin >> l1[i] >> r1[i];
    mp[{l1[i], r1[i]}] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int d = l1[i]; d <= r1[i]; d++) {
      if ((d == l1[i] or mp[{l1[i], (d - 1)}] == true) &&
          (d == r1[i] or mp[{(d + 1), r1[i]}] == true)) {
        cout << l1[i] << " " << r1[i] << " " << d << endl;
        break;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
