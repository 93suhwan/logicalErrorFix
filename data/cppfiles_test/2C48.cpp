#include <bits/stdc++.h>
using namespace std;
const long long N = 105000;
long long n, ans1, ans2;
long long px[N], py[N];
long long cnt[4][4][4];
inline long long read() {
  long long re = 0, k = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') k = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    re = re * 10 + ch - '0';
    ch = getchar();
  }
  return re * k;
}
inline long long gcd(long long x, long long y) {
  if (x < 0) x = -x;
  if (y < 0) y = -y;
  if (!y) return x;
  return gcd(y, x % y);
}
inline long long calc_s(long long a, long long b, long long c, long long d,
                        long long e, long long f) {
  return (((a * (d - f) + c * (f - b) + e * (b - d)) % 4 + 4) % 4);
}
signed main() {
  n = read();
  for (register long long i = 1; i <= n; i++) {
    px[i] = read(), py[i] = read();
  }
  for (register long long i = 1; i <= n; i++) {
    memset(cnt, 0, sizeof(cnt));
    for (register long long j = 1; j <= n; j++) {
      if (i == j) continue;
      cnt[px[j] % 4][py[j] % 4][gcd(px[i] - px[j], py[i] - py[j]) % 4]++;
    }
    for (register long long a = 0; a < 4; a++) {
      for (register long long b = 0; b < 4; b++) {
        for (register long long k1 = 0; k1 < 4; k1++) {
          long long now = cnt[a][b][k1];
          cnt[a][b][k1]--;
          for (register long long c = a & 1; c < 4; c += 2) {
            for (register long long d = b & 1; d < 4; d += 2) {
              for (register long long k2 = k1 & 1; k2 < 4; k2 += 2) {
                if (!cnt[c][d][k2]) continue;
                long long s = calc_s(px[i], py[i], a, b, c, d) / 2;
                long long point = s + 1 - (k1 + k2 + gcd(a - c, b - d)) / 2;
                if (point & 1) {
                  if (k1 & 1)
                    ans1 += now * cnt[c][d][k2];
                  else
                    ans2 += now * cnt[c][d][k2];
                }
              }
            }
          }
          cnt[a][b][k1]++;
        }
      }
    }
  }
  printf("%lld", ans1 / 2 + ans2 / 6);
  return 0;
}
