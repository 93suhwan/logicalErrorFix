#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(NULL);
  unsigned long long t;
  cin >> t;
  while (t--) {
    unsigned long long n;
    cin >> n;
    unsigned long long ans = n / 6 * 15;
    unsigned long long m = n % 6;
    if (n <= 6) {
      ans = 15;
    } else if (m != 0) {
      if (m <= 2) {
        ans -= 15;
        ans += 20;
      } else if (m <= 4) {
        ans -= 15;
        ans += 25;
      } else if (m > 4) {
        ans += 15;
      }
    }
    cout << ans << "\n";
  }
}
