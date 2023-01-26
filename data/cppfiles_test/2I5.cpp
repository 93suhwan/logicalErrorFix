#include <bits/stdc++.h>
using namespace std;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int maxn = 1e6 + 7, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int MAXN = 1 << 20;
const double PI = acos(-1);
const long long MOD = 1000000007;
struct Complex {
  double real, imag;
  Complex(double R = 0, double I = 0) {
    real = R;
    imag = I;
  }
  Complex operator+(const Complex &p) const {
    return Complex(real + p.real, imag + p.imag);
  }
  Complex operator-(const Complex &p) const {
    return Complex(real - p.real, imag - p.imag);
  }
  Complex operator*(const Complex &p) const {
    return Complex(real * p.real - imag * p.imag,
                   real * p.imag + imag * p.real);
  }
} f[MAXN << 2], g[MAXN << 2], h[MAXN << 2], wn[2][MAXN << 2];
int n, m, k, N;
int rev[MAXN << 2];
long long cnt[MAXN];
void FFTinit(int l) {
  N = 1;
  while (N < l) N <<= 1;
  for (int i = 1; i < N; i++) rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (N >> 1);
  int half = N >> 1;
  for (int i = 0; i < half; i++) {
    wn[0][half + i] = Complex(cos(PI * i / half), sin(PI * i / half));
    wn[1][half + i] = Complex(cos(PI * i / half), -sin(PI * i / half));
  }
  for (int i = half - 1; i >= 0; i--) {
    wn[0][i] = wn[0][i << 1];
    wn[1][i] = wn[1][i << 1];
  }
}
void FFT(Complex *v, int inv) {
  for (int i = 0; i < N; i++)
    if (i < rev[i]) swap(v[i], v[rev[i]]);
  for (int i = 1; i < N; i <<= 1)
    for (int j = 0; j < N; j += (i << 1)) {
      Complex *l = v + j, *r = v + j + i, *w = wn[inv == -1] + i, A;
      for (int k = 0; k < i; k++, l++, r++, w++) {
        A = *w * *r;
        *r = *l - A;
        *l = *l + A;
      }
    }
  if (inv == -1) {
    Complex Inv(1.0 / N, 0);
    for (int i = 0; i < N; i++) v[i] = v[i] * Inv;
  }
}
int a[maxn], pre[maxn], lst[maxn];
long long res[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pre[i] = (pre[i - 1] + a[i]) % k;
  }
  long long ans = 0;
  if (k == 1) {
    long long v = 1ll * n * m % mod;
    cout << (v % mod * v % mod - v + 1 + mod) % mod << '\n';
    return 0;
  }
  if (m == 1) {
    if (pre[n] == 0) ans = 1;
    for (int i = n + 1; i <= 2 * n; ++i)
      a[i] = a[i - n], pre[i] = (pre[i - 1] + a[i]) % k;
    map<int, int> vis;
    vis[0] = 1;
    for (int i = 1; i < 2 * n; ++i) {
      if (i - n >= 0) {
        vis[pre[i - n]]--;
        ans = (ans + vis[pre[i]]) % mod;
      }
      vis[pre[i]]++;
    }
    cout << ans << '\n';
  } else {
    for (int i = n; i >= 1; --i) {
      lst[i] = (lst[i + 1] + a[i]) % k;
    }
    FFTinit(k * 3 + 3);
    for (int i = 1; i <= n; ++i) {
      f[pre[i]].real++;
      h[lst[i]].real++;
    }
    for (int i = 0; i <= m - 2; ++i) g[1ll * pre[n] * i % k].real++;
    FFT(f, 1), FFT(h, 1), FFT(g, 1);
    for (int i = 0; i < N; ++i) f[i] = f[i] * h[i] * g[i];
    FFT(f, -1);
    for (int i = 0; i < N; ++i)
      res[i % k] = (res[i % k] + (long long)(f[i].real + 0.5) % mod) % mod;
    ans = res[0] * m % mod;
    ;
    if ((pre[n] * m) % k == 0) ans++;
    map<int, int> vis;
    vis[0] = 1;
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
      tmp = (tmp + vis[pre[i]]) % mod;
      vis[pre[i]]++;
    };
    ans = (ans + 1ll * tmp * m % mod) % mod;
    cout << ans << '\n';
  }
  return 0;
}
