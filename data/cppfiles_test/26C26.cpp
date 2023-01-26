#include <bits/stdc++.h>
using namespace std;
const long long mxsz = 1e2 + 7;
const long long mxnm = 1e3 + 7;
const long long inf = 1e9 + 1e2;
const long long mod = 1e9 + 7;
const long double pi = (long double)3.14159265358;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long mn = inf;
    for (long long mask = 0; mask < (1 << 10); mask++) {
      bool ok = 1;
      for (long long i = 0; i < 10; i++) {
        if ((1 << i) & mask) {
          if (s[i] == '0') {
            ok = 0;
            break;
          }
        } else {
          if (s[i] == '1') {
            ok = 0;
            break;
          }
        }
      }
      if (!ok) continue;
      long long f = 0, k = 0, ans = 10;
      for (long long i = 0; i < 10; i++) {
        if (i % 2 == 0) {
          if ((1 << i) & mask) f++;
        } else {
          if ((1 << i) & mask) k++;
        }
        if (f - k > (10 - i) / 2) {
          ans = i + 1;
          break;
        }
        if (k - f > (9 - i) / 2) {
          ans = i + 1;
          break;
        }
      }
      mn = min(ans, mn);
    }
    cout << mn << '\n';
  }
}
