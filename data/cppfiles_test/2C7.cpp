#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 77309411329ll;
const ll modinv2 = (mod + 1) / 2;
const ll G = 7;
const int maxn = (1 << 19) + 5;
inline ll add(ll a, ll b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(ll& a, ll b) {
  if ((a += b) >= mod) a -= mod;
}
inline ll sub(ll a, ll b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(ll& a, ll b) {
  if ((a -= b) < 0) a += mod;
}
inline ll mul(ll a, ll b) {
  return (a * b - (ll)((long double)a / mod * b) * mod + mod) % mod;
}
inline ll qpow(ll x, ll n) {
  ll ans = 1;
  for (; n; n >>= 1, x = mul(x, x))
    if (n & 1) ans = mul(ans, x);
  return ans;
}
ll wn[30], iwn[30];
inline void init() {
  wn[21] = qpow(G, (mod - 1) / (1 << 21));
  for (int i = 20; i >= 0; i--) wn[i] = mul(wn[i + 1], wn[i + 1]);
  iwn[21] = qpow(wn[21], (1 << 21) - 1);
  for (int i = 20; i >= 0; i--) iwn[i] = mul(iwn[i + 1], iwn[i + 1]);
}
inline void revbin_permute(ll a[], int n) {
  int i = 1, j = n >> 1, k;
  for (; i < n - 1; i++) {
    if (i < j) swap(a[i], a[j]);
    for (k = n >> 1; j >= k;) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}
void NTT(ll f[], int ldn, int is) {
  int n = (1 << ldn);
  revbin_permute(f, n);
  for (int i = 0; i < n; i += 2) {
    ll tmp1 = f[i], tmp2 = f[i + 1];
    f[i] = add(tmp1, tmp2), f[i + 1] = sub(tmp1, tmp2);
  }
  for (int ldm = 2; ldm <= ldn; ldm++) {
    int m = (1 << ldm), mh = (m >> 1);
    ll dw = is > 0 ? wn[ldm] : iwn[ldm], w = 1;
    for (int j = 0; j < mh; j++) {
      for (int r = 0; r < n; r += m) {
        ll u = f[r + j], v = mul(f[r + j + mh], w);
        f[r + j] = add(u, v);
        f[r + j + mh] = sub(u, v);
      }
      w = mul(w, dw);
    }
  }
}
void convolution(ll f[], ll g[], int n) {
  int ldn;
  for (int i = 20; i >= 0; i--)
    if (n & (1 << i)) {
      ldn = i;
      break;
    }
  NTT(f, ldn, 1);
  NTT(g, ldn, 1);
  for (int i = 0; i < n; i++) f[i] = mul(f[i], g[i]);
  NTT(f, ldn, -1);
  ll iv = qpow(n, mod - 2);
  for (int i = 0; i < n; i++) f[i] = mul(f[i], iv);
}
const int M = 1000000007;
int a[maxn];
ll f[maxn], g[maxn];
int main(void) {
  init();
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) a[i] = (a[i] + a[i - 1]) % k;
  ll ans = 0;
  map<int, int> cnt;
  ++cnt[a[0]];
  for (int i = 1; i <= n; i++) {
    ans = (ans + cnt[a[i]]) % M;
    if (i < n) {
      ans = (ans + cnt[(a[i] - m * (ll)a[n] % k + k) % k]) % M;
      if ((a[i] - m * (ll)a[n] % k + k) % k == a[0]) ans--;
    }
    ++cnt[a[i]];
  }
  for (int i = 0; i < n; i++) f[a[i]]++;
  for (int i = 1; i <= n; i++) g[(k - a[i]) % k]++;
  int len = 2;
  while (len < 2 * k) len *= 2;
  convolution(f, g, len);
  for (int i = k; i < len; i++) f[i % k] += f[i];
  for (int i = 1; i <= m - 1; i++) ans = (ans + f[i * (ll)a[n] % k]) % M;
  ans = ans * m % M;
  if (a[n] * (ll)m % k == 0) ans -= m - 1;
  printf("%lld\n", ans);
  return 0;
}
