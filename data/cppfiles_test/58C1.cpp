#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[0][i] == '1' && a[1][i] == '1') {
        ok = false;
        break;
      }
    }
    if (a[1][n - 1] == '1') ok = false;
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
