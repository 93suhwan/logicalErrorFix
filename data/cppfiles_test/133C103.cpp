#include <bits/stdc++.h>
using namespace std;
int t;
int n;
string s[200], ans;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    ans = "";
    bool check = false;
    for (int i = 1; i <= n - 2; ++i) {
      cin >> s[i];
    }
    if (n == 3) {
      if (s[1][0] == 'a')
        cout << 'b' << s[1] << endl;
      else
        cout << 'a' << s[1] << endl;
      continue;
    }
    ans += s[1];
    int w = 2;
    for (int i = 2; i <= n - 2; ++i) {
      if (ans[w - 1] == s[i][0]) {
        ans += s[i][1];
        ++w;
      } else {
        ans += s[i];
        w += 2;
      }
    }
    if (w == n)
      cout << ans << endl;
    else {
      if (ans[w - 1] == 'a')
        cout << ans << 'b' << endl;
      else
        cout << ans << 'a' << endl;
    }
  }
  return 0;
}
