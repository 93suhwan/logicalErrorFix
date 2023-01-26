#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n;
string a[2];
int main() {
  cin >> t;
  while (t--) {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < 2; i++) cin >> a[i];
    if (a[1][0] == '1') {
      if (a[0][0] == '0') {
        ans++;
        a[0][0] = '2';
      } else if (a[0][1] == '1') {
        ans++;
        a[0][1] = '2';
      }
    }
    for (int i = 1; i < n - 1; i++) {
      if (a[1][i] == '0') continue;
      if (a[0][i] == '0') {
        ans++;
        a[0][0] = '2';
      } else if (a[0][i - 1] == '1') {
        ans++;
        a[0][i - 1] = '1';
      } else if (a[0][i + 1] == '1') {
        ans++;
        a[0][i + 1] = '2';
      }
    }
    if (a[1][n - 1] == '1') {
      if (a[0][n - 1] == '0') {
        ans++;
        a[0][n - 1] = '2';
      } else if (a[0][n - 2] == '1') {
        ans++;
        a[0][1] = '2';
      }
    }
    cout << ans << endl;
  }
  return 0;
}
