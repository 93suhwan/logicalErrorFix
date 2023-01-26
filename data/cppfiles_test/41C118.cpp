#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e5 + 80;
const long long mod = 998244353;
const long long base = 1e18;
long long f[3][3][maxn];
long long get(long long ch, long long du, long long l, long long r) {
  return f[ch][du][r] - f[ch][du][l - 1];
}
long long sl[4];
long long p[4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  for (int t = 1; t <= n; t++) {
    long long h = s[t] - 'a';
    for (int i = 0; i <= 2; i++) {
      for (int du = 0; du <= 2; du++) {
        f[i][du][t] = f[i][du][t - 1];
      }
    }
    f[h][t % 3][t]++;
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    long long ans = base;
    for (int d = 0; d <= 2; d++) {
      for (int d1 = 0; d1 <= 2; d1++) {
        if (d1 == d) continue;
        long long d2 = 3 - d1 - d;
        p[d] = 0;
        p[d1] = 1;
        p[d2] = 2;
        sl[0] = (r - l + 1) / 3;
        sl[1] = sl[0];
        sl[2] = sl[0];
        if ((r - l + 1) % 3 == 1) {
          sl[0]++;
        } else if ((r - l + 1) % 3 == 2) {
          sl[0]++;
          sl[1]++;
        }
        long long res = 0;
        for (int t = 0; t <= 2; t++) {
          res += (sl[t] - get(p[t], t, l, r));
        }
        ans = min(ans, res);
      }
    }
    cout << ans << "\n";
  }
}
