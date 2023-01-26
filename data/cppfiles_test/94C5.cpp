#include <bits/stdc++.h>
using namespace std;
const long long N = 20;
long long cnt[N];
void work(long long u, long long& idx) {
  while (u) {
    cnt[++idx] = u % 10;
    u /= 10;
  }
  reverse(cnt + 1, cnt + 1 + idx);
  return;
}
long long f[20][2][2];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    memset(f, 0, sizeof f);
    long long a;
    cin >> a;
    long long idx = 0;
    work(a, idx);
    for (long long i = idx; i >= 1; i--) {
      if ((idx - i + 1) <= 2) {
        f[i][0][0] = cnt[i] + 1;
        if (cnt[i] == 9) continue;
        if (cnt[i] != 9) f[i][1][0] = (10 - cnt[i] - 1);
      } else {
        f[i][0][0] = cnt[i] + 1;
        f[i][0][1] = cnt[i];
        if (cnt[i] != 9) f[i][1][0] = (10 - cnt[i] - 1);
        if (cnt[i] != 0)
          f[i][1][1] = (10 - (cnt[i] - 1) - 1);
        else
          f[i][1][1] = 10;
      }
      if (i != idx && i != (idx - 1)) {
        long long kk = f[i + 2][1][0] + f[i + 2][1][1];
        f[i][0][1] *= kk, f[i][1][1] *= kk;
        kk = f[i + 2][0][0] + f[i + 2][0][1];
        f[i][0][0] *= kk, f[i][1][0] *= kk;
      }
    }
    long long ans = 0;
    if (idx == 1)
      ans += f[1][0][0] + f[1][0][1];
    else
      ans = f[1][0][0] * f[2][0][0] + f[1][0][0] * f[2][0][1] +
            f[1][0][1] * f[2][0][0] + f[1][0][1] * f[2][0][1];
    cout << ans - 2 << endl;
  }
  return 0;
}
