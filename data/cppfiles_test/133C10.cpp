#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> a(n - 2);
    for (int i = 0; i < n - 2; i++) cin >> a[i];
    string ans = "";
    int b = 0;
    ans += a[0][0];
    for (int i = 1; i < n - 2; i++) {
      if (a[i - 1][1] != a[i][0]) {
        ans += a[i - 1][1];
        b = 1;
      }
      ans += a[i][0];
    }
    ans += a[n - 3][1];
    if (b == 0) ans += a[n - 3][1];
    cout << ans << endl;
  }
  return 0;
}
