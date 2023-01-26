#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2.5e5 + 5, P = 998244353;
int n, d[N], c[N], lim = 1, bit = -1, rev[1 << 18];
ll w[1 << 18], A[1 << 18], B[1 << 18], fac[N], ifac[N];
ll Pow(ll a, int n, ll r = 1) {
  for (; n; n >>= 1, a = a * a % P)
    if (n & 1) r = r * a % P;
  return r;
}
void NTT(ll a[], int t) {
  if (t) reverse(a + 1, a + lim);
  for (int i = (0), ie = (lim); i < ie; i++)
    if (rev[i] < i) swap(a[i], a[rev[i]]);
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = (j), ke = (j + i); k < ke; k++) {
        ll &x = a[k], y = a[k + i] * w[lim / i * (k - j)] % P;
        a[k + i] = x < y ? x - y + P : x - y;
        x += y, x >= P ? x -= P : 0;
      }
  ll inv = Pow(lim, P - 2);
  if (t)
    for (int i = (0), ie = (lim); i < ie; i++) (a[i] *= inv) %= P;
}
int main() {
  cin >> n;
  int u, v;
  for (int i = (2); i <= (n); i++)
    d[i]--, scanf("%d%d", &u, &v), d[u]++, d[v]++;
  for (int i = (1); i <= (n); i++) c[d[i]]++;
  for (int i = (0); i <= (n); i++) fac[i] = i ? fac[i - 1] * i % P : 1;
  for (int i = (n + 1); i >= (1); i--)
    ifac[i - 1] = i > n ? Pow(fac[n], P - 2) : ifac[i] * i % P;
  A[0] = 1;
  int m = 0;
  for (int i = (n); i >= (1); i--)
    if (c[i]) {
      m += c[i];
      if (lim <= m) {
        NTT(A, 1);
        while (lim <= m) lim <<= 1, bit++;
        for (int i = (1), ie = (lim); i < ie; i++)
          rev[i] = rev[i >> 1] >> 1 | (i & 1) << bit;
        ll wn = Pow(3, P / 2 / lim);
        for (int i = (0), ie = (lim); i < ie; i++)
          w[i] = i ? w[i - 1] * wn % P : 1;
        NTT(A, 0);
      }
      ll p = 1;
      for (int j = (0); j <= (c[i]); j++)
        B[j] = fac[c[i]] * ifac[j] % P * ifac[c[i] - j] % P * p % P,
        p = p * i % P;
      for (int j = (c[i] + 1), je = (lim); j < je; j++) B[j] = 0;
      NTT(B, 0);
      for (int j = (0), je = (lim); j < je; j++) (A[j] *= B[j]) %= P;
    }
  NTT(A, 1);
  ll ans = 0;
  for (int i = (0); i <= (n); i++)
    (ans += (i & 1 ? -1 : 1) * fac[n - i] * A[i]) %= P;
  cout << (ans + P) % P;
}
