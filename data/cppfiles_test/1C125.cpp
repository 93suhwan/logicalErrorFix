#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mo = 1e9 + 7;
const int maxn = 2e5 + 5;
namespace MF {
LL qpow(LL a, LL b) {
  LL ans = 1;
  a %= mo;
  while (b) {
    if (b & 1) {
      ans = ans * a % mo;
    }
    b >>= 1;
    a = a * a % mo;
  }
  return ans;
}
LL fac[maxn];
LL inv[maxn];
void init() {
  fac[0] = fac[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    fac[i] = fac[i - 1] * i % mo;
  }
  for (int i = 2; i < maxn; i++) {
    inv[i] = (mo - mo / i) * inv[mo % i] % mo;
  }
  for (int i = 2; i < maxn; i++) {
    inv[i] = inv[i - 1] * inv[i] % mo;
  }
}
LL C(int n, int m) {
  if (n < m) {
    return 0;
  }
  return fac[n] * inv[m] % mo * inv[n - m] % mo;
}
};  // namespace MF
int f(int x, int y) {
  if (x == 0 && y == 0) {
    return 0;
  }
  return 1;
}
LL C(int n, int m) {
  if (n < m) {
    return 0;
  }
  if (m == 0) {
    return 1;
  } else if (m == 1) {
    return n;
  } else if (m == 2) {
    return (LL)n * (n - 1) / 2;
  }
  return (LL)n * (n - 1) * (n - 2) / 6;
}
int main() {
  int n;
  scanf("%d", &n);
  int num[4] = {0};
  int x, y;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    x >>= 1;
    y >>= 1;
    int now = (x % 2) * 2 + (y % 2);
    num[now]++;
  }
  LL ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 4; j++) {
      for (int k = j; k < 4; k++) {
        int x1 = i / 2, y1 = i % 2;
        int x2 = j / 2, y2 = j % 2;
        int x3 = k / 2, y3 = k % 2;
        if (f(abs(x2 - x1), abs(y2 - y1)) + f(abs(x3 - x1), abs(y3 - y1)) +
                f(abs(x3 - x2), abs(y3 - y2)) &
            1) {
          continue;
        }
        int now[4] = {0};
        now[i]++;
        now[j]++;
        now[k]++;
        LL tmp = 1;
        for (int u = 0; u < 4; u++) {
          tmp *= C(num[u], now[u]);
        }
        ans += tmp;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
