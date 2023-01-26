#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int x = 0, y = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == 'R') {
      if (y > 0) y--;
    } else if (s[i] == 'U') {
      if (x < n - 1) x++;
    } else if (s[i] == 'L') {
      if (y < m - 1) y++;
    } else {
      if (x > 0) x--;
    }
  }
  cout << x + 1 << ' ' << y + 1 << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    solve();
  }
}
