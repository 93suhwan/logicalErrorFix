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
    if (((r + 1) / 2) >= l) {
      cout << ((r + 1) / 2) - 1 << endl;
    } else {
      cout << r - l << endl;
    }
  }
}
