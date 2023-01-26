#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string a, b;
  cin >> n;
  cin >> a >> b;
  int res = 0, zero = 0, one = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      res += 2;
      zero = one = 0;
    } else if (a[i] == '0') {
      if (zero || one) {
        res += 2;
        zero = one = 0;
      } else {
        zero = 1;
      }
    } else if (a[i] == '1') {
      if (zero) {
        res += 2;
        zero = one = 0;
      } else {
        one = 1;
      }
    }
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
