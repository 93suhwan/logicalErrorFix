#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  for (long long tc = 1; tc <= T; ++tc) {
    long long n;
    cin >> n;
    vector<long long> need(n + 1, true), spare;
    for (long long i = 0; i < n; ++i) {
      long long a;
      cin >> a;
      if (a <= n && need[a])
        need[a] = false;
      else
        spare.push_back((a + 2 - 1) / 2 - 1);
    }
    sort(spare.begin(), spare.end());
    long long ans = (long long)spare.size();
    for (long long i = n; i >= 1; --i) {
      if (need[i]) {
        if (spare.back() >= i)
          spare.pop_back();
        else
          ans = -1;
      }
    }
    cout << ans << "\n";
  }
}
