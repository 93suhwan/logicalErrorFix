#include <bits/stdc++.h>
using namespace std;
int a[1050];
signed main() {
  ios::sync_with_stdio(false);
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n & 1) n--;
  for (int i = 1; i <= n; i += 2) {
    ans += min(a[i], a[i + 1]);
    int cnt1 = a[i], cnt2 = a[i + 1];
    cnt1 -= min(a[i], a[i + 1]);
    cnt2 -= min(a[i], a[i + 1]);
    if (cnt2 > cnt1) continue;
    for (int j = i + 2; j <= n; j += 2) {
      cnt1 += a[j];
      cnt2 += a[j + 1];
      cnt1 -= min(a[j], a[j + 1]);
      cnt2 -= min(a[j], a[j + 1]);
      ans++;
      ans += min(cnt1, cnt2);
      if (cnt2 > cnt1) break;
      cnt1 -= cnt2, cnt2 = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
