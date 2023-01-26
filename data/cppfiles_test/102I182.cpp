#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int x = 1, y = 1;
  for (auto i : s) {
    if (i == 'R') {
      if (y > 1)
        y--;
      else
        break;
    } else if (i == 'U') {
      if (x < n)
        x++;
      else
        break;
    } else if (i == 'L') {
      if (y < m)
        y++;
      else
        break;
    } else {
      if (x > 1)
        x--;
      else
        break;
    }
  }
  cout << x << ' ' << y << '\n';
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
