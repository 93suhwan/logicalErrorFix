#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
void solve() {
  string s;
  cin >> s;
  if (s.length() % 2 == 1) {
    cout << "NO\n";
    return;
  } else {
    for (int i = 0; i + s.length() / 2 < s.length(); i += 1) {
      if (s[i] != s[i + s.length() / 2]) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
