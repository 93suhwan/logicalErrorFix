#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 60);
const long long mod = 1000000007;
const long long N = 2e5 + 10;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << endl;
    } else if (l + 1 == r) {
      cout << 1 << endl;
    } else if (r % 2 == 0 && (r / 2) >= l) {
      cout << (r / 2) - 1 << endl;
    } else if ((r / 2) >= l) {
      cout << (r / 2) << endl;
    } else {
      cout << r - l << endl;
    }
  }
}
