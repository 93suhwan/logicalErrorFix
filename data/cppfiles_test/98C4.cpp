#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s;
  cin >> t;
  map<char, int> pos;
  for (int i = 0; i < (long long int)s.size(); i++) {
    pos[s[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i < (long long int)t.size(); i++) {
    ans += abs(pos[t[i]] - pos[t[i - 1]]);
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
