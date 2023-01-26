#include <bits/stdc++.h>
using namespace std;
int t, n, pl;
string s;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> t;
  for (int qqw = 1; qqw <= t; qqw++) {
    cin >> n;
    cin >> s;
    pl = -1;
    for (int i = 1; i <= n; i++)
      if (s[i - 1] == '0') pl = i;
    if (pl > 0) {
      if (n % 2 == 0) {
        if (pl <= n / 2) {
          cout << pl << ' ' << n << ' ' << pl + 1 << ' ' << n << '\n';
          continue;
        }
        cout << 1 << ' ' << pl - 1 << ' ' << 1 << ' ' << pl << '\n';
      } else {
        if (pl <= n / 2) {
          cout << pl << ' ' << n << ' ' << pl + 1 << ' ' << '\n';
          continue;
        }
        cout << 1 << ' ' << pl - 1 << ' ' << 1 << ' ' << pl << '\n';
      }
    } else {
      cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
      continue;
    }
  }
  return 0;
}
