#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long mx = 1;
    long long mn = 1000000000;
    long long second = 0;
    vector<long long> freq(3, 0);
    for (long long& ai : a) {
      cin >> ai;
      if (ai > mx) {
        second = mx;
        mx = ai;
      }
      if (ai != mx) {
        second = max(second, ai);
      }
      mn = min(mn, ai);
      freq[ai % 3]++;
    }
    long long ans;
    if (mx % 3 == 0) {
      if (freq[1] == 0 && freq[2] == 0) {
        ans = mx / 3;
      } else {
        ans = mx / 3 + 1;
      }
    } else if (mx % 3 == 2) {
      if (freq[1] == 0) {
        ans = mx / 3 + 1;
      } else {
        ans = mx / 3 + 2;
      }
    } else {
      if (freq[2] == 0 || (mn != 1 && second != mx - 1)) {
        ans = mx / 3 + 1;
      } else {
        ans = mx / 3 + 2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
