#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, ans = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = '0' + a;
    a = a + '0';
    for (int i = 1; i <= n; i++) {
      if (b[i - 1] == '1') {
        if (a[i] == '0')
          ans++;
        else if (a[i - 1] == '1') {
          ans++;
          a[i - 1] = '0';
        } else if (a[i + 1] == '1') {
          ans++;
          a[i + 1] = '0';
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
