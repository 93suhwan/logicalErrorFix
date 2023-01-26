#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool flag = false;
    string ans = "";
    for (int i = 0; i < n - 2; i++) {
      int l = ans.length();
      string s;
      cin >> s;
      if (i == 0) {
        ans += s;
        l += 2;
      } else {
        if (s[0] == ans[l - 1]) {
          ans += s[1];
        } else {
          ans += s;
          flag = true;
        }
      }
    }
    if (flag == false) ans += "a";
    cout << ans << endl;
  }
  return 0;
}
