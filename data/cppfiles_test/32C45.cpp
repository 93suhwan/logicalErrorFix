#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
using ll = long long;
using vi = vector<int>;
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int pow_mod(int q, int w) {
  int ret = 1;
  while (w) {
    if (w & 1) ret = mul(ret, q);
    q = mul(q, q);
    w >>= 1;
  }
  return ret;
}
namespace Polynomial {
vector<int> rev = {0, 1};
inline int getlen(int x) {
  int len = 1;
  while (len <= x) len <<= 1;
  return len;
}
void dft(vi &a, int on) {
  int cnt = 0, len = a.size();
  while ((1 << cnt) < len) ++cnt;
  rev.resize(len);
  for (int i = 0; i < len; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int h = 1; h < len; h <<= 1) {
    int wn = pow_mod(3, (mod - 1) / (h << 1));
    for (int j = 0; j < len; j += (h << 1)) {
      int w = 1;
      for (int k = j; k < j + h; k++) {
        int u = a[k] % mod;
        int t = 1ll * w * a[k + h] % mod;
        a[k] = (u + t) % mod;
        a[k + h] = (u + mod - t) % mod;
        w = 1ll * w * wn % mod;
      }
    }
  }
  if (on == -1) {
    for (int i = 1; i < len / 2; i++) swap(a[i], a[len - i]);
    int inv = pow_mod(len, mod - 2);
    for (int i = 0; i < len; i++) a[i] = (ll)a[i] * inv % mod;
  }
}
vi mul(vi a, vi b) {
  int n = a.size() - 1;
  int m = b.size() - 1;
  int len = getlen(n + m);
  vi c(len);
  a.resize(len);
  b.resize(len);
  dft(a, 1), dft(b, 1);
  for (int i = 0; i < len; ++i) {
    c[i] = (ll)a[i] * b[i] % mod;
  }
  dft(c, -1);
  return c;
}
}  // namespace Polynomial
vi &operator+=(vi &a, const vi &b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < b.size(); ++i) {
    add(a[i], b[i]);
  }
  return a;
}
vi operator+(const vi &a, const vi &b) {
  vi c = a;
  return c += b;
}
vi &operator-=(vi &a, const vi &b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < b.size(); ++i) {
    sub(a[i], b[i]);
  }
  return a;
}
vi operator-(const vi &a, const vi &b) {
  vi c = a;
  return c -= b;
}
vi &operator*=(vi &a, const vi &b) {
  if (min(a.size(), b.size()) < 128) {
    vi c = a;
    a.assign(a.size() + b.size() - 1, 0);
    for (int i = 0; i < c.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        add(a[i + j], mul(c[i], b[j]));
      }
    }
  } else {
    a = Polynomial::mul(a, b);
  }
  return a;
}
vi operator*(const vi &a, const vi &b) {
  vi c = a;
  return c *= b;
}
vi shift(vi a) {
  reverse(a.begin(), a.end());
  a.pop_back();
  reverse(a.begin(), a.end());
  for (int i = 0; i < a.size(); i += 1) {
    a[i] = mul(a[i], mod + 1 >> 1);
  }
  return a;
}
const int maxn = 1e5 + 233;
vi poly[maxn << 2][2][2];
int a[maxn];
int b[maxn];
int n;
int fac[maxn];
int inv[maxn];
void solve(int o, int l, int r) {
  if (l == r) {
    poly[o][0][0] = vi{0, b[l] == 1 ? 1 : 2};
    poly[o][0][1] = poly[o][1][0] = poly[o][1][1] = vi{0, 2};
    return;
  }
  int mid = l + r >> 1;
  solve(o << 1, l, mid);
  solve(o << 1 | 1, mid + 1, r);
  for (int i = 0; i < 2; i += 1) {
    for (int j = 0; j < 2; j += 1) {
      poly[o][i][j] += poly[o << 1][i][0] * poly[o << 1 | 1][0][j];
      poly[o][i][j] += shift(poly[o << 1][i][1] * poly[o << 1 | 1][1][j]);
    }
  }
}
int choose(int x, int y) {
  if (x < y || x < 0 || y < 0) return 0;
  return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  fac[0] = inv[0] = 1;
  cin >> n;
  for (int i = 1; i <= n; i += 1) {
    cin >> a[i];
    fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[i] = pow_mod(fac[i], mod - 2);
  }
  int cnt = 0;
  int res = 1;
  for (int i = 1; i <= n; i += 1) {
    int cur = a[i];
    b[++cnt] = cur;
    for (int j = 1; j <= cur; j += 1) {
      if (a[j + i - 1] != a[i]) res = 0;
    }
    i += cur - 1;
  }
  if (res == 0) {
    cout << "0\n";
    return 0;
  }
  res = 0;
  solve(1, 1, cnt);
  auto &c = poly[1][0][0];
  for (int i = 1; i <= cnt; i += 1) {
    c[i] = mul(c[i], fac[i]);
    if (cnt - i & 1)
      sub(res, c[i] % mod);
    else
      add(res, c[i]);
  }
  cout << res << "\n";
  return 0;
}
