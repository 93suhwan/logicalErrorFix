#include <bits/stdc++.h>
using namespace std;
long long d(pair<long long, long long> f, pair<long long, long long> s) {
  return abs(f.first - s.first) % 2 || abs(f.second - s.second) % 2;
}
long long cnt[2][2];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    x /= 2;
    y /= 2;
    cnt[x & 1][y & 1]++;
  }
  long long d1 = 0;
  long long d2 = 0;
  long long d6 = 0;
  for (long long fx = 0; fx < 2; fx++) {
    for (long long fy = 0; fy < 2; fy++) {
      if (cnt[fx][fy] == 0) continue;
      long long fml = cnt[fx][fy];
      cnt[fx][fy]--;
      for (long long sx = 0; sx < 2; sx++) {
        for (long long sy = 0; sy < 2; sy++) {
          if (cnt[sx][sy] == 0) continue;
          long long sml = fml * cnt[sx][sy];
          cnt[sx][sy]--;
          for (long long tx = 0; tx < 2; tx++) {
            for (long long ty = 0; ty < 2; ty++) {
              if (cnt[tx][ty] == 0) continue;
              long long tml = sml * cnt[tx][ty];
              pair<long long, long long> F = {fx, fy};
              pair<long long, long long> S = {sx, sy};
              pair<long long, long long> T = {tx, ty};
              if (F > S || S > T) continue;
              if ((d(F, S) + d(S, T) + d(F, T)) % 2 == 1) continue;
              if (F == S && F == T) {
                d6 += tml;
              } else if (F == S || S == T) {
                d2 += tml;
              } else {
                d1 += tml;
              }
            }
          }
          cnt[sx][sy]++;
        }
      }
      cnt[fx][fy]++;
    }
  }
  cerr << d1 << ' ' << d2 << ' ' << d6 << endl;
  long long ans = d1 + d2 / 2 + d6 / 6;
  cout << ans << '\n';
}
