#include <bits/stdc++.h>
using namespace std;
long long a[1050];
signed main() {
  ios::sync_with_stdio(false);
  long long n, ans = 0;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  if (n & 1) n--;
  for (long long i = 1; i <= n; i += 2) {
    ans += min(a[i], a[i + 1]);
    if (a[i + 1] > a[i]) continue;
    long long cnt = a[i] - a[i + 1];
    for (long long j = i + 2; j <= n; j += 2) {
      long long tmp1 = a[j], tmp2 = a[j + 1];
      if (tmp1 <= tmp2) {
        ans++;
        tmp2 -= tmp1;
        ans += min(cnt, tmp2);
        cnt -= tmp2;
      } else {
        cnt += tmp1 - tmp2;
      }
      if (cnt < 0) break;
    }
  }
  cout << ans << endl;
  return 0;
}
