#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  reverse(s.begin(), s.end());
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '0') {
      res += (s[i] - '0') + (i != 0);
    }
  }
  cout << res << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
