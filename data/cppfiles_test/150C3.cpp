#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int t, n;
int a[N];
int now[20];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 1e9;
    for (int cnt1 = 0; cnt1 <= 6; ++cnt1)
      for (int cnt2 = 0; cnt2 <= 3; ++cnt2) {
        for (int i = 0; i <= 12; ++i) now[i] = 0;
        now[0] = 1;
        for (int i = 1; i <= cnt1; ++i)
          for (int j = 12; j >= 1; --j) now[j] |= now[j - 1];
        for (int i = 1; i <= cnt2; ++i)
          for (int j = 12; j >= 2; --j) now[j] |= now[j - 2];
        int maxs = 0;
        for (int i = 1; i <= n; ++i) {
          int flag = 0;
          for (int j = 12; j >= 0; --j)
            if (now[j])
              if (j <= a[i] && (a[i] - j) % 3 == 0) {
                flag = 1;
                maxs = max(maxs, (a[i] - j) / 3);
                break;
              }
          if (flag == 0) maxs = 1e9;
        }
        ans = min(ans, maxs + cnt1 + cnt2);
      }
    cout << ans << "\n";
  }
}
