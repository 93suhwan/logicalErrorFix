#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    string a[n - 2];
    for (i = 0; i < n - 2; i++) {
      cin >> a[i];
    }
    string ans = "";
    ans += a[0][0];
    for (i = 1; i < n - 2; i++) {
      if (a[i][0] == a[i - 1][1])
        ans += a[i][0];
      else
        ans += (a[i - 1][1] + a[i][0]);
    }
    ans += a[n - 3][1];
    if (ans.size() < n) ans += a[n - 3][1];
    cout << ans << endl;
  }
}
