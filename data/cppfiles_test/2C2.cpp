#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e6 + 100;
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
struct base {
  double a, b;
  base() {}
  base(double x) : a(x), b(0) {}
  base(double x, double y) : a(x), b(y) {}
  friend base operator+(const base& a, const base& b) {
    return base(a.a + b.a, a.b + b.b);
  }
  friend base operator-(const base& a, const base& b) {
    return base(a.a - b.a, a.b - b.b);
  }
  friend base operator*(const base& a, const base& b) {
    return base(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
  }
  friend base operator/(const base& a, double b) {
    return base(a.a / b, a.b / b);
  }
};
int a[N], pref[N], suff[N], blocks[N];
ll res[N];
base b[N];
void fft(base* a, int n, bool inv) {
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n / 2;
    for (; j >= bit; bit /= 2) {
      j -= bit;
    }
    j += bit;
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (int len = 2; len <= n; len *= 2) {
    double ang = 2 * pi / len * (inv ? -1 : 1);
    base wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      base w(1);
      for (int j = 0; j < len / 2; ++j) {
        base u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w = w * wlen;
      }
    }
  }
  if (inv) {
    for (int i = 0; i < n; ++i) {
      a[i] = a[i] / n;
    }
  }
}
void multiply(int* fa, int* fb, ll* fc, int k) {
  int n = 1;
  while (n < k) {
    n *= 2;
  }
  n *= 2;
  for (int i = 0; i < n; ++i) {
    if (i < k) {
      b[i].a = fa[i];
      b[i].b = fb[i];
    } else {
      b[i] = base(0);
    }
  }
  fft(b, n, false);
  for (int i = 0; i < n; ++i) {
    b[i] = b[i] * b[i];
  }
  fft(b, n, true);
  for (int i = 0; i < k; ++i) {
    fc[i] = (ll(b[i].b + 0.5) + ll(b[i + k].b + 0.5)) / 2;
  }
}
void solve() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[i] %= k;
  }
  int ans = 0;
  if (m >= 2) {
    int cur_suff = 0;
    for (int i = n - 1; i >= 0; --i) {
      cur_suff += a[i];
      if (cur_suff >= k) {
        cur_suff -= k;
      }
      ++suff[cur_suff];
    }
    int cur_blocks = 0;
    for (int i = 0; i <= m - 2; ++i) {
      ++blocks[cur_blocks];
      cur_blocks += cur_suff;
      if (cur_blocks >= k) {
        cur_blocks -= k;
      }
    }
    multiply(suff, blocks, res, k);
    int pref = 0;
    for (int r = 0; r < n; ++r) {
      pref += a[r];
      if (pref >= k) {
        pref -= k;
      }
      int x = (pref == 0 ? 0 : k - pref);
      ans = (ans + res[x]) % MOD;
    }
  }
  ++pref[0];
  int cur_pref = 0;
  for (int r = 0; r < n; ++r) {
    cur_pref += a[r];
    if (cur_pref >= k) {
      cur_pref -= k;
    }
    ans = (ans + pref[cur_pref]) % MOD;
    ++pref[cur_pref];
  }
  int blocks = (ll(cur_pref) * (m - 1)) % k;
  int full = (ll(cur_pref) * m) % k;
  int cur_suff = 0;
  for (int i = 0; i < k; ++i) {
    suff[i] = 0;
  }
  for (int i = n - 1; i >= 0; --i) {
    int val = cur_pref + blocks;
    if (val >= k) {
      val -= k;
    }
    val = (val == 0 ? 0 : k - val);
    ans = (ans + suff[val]) % MOD;
    cur_suff += a[i];
    if (cur_suff >= k) {
      cur_suff -= k;
    }
    ++suff[cur_suff];
    cur_pref -= a[i];
    if (cur_pref < 0) {
      cur_pref += k;
    }
  }
  if (full == 0 && m >= 2) {
    --ans;
    if (ans < 0) {
      ans += MOD;
    }
  }
  if (full == 0 && m == 1) {
    --ans;
    if (ans < 0) {
      ans += MOD;
    }
  }
  if (full == 0) {
    ans -= n - 1;
    if (ans < 0) {
      ans += MOD;
    }
  }
  ans = (ll(ans) * m) % MOD;
  if (full == 0) {
    ++ans;
    if (ans >= MOD) {
      ans -= MOD;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
