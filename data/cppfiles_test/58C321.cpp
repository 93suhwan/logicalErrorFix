#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char a[2][n];
    for (int i = 0; i < n; i++) cin >> a[0][i];
    for (int i = 0; i < n; i++) cin >> a[1][i];
    bool can = true;
    if (a[0][0] == '0' && a[1][n - 1] == '0') {
      for (int i = 1; i < n - 1; i++) {
        if (a[0][i] == '0' || a[1][i] == '0')
          continue;
        else {
          can = false;
          break;
        }
      }
    } else
      can = false;
    if (can)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
