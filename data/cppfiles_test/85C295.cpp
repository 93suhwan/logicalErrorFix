#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int cnt = 0, ans = 2;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1])
        continue;
      else {
        if (s[i - 1] == '0') cnt++;
      }
    }
    if (s[s.size() - 1] == '0') cnt++;
    ans = min(ans, cnt);
    cout << ans << endl;
  }
}
