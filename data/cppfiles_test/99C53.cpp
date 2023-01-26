#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    long long d;
    cin >> d;
    vector<long long> f;
    long long cur = x;
    for (long long i = 0; i < 4; i++) {
      long long min = i + 1;
      if (cur & 1) {
        cur += min;
      } else {
        cur -= min;
      }
      f.push_back(cur);
    }
    long long te = d % 4;
    if (te == 2 || te == 0) {
      if (te == 0) te += 4;
      cout << f[te - 1] << '\n';
    } else {
      if (te == 1) {
        d--;
        long long dem = d / 4.0;
        if (x & 1) {
          cout << f[te - 1] + dem * 4 << '\n';
        } else {
          cout << f[te - 1] - dem * 4 << '\n';
        }
      } else {
        d--;
        long long dem = d / 4.0;
        if (x & 1) {
          cout << f[te - 1] - dem * 4 << '\n';
        } else {
          cout << f[te - 1] + dem * 4 << '\n';
        }
      }
    }
  }
  return 0;
}
