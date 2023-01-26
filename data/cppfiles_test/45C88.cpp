#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    for (auto &x : v) cin >> x;
    bool flag = false;
    for (long long int i = 1; i < n; i++) {
      if (v[i] == v[i - 1] && v[i] == 0) flag = true;
    }
    if (flag) {
      cout << "-1\n";
      continue;
    }
    long long int ans = 1;
    if (v[0] == 1) ans++;
    for (long long int i = 1; i < n; i++) {
      if (v[i] == v[i - 1] && v[i] == 1) {
        ans += 5;
        continue;
      }
      if (v[i] == 1) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
