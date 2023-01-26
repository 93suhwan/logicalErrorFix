#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1') {
        cnt1++;
      }
      if (b[i] == '1') {
        cnt2++;
      }
    }
    if (cnt1 == cnt2) {
    } else if (cnt1 == cnt2 + 1) {
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
