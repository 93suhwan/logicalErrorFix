#include <bits/stdc++.h>
using namespace std;
int ai[200010], bi[200010];
int ans1[200010], ans2[200010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long long s = 0;
    long long L = 0;
    long long R = 0;
    for (int i = 1; i <= n; i++) {
      cin >> ai[i] >> bi[i];
      s += ai[i] - bi[i] + m;
      L += max(m - bi[i], 0);
      R += min(ai[i], m);
    }
    if (s <= 2 * L) {
      cout << 2 * L - s << endl;
      for (int i = 1; i <= n; i++) {
        cout << max(m - bi[i], 0) << " " << min(bi[i], m) << endl;
      }
    } else if (s >= 2 * R) {
      cout << s - 2 * R << endl;
      for (int i = 1; i <= n; i++) {
        cout << min(ai[i], m) << " " << max(m - ai[i], 0) << endl;
      }
    } else {
      if (s % 2 == 0)
        cout << 0 << endl;
      else
        cout << 1 << endl;
      for (int i = 1; i <= n; i++) {
        ans1[i] = max(m - bi[i], 0);
        ans2[i] = min(bi[i], m);
      }
      long long oi = s / 2 - L;
      for (int i = 1; i <= n; i++) {
        if (oi >= min(ai[i], m) - max(m - bi[i], 0)) {
          oi -= min(ai[i], m) - max(m - bi[i], 0);
          ans1[i] = ai[i], ans2[i] = m - ai[i];
        } else {
          ans1[i] = ans1[i] + oi;
          ans2[i] = m - ans1[i];
          oi = 0;
        }
        if (oi == 0) break;
      }
      for (int i = 1; i <= n; i++) {
        cout << ans1[i] << " " << ans2[i] << endl;
      }
    }
  }
  return 0;
}
