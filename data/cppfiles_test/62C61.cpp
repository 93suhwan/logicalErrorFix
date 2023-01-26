#include <bits/stdc++.h>
using namespace std;
long long t = 1, n, m, k, q, l, r, ans, a[1009][1009], dy[1009][1009],
          xy[1009][1009], zt[1009][1009], b, c, u, v, x, y, z, mod = 1e9 + 7;
string s;
struct st {
  long long x, y;
};
bool cmp(const st &a, const st &b) { return a.x < b.x; }
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long qp(long long x, long long y) {
  long long a = 1, b = x;
  while (y) {
    if (y & 1) a = a * b % mod;
    b = b * b % mod, y >>= 1;
  }
  return a;
}
void add(long long x, long long y, bool opt) {
  if (opt) {
    bool wtf = 0;
    long long nx = x, ny = y, posx = -1, posy = -1, asd = 1;
    while (1) {
      if (!wtf)
        nx += 1;
      else
        ny += 1;
      if (nx > n || ny > m) break;
      if (!zt[nx][ny]) {
        if (!wtf)
          posx = nx - 1, posy = ny;
        else
          posx = nx, posy = ny - 1;
        break;
      }
      asd += 1, wtf ^= 1;
    }
    wtf = 1;
    long long nx2 = x, ny2 = y, posx2 = -1, posy2 = -1, asd2 = 1;
    while (1) {
      if (!wtf)
        nx2 -= 1;
      else
        ny2 -= 1;
      if (nx2 < 1 || ny2 < 1) break;
      if (!zt[nx2][ny2]) {
        if (!wtf)
          posx2 = nx2 + 1, posy2 = ny2;
        else
          posx2 = nx2, posy2 = ny2 + 1;
        break;
      }
      asd2 += 1, wtf ^= 1;
    }
    ans += asd * asd2;
    wtf = 1;
    nx = x, ny = y, posx = -1, posy = -1, asd = 1;
    while (1) {
      if (!wtf)
        nx += 1;
      else
        ny += 1;
      if (nx > n || ny > m) break;
      if (!zt[nx][ny]) {
        if (!wtf)
          posx = nx - 1, posy = ny;
        else
          posx = nx, posy = ny - 1;
        break;
      }
      asd += 1, wtf ^= 1;
    }
    wtf = 0;
    nx2 = x, ny2 = y, posx2 = -1, posy2 = -1, asd2 = 1;
    while (1) {
      if (!wtf)
        nx2 -= 1;
      else
        ny2 -= 1;
      if (nx2 < 1 || ny2 < 1) break;
      if (!zt[nx2][ny2]) {
        if (!wtf)
          posx2 = nx2 + 1, posy2 = ny2;
        else
          posx2 = nx2, posy2 = ny2 + 1;
        break;
      }
      asd2 += 1, wtf ^= 1;
    }
    ans += asd * asd2, ans -= 1;
  } else {
    bool wtf = 0;
    long long nx = x, ny = y, posx = -1, posy = -1, asd = 1;
    while (1) {
      if (!wtf)
        nx += 1;
      else
        ny += 1;
      if (nx > n || ny > m) break;
      if (!zt[nx][ny]) {
        if (!wtf)
          posx = nx - 1, posy = ny;
        else
          posx = nx, posy = ny - 1;
        break;
      }
      asd += 1, wtf ^= 1;
    }
    wtf = 1;
    long long nx2 = x, ny2 = y, posx2 = -1, posy2 = -1, asd2 = 1;
    while (1) {
      if (!wtf)
        nx2 -= 1;
      else
        ny2 -= 1;
      if (nx2 < 1 || ny2 < 1) break;
      if (!zt[nx2][ny2]) {
        if (!wtf)
          posx2 = nx2 + 1, posy2 = ny2;
        else
          posx2 = nx2, posy2 = ny2 + 1;
        break;
      }
      asd2 += 1, wtf ^= 1;
    }
    ans -= asd * asd2;
    wtf = 1;
    nx = x, ny = y, posx = -1, posy = -1, asd = 1;
    while (1) {
      if (!wtf)
        nx += 1;
      else
        ny += 1;
      if (nx > n || ny > m) break;
      if (!zt[nx][ny]) {
        if (!wtf)
          posx = nx - 1, posy = ny;
        else
          posx = nx, posy = ny - 1;
        break;
      }
      asd += 1, wtf ^= 1;
    }
    wtf = 0;
    nx2 = x, ny2 = y, posx2 = -1, posy2 = -1, asd2 = 1;
    while (1) {
      if (!wtf)
        nx2 -= 1;
      else
        ny2 -= 1;
      if (nx2 < 1 || ny2 < 1) break;
      if (!zt[nx2][ny2]) {
        if (!wtf)
          posx2 = nx2 + 1, posy2 = ny2;
        else
          posx2 = nx2, posy2 = ny2 + 1;
        break;
      }
      asd2 += 1, wtf ^= 1;
    }
    ans -= asd * asd2, ans += 1;
  }
}
int main() {
  while (t--) {
    n = read(), m = read(), q = read();
    for (long long i = 1; i <= n; i += 1)
      for (long long j = 1; j <= m; j += 1) {
        zt[i][j] = 1;
        if (i == j)
          ans += 2 * (2 * i - 1) - 1;
        else if (i > j)
          ans += 2 * (2 * j - 1);
        else
          ans += 2 * (2 * i - 1);
      }
    while (q--) {
      x = read(), y = read();
      zt[x][y] ^= 1, add(x, y, zt[x][y]);
      printf("%lld\n", ans);
    }
  }
  return 0;
}
