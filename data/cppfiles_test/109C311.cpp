#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (i = 0; i < n; i++) {
      if (s[i] != '0') {
        ans += (s[i] - ('0'));
        if (i != n - 1) ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
