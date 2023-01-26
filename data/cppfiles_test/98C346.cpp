#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 1;
void solve() {
  string s, t;
  cin >> s;
  cin >> t;
  map<char, int> m;
  for (int i = 0; i < s.length(); i++) {
    m[s[i]] = i + 1;
  }
  int ans = 0;
  for (int i = 1; i < t.length(); i++) {
    ans += abs(m[t[i]] - m[t[i - 1]]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
