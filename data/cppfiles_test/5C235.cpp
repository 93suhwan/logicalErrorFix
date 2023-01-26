#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i = 0, ans = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    while (i < n) {
      if (b[i] == '1') {
        if (a[i] == '0')
          ans++;
        else if (i >= 1 && a[i - 1] == '1') {
          ans++;
          a[i - 1] = '0';
        } else if (a[i + 1] == '1') {
          ans++;
          a[i + 1] = '0';
        }
      }
      i++;
    }
    cout << ans << endl;
  }
  return 0;
}
