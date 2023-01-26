#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 5;
const long long oo = 1e18 + 7, mod = 1e9 + 7;
long long n, a[N], pref[N], mn[N][N];
void process() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    if (i & 1)
      pref[i] = (pref[i - 1] + a[i]);
    else
      pref[i] = (pref[i - 1] - a[i]);
  }
  for (long long i = 1; i <= n; i++) {
    mn[i][i - 1] = oo;
    mn[i][i] = pref[i] - pref[i - 1];
    for (long long j = i + 1; j <= n; j++) {
      mn[i][j] = min(mn[i][j - 1], pref[j] - pref[i - 1]);
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      long long temp = 0;
      if (j > (i + 1)) temp = pref[j - 1] - pref[i];
      if (!(i & 1) || j & 1) continue;
      long long diff = -temp, mn_odd = max(0LL, -mn[i + 1][j - 1]),
                mx_odd = min(a[i], a[j] + diff);
      mn_odd = max(mn_odd, diff + 1);
      mn_odd = max(mn_odd, 1LL);
      ans += max(0LL, (mx_odd - mn_odd + 1));
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  process();
}
