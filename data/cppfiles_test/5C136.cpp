#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int x = 0; x < n; x++) {
      if (b[x] == '1') {
        if (a[x] == '0')
          ans++;
        else if (x > 0 && a[x - 1] == '1')
          ans++;
        else if (x + 1 < n && a[x + 1] == '1') {
          ans++;
          a[x + 1] = '2';
        }
      }
    }
    cout << ans << endl;
  }
}
