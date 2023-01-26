#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve() {
  string s;
  cin >> s;
  long long low = pow(10, s.size() - 1), high = pow(10, s.size()) - 1;
  if (low == 1) low--;
  long long ans = 0;
  for (; low <= high; low += 25) {
    string current = to_string(low);
    char c = '#';
    bool can = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '_') continue;
      if (s[i] == 'X') {
        if (c != '#' && c != current[i]) {
          can = 0;
          break;
        }
        c = current[i];
      } else if (s[i] != current[i]) {
        can = 0;
        break;
      }
    }
    ans += can;
  }
  cout << ans << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
