#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 100, mod = 998244353;
const long long maxn = 4e5 + 100, k = 1e6;
long long u, v, n, m;
string s;
long long f[maxn], siz[maxn];
long long get(long long x) { return x == f[x] ? f[x] : f[x] = get(f[x]); }
void lian(long long x, long long y) {
  long long xx = get(x), yy = get(y);
  if (xx == yy) return;
  f[xx] = yy;
  siz[yy] += siz[xx];
}
void work() {
  cin >> n >> m;
  for (long long i = 1; i <= 2 * n; i++) siz[i] = i / (n + 1), f[i] = i;
  for (long long i = 1; i <= m; i++) {
    cin >> u >> v >> s;
    long long zhi = (s[0] == 'i' ? n : 0);
    lian(u, v + zhi);
    lian(u + n, v + n - zhi);
  }
  bool ok = false;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (get(i) == get(i + n)) {
      ok = true;
      break;
    }
    if (get(i) != i) continue;
    ans += max(siz[i], siz[i + n]);
  }
  if (ok)
    cout << "-1" << endl;
  else
    cout << ans << endl;
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long Case = 1;
  cin >> Case;
  for (long long ka = 1; ka <= Case; ka++) {
    work();
  }
  return 0;
}
