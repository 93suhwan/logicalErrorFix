#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      int k = s[i] - '0';
      if (k != 0 and i != a - 1) {
        ans = ans + s[i] - '0' + 1;
      } else if (k != 0 and i == a - 1) {
        ans = ans + s[i] - '0';
      }
    }
    cout << ans << endl;
  }
  return 0;
}
