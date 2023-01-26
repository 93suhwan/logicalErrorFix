#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto solve = [&]() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int u = 0, l = 0, d = 0, r = 0;
    int x = 0, y = 0;
    for (auto ch : s) {
      if (ch == 'L') {
        if (r - y == m - 1) {
          break;
        }
        l = min(l, --y);
      } else if (ch == 'R') {
        if (y - l == m - 1) {
          break;
        }
        r = max(r, ++y);
      } else if (ch == 'U') {
        if (d - x == n - 1) {
          break;
        }
        u = min(u, --x);
      } else if (ch == 'D') {
        if (x - u == n - 1) {
          break;
        }
        d = max(d, ++x);
      }
    }
    cout << -u + 1 << ' ' << -l + 1 << '\n';
  };
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
