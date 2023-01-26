#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, M = 998244353, OO = 0x3f3f3f3f, HS = 31, HS2 = 47,
                M2 = 1e9 + 9;
const double PI = acos(-1);
long long tc, x, y;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  tc = 1;
  cin >> tc;
  while (tc--) {
    cin >> x >> y;
    long long ans = 0;
    if (x > y)
      ans = (y * x) + y;
    else if (y % x == 0)
      ans = y;
    else {
      long long md = y % x;
      md /= 2;
      ans = y - md;
    }
    cout << ans << "\n";
  }
  return 0;
}
