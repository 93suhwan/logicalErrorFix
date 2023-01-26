#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    string ans;
    string s;
    cin >> n;
    int l = -1, r = -1;
    cin >> s;
    if (s[0] == 'a')
      l = 0;
    else
      l = 1;
    if (s[1] == 'a')
      r = 0;
    else
      r = 1;
    ans = ans + s;
    int check = 0;
    for (int i = 1; i < n - 2; i++) {
      cin >> s;
      if (r == 0 && s[0] == 'b') {
        check = 1;
        ans = ans + s;
      } else if (r == 1 && s[0] == 'a') {
        check = 1;
        ans = ans + s;
      } else
        ans = ans + s[1];
      if (s[0] == 'a')
        l = 0;
      else
        l = 1;
      if (s[1] == 'a')
        r = 0;
      else
        r = 1;
    }
    if (check == 1)
      cout << ans << "\n";
    else
      cout << ans + 'a' << "\n";
  }
  return 0;
}
