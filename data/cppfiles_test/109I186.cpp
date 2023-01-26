#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, ans;
    int count = ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] != '0') {
        count++;
        ans += ((int)s[i] - 48);
      }
    }
    cout << ans << " ";
    if (s[n - 1] != '0')
      cout << ans + count - 1 << endl;
    else
      cout << ans + count << endl;
  }
  return 0;
}
