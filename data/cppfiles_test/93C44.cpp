#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, i, j, a, b, cnt, ans;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    ans = a;
    a -= 1;
    if (a % 4 == 1)
      a = 1;
    else if (a % 4 == 2)
      a = 4 * (a / 4) + 3;
    else if (a % 4 == 3)
      a = 0;
    if (a == b)
      cout << ans << "\n";
    else if ((a ^ b) != ans)
      cout << ans + 1 << "\n";
    else
      cout << ans + 2 << "\n";
  }
  return 0;
}
