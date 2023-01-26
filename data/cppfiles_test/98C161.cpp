#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k[256];
  memset(k, 0, sizeof k);
  string s;
  for (int i = 1; i <= 26; i++) {
    char c;
    cin >> c;
    k[c] = i;
  }
  cin >> s;
  int ans = 0;
  for (int i = 1; i < s.size(); i++) {
    ans += abs(k[s[i]] - k[s[i - 1]]);
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
