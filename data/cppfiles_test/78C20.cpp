#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    long long ans = 0;
    cin >> l >> r;
    long long b = r / 2 + 1;
    if (b >= l) {
      cout << r % b << endl;
    } else {
      cout << r % l << endl;
    }
  }
  return 0;
}
