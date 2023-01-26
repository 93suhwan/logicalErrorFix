#include <bits/stdc++.h>
using namespace std;
const long long P = 998244353;
long long T, n, m, fac[200005], inv[200005];
long long cnt, ans, tu[200005], tv[200005], pos[200005], val[200005];
long long tr[200005];
long long lowbit(long long x) { return x & (-x); }
void modify(long long x, long long v) {
  for (; x <= n; x += lowbit(x)) tr[x] += v;
}
long long query(long long x) {
  long long ret = 0;
  for (; x; x -= lowbit(x)) ret += tr[x];
  return ret;
}
long long pwr(long long x, long long y) {
  long long ret = 1, tmp = x;
  while (y) {
    if (y & 1) ret = (ret * tmp) % P;
    tmp = (tmp * tmp) % P;
    y >>= 1;
  }
  return ret;
}
long long comb(long long x, long long y) {
  if (x < y) return 0;
  return fac[x] * inv[y] % P * inv[x - y] % P;
}
int main() {
  ios::sync_with_stdio(false);
  fac[0] = 1;
  for (long long i = 1; i <= 200001; i++) fac[i] = (fac[i - 1] * i) % P;
  for (long long i = 0; i <= 200001; i++) inv[i] = pwr(fac[i], P - 2);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    ans = cnt = 0;
    for (long long i = 1; i <= m; i++) cin >> tv[i] >> tu[i];
    for (long long l, r, mid, i = m; i >= 1; i--) {
      l = tu[i];
      r = n;
      while (l <= r) {
        mid = (l + r) >> 1;
        if (query(mid) - query(tu[i] - 1) < mid - tu[i] + 1) {
          pos[i] = mid;
          r = mid - 1;
        } else
          l = mid + 1;
      }
      modify(pos[i], 1);
      val[pos[i]] = tv[i];
    }
    for (long long i = 1; i <= m; i++) {
      if (pos[i] != n) {
        if (!val[pos[i] + 1])
          cnt++;
        else if (val[pos[i] + 1] < val[pos[i]])
          cnt++;
      }
    }
    for (long long i = m; i >= 1; i--) {
      val[pos[i]] = 0;
      modify(pos[i], -1);
      pos[i] = 0;
    }
    m = n - 1 - cnt;
    for (long long i = 1; i <= m; i++)
      ans = (ans + comb(n + 1, i) * comb(m - 1, i - 1)) % P;
    if (m == 0) ans = 1;
    cout << ans << '\n';
  }
  return 0;
}
