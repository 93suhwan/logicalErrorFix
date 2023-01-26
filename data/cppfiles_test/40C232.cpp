#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    vector<long long> pref1(m), pref2(m);
    long long sum_a = 0;
    for (int i = 0; i < m; i++) {
      long long q;
      cin >> q;
      sum_a += q;
      if (i == 0)
        pref1[i] = q;
      else
        pref1[i] = pref1[i - 1] + q;
    }
    for (int i = 0; i < m; i++) {
      long long q;
      cin >> q;
      sum_a += q;
      if (i == 0)
        pref2[i] = q;
      else
        pref2[i] = pref2[i - 1] + q;
    }
    long long ans = pref1[m - 1] - pref1[0];
    if (m >= 2) ans = min(ans, pref2[m - 2]);
    for (int i = 1; i < m - 1; i++) {
      ans = min(ans, max(pref2[i - 1], pref1[m - 1] - pref1[i]));
    }
    cout << ans << "\n";
  }
  return 0;
}
