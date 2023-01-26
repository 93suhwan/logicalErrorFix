#include <bits/stdc++.h>
using namespace std;
const int M = 998244353, _G = 3, N = 1 << 20;
inline int qpow(int x, int y = M - 2) {
  int res = 1;
  for (; y; x = (long long)x * x % M, y >>= 1)
    if (y & 1) res = (long long)res * x % M;
  return res;
}
int rt[N], mg[N], fac[N], Lim;
void Pinit(int x) {
  for (Lim = 1; Lim <= x; Lim <<= 1)
    ;
  int w = qpow(_G, (M - 1) / Lim);
  mg[0] = 1;
  for (int i = (1); i <= (Lim - 1); ++i) mg[i] = (long long)mg[i - 1] * w % M;
  for (int i = 1; i < Lim; i <<= 1) {
    int sG = qpow(_G, M - 1 - (M - 1) / (i << 1));
    rt[i] = 1;
    for (int j = (i + 1); j <= (i * 2 - 1); ++j)
      rt[j] = (long long)rt[j - 1] * sG % M;
  }
}
int rev[N], a[N];
void dft(int n) {
  for (int i = (0); i <= (n - 1); ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
  for (int i = (0); i <= (n - 1); ++i)
    if (i < rev[i]) a[i] ^= a[rev[i]] ^= a[i] ^= a[rev[i]];
  for (int i = 2; i <= n; i <<= 1)
    for (int j = 0, l = (i >> 1); j < n; j += i)
      for (int k = 0, *w = rt + l; k < l; k++, w++) {
        int pa = a[j + k], pb = (long long)a[j + k + l] * *w % M;
        a[j + k] = (pa + pb >= M ? pa + pb - M : pa + pb),
              a[j + k + l] = (pa < pb ? pa - pb + M : pa - pb);
      }
  for (int i = 0, iv = qpow(n); i < n; i++) a[i] = (long long)a[i] * iv % M;
}
int n, deg[N], cnt[N], ns, x, y, all;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n, fac[0] = deg[1] = 1;
  for (int i = (1); i <= (n); ++i) fac[i] = (long long)fac[i - 1] * i % M;
  for (int i = (1); i <= (n - 1); ++i) cin >> x >> y, deg[x] += 1, deg[y] += 1;
  for (int i = (1); i <= (n); ++i)
    if (deg[i] > 1) cnt[deg[i] - 1] += 1, all += 1;
  Pinit(all);
  for (int i = (0); i <= (Lim - 1); ++i) a[i] = 1;
  for (int i = (1); i <= (n); ++i)
    if (cnt[i])
      for (int j = 0, *w = mg; j < Lim; j++, w++)
        a[j] = (long long)a[j] * qpow(*w + i, cnt[i]) % M;
  dft(Lim);
  for (int i = (0); i <= (all); ++i)
    (ns +=
     (long long)fac[n - i] * a[all - i] % M * ((i & 1) ? M - 1 : 1) % M) %= M;
  cout << ns << '\n';
  return 0;
}
