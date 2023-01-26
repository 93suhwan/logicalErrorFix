#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      cout << x + y << '\n';
      continue;
    }
    int ans = y - y % x;
    ans = ans + (y - ans) / 2;
    cout << ans << '\n';
  }
  exit(0);
}
