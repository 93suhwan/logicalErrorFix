#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  long long N = 200000;
  vector<vector<long long>> pref(31, vector<long long>(N + 1, 0));
  for (long long i = 1; i <= N; i++) {
    for (long long j = 0; j < 31; j++) {
      pref[j][i] += pref[j][i - 1];
      if (i & (1 << j)) pref[j][i]++;
    }
  }
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    for (long long i = 0; i < 31; i++) {
      ans = max(ans, pref[i][r] - pref[i][l - 1]);
    }
    cout << (r - l + 1 - ans) << "\n";
  }
  return 0;
}
