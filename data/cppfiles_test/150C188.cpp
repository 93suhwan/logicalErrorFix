#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 1e9;
    for (long long cnt1 = 0; cnt1 <= 1; cnt1++)
      for (long long cnt2 = 0; cnt2 <= 2; cnt2++) {
        long long mx_cnt3 = 0;
        for (int i = 0; i < n; i++) {
          long long mn_cnt3 = 1e9 + 1;
          for (long long used1 = 0; used1 <= cnt1; used1++)
            for (long long used2 = 0; used2 <= cnt2; used2++) {
              if (a[i] < used1 + used2 * 2 ||
                  (a[i] - used1 - used2 * 2) % 3 != 0)
                continue;
              mn_cnt3 = (a[i] - used1 - used2 * 2) / 3;
            }
          mx_cnt3 = max(mx_cnt3, mn_cnt3);
        }
        ans = min(ans, cnt1 + cnt2 + mx_cnt3);
      }
    cout << ans << "\n";
  }
}
