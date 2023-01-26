#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 10, maxm = 2 * (1000 + 365 * 1000 + 10),
          mod = 1e9 + 7, inf = 0x3f3f3f3f;
const double pi = acos(-1), eps = 1e-8;
int T, l, r;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> l >> r;
    int t = r / 2 + 1;
    if (t >= l) {
      cout << r - t << "\n";
    } else {
      cout << r - l << "\n";
    }
  }
  return 0;
}
