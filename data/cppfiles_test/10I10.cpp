#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000006;
long long modpow(long long x, long long p, long long mod) {
  if (p == 0) return 1;
  if (p % 2 == 1) return x * modpow(x, p - 1, mod) % mod;
  long long r = modpow(x, p / 2, mod);
  return r * r % mod;
}
int main() {
  int n, m, k, r, c;
  scanf("%d %d %d %d %d", &n, &m, &k, &r, &c);
  int ax, ay, bx, by;
  scanf("%d %d %d %d", &ax, &ay, &bx, &by);
  long long total = 1LL * n * m % MOD;
  long long cnt_union = 2LL * r * c % MOD;
  int cx_1 = max(ax, bx);
  int cx_2 = min(ax + r - 1, bx + r - 1);
  int cy_1 = max(ay, by);
  int cy_2 = min(ay + c - 1, by + c - 1);
  if (cx_1 <= cx_2 && cy_1 <= cy_2) {
    long long cnt_intersection = 1LL * (cx_2 - cx_1) * (cy_2 - cy_1) % MOD;
    cnt_union = (cnt_union - cnt_intersection + MOD) % MOD;
  }
  total = (total - cnt_union + MOD) % MOD;
  int dx = bx - ax, dy = by - ay;
  long long lx = max(ax, ax + dx);
  long long rx = min(ax + r - 1, ax + r - 1 + dx);
  long long ly = max(ay, ay + dy);
  long long ry = min(ay + c - 1, ay + c - 1 + dy);
  long long add = 1LL * r * c % MOD;
  if (lx <= rx && ly <= ry) {
    long long z = (rx - lx) * (ry - ly) % MOD;
    add = (add - z + MOD) % MOD;
  }
  total = (total + add) % MOD;
  printf("%lld\n", modpow(k, total, MOD + 1));
  return 0;
}
