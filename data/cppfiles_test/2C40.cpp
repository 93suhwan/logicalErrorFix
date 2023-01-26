#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void qr(T &x) {
  x = 0;
  int f = 0;
  char s = getchar();
  while (s < '0' || '9' < s) f |= s == '-', s = getchar();
  while ('0' <= s && s <= '9') x = x * 10 + s - 48, s = getchar();
  x = f ? -x : x;
}
int cc = 0, buf[31];
template <typename T>
inline void qw(T x) {
  if (x < 0) putchar('-'), x = -x;
  do {
    buf[++cc] = int(x % 10);
    x /= 10;
  } while (x);
  while (cc) putchar(buf[cc--] + '0');
  puts("");
}
int ad(int x, int y) {
  return (x + y) >= 1000000007 ? x + y - 1000000007 : x + y;
}
int mu(int x, int y) { return 1ll * x * y % 1000000007; }
int de(int x, int y) { return (x - y) < 0 ? x - y + 1000000007 : x - y; }
void mymin(int &x, int y) { x = x < y ? x : y; }
void mymax(int &x, int y) { x = x > y ? x : y; }
const int N = 6e3 + 10;
int n, x[N], y[N], cnt[4][4][4];
int S2(int x1, int y1, int x2, int y2, int x3, int y3) {
  int res = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
  res %= 4;
  if (res < 0) res += 4;
  return res;
}
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int main() {
  qr(n);
  for (int i = 1; i <= n; i++) qr(x[i]), qr(y[i]);
  long long eee = 0, eoo = 0;
  for (int i = 1; i <= n; i++) {
    memset(cnt, 0, sizeof(cnt));
    for (int j = 1; j <= n; j++)
      if (i != j)
        cnt[x[j] % 4][y[j] % 4][gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) % 4]++;
    for (int x1 = 0; x1 <= 3; x1++)
      for (int y1 = 0; y1 <= 3; y1++)
        for (int b1 = 0; b1 <= 3; b1++) {
          int kk = cnt[x1][y1][b1];
          cnt[x1][y1][b1]--;
          for (int x2 = x1 & 1; x2 < 4; x2 += 2)
            for (int y2 = y1 & 1; y2 < 4; y2 += 2)
              for (int b2 = b1 & 1; b2 < 4; b2 += 2) {
                int S = S2(x[i], y[i], x1, y1, x2, y2) >> 1;
                int b3 = gcd(abs(x1 - x2), abs(y1 - y2));
                int res = S - (b1 + b2 + b3) / 2 + 1;
                if (res & 1) {
                  if (b1 & 1)
                    eoo += kk * cnt[x2][y2][b2];
                  else
                    eee += kk * cnt[x2][y2][b2];
                }
              }
          cnt[x1][y1][b1]++;
        }
  }
  qw(eee / 6 + eoo / 2);
  return 0;
}
