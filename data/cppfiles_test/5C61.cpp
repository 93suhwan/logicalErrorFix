#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == '0' && b[i] == '1')
        ans++;
      else if (i > 0 && a[i - 1] == '1' && b[i] == '1') {
        ans++;
        a[i - 1] = '0';
      } else if (i < n - 1 && a[i + 1] == '1' && b[i] == '1') {
        ans++;
        a[i + 1] = '0';
      }
    }
    cout << ans << endl;
  }
}
