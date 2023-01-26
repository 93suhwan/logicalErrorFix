#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long mod = 998244353;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x = mod - 2) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
template <class T, class... T_>
inline void re(T &x, T_ &...y) {
  re(x), re(y...);
}
int m, n, t = 1, st, en;
int a[N], b[N], c[N], d[N];
struct SegT {
  long long e[N << 2], tag[N << 2];
  inline void push_up(int p) {
    e[p] = (e[((p) << 1)] + e[((p) << 1 | 1)]) % mod;
  }
  void build(int p, int l, int r) {
    e[p] = tag[p] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(((p) << 1), l, mid);
    build(((p) << 1 | 1), mid + 1, r);
  }
  inline void push_down(int p, int l, int r) {
    if (tag[p]) {
      int mid = (l + r) >> 1;
      (e[((p) << 1)] += 1ll * (mid - l + 1) * tag[p] % mod) %= mod;
      (tag[((p) << 1)] += tag[p]) %= mod;
      (e[((p) << 1 | 1)] += 1ll * (r - mid) * tag[p] % mod) %= mod;
      (tag[((p) << 1 | 1)] += tag[p]) %= mod;
      tag[p] = 0;
    }
  }
  void update(int p, int l, int r, int L, int R, long long k) {
    if (L <= l && r <= R)
      return (e[p] += 1ll * (r - l + 1) * k % mod) %= mod, (tag[p] += k) %= mod,
             void();
    int mid = (l + r) >> 1;
    push_down(p, l, r);
    if (L <= mid) update(((p) << 1), l, mid, L, R, k);
    if (mid < R) update(((p) << 1 | 1), mid + 1, r, L, R, k);
    push_up(p);
  }
  long long query(int p, int l, int r, int L, int R) {
    long long ans = 0;
    if (L <= l && r <= R) return e[p];
    int mid = (l + r) >> 1;
    push_down(p, l, r);
    if (L <= mid) (ans += query(((p) << 1), l, mid, L, R)) %= mod;
    if (mid < R) (ans += query(((p) << 1 | 1), mid + 1, r, L, R)) %= mod;
    return ans;
  }
} tr;
int main() {
  re(t);
  while (t--) {
    re(n);
    tr.build(1, 1, n);
    for (int i = 1; i <= n; i++) re(a[i]), b[i] = c[i] = d[i] = 0;
    long long ans = 0, now = 0;
    for (int i = 1; i <= n; i++) {
      auto calc = [&](int x, int y) { return x / ((x + y - 1) / y); };
      auto times = [&](int x, int y) { return (x + y - 1) / y - 1; };
      c[i] = a[i];
      d[i] = 0;
      for (int j = i - 1; j >= 1; j--) {
        now -= 1ll * d[j] * j;
        d[j] = times(a[j], c[j + 1]);
        now += 1ll * d[j] * j;
        if (calc(a[j], c[j + 1]) == c[j]) break;
        c[j] = calc(a[j], c[j + 1]);
      }
      (ans += now) %= mod;
    }
    printf("%lld\n", ans);
  }
}
