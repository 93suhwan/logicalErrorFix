#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a, s;
  cin >> a >> s;
  string ans = "";
  long long int l = a.size() - 1;
  for (long long int i = s.size() - 1; i >= 0; i--) {
    if (l < 0)
      ans += s[i];
    else {
      if (s[i] >= a[l]) {
        ans += s[i] - a[l] + '0';
        l--;
      } else {
        if (i) {
          long long int f = stoi(s.substr(i - 1, 2));
          i--;
          if (f > 18 || f < a[l] - '0') {
            cout << "-1\n";
            return;
          } else {
            ans += f - (a[l] - '0') + '0';
            l--;
          }
        } else {
          cout << "-1\n";
          return;
        }
      }
    }
  }
  while (ans.size() && ans.back() == '0') ans.pop_back();
  reverse(ans.begin(), ans.end());
  if (l >= 0) {
    cout << "-1\n";
    return;
  } else
    cout << ans << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i < t + 1; i++) {
    solve();
  }
  return 0;
}
