#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int k;
    cin >> k;
    int x, sum = 0;
    for (int i = 1;; i++) {
      sum = i * i;
      if (sum >= k) {
        x = i;
        break;
      }
    }
    int corner = sum - (x - 1);
    if (k == corner) {
      cout << x << ' ' << x << "\n";
      ;
    } else if (k > corner) {
      cout << x << ' ' << abs(sum - k) + 1 << "\n";
      ;
    } else {
      cout << abs(corner - k) << ' ' << x << "\n";
      ;
    }
  }
  return 0;
}
