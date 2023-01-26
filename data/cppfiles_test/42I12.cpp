#include <bits/stdc++.h>
using namespace std;
const int N = 200000, mod = 1000000007;
template <typename T, typename T2, T mod>
struct modint {
  using mint = modint<T, T2, mod>;
  T v;
  modint() : v() {}
  modint(T V) : v(V) {}
  static constexpr T umod() { return mod; }
  mint &operator+=(const mint &p) {
    v = v + p.v >= mod ? v + p.v - mod : v + p.v;
    return *this;
  }
  mint &operator-=(const mint &p) {
    v = v < p.v ? v + mod - p.v : v - p.v;
    return *this;
  }
  mint &operator*=(const mint &p) {
    v = T2(v) * p.v % mod;
    return *this;
  }
  mint &operator++() {
    v + 1 < mod ? ++v : v = 0;
    return *this;
  }
  mint operator++(int) {
    mint res = *this;
    v + 1 < mod ? ++v : v = 0;
    return res;
  }
  mint &operator--() {
    v ? --v : v = mod - 1;
    return *this;
  }
  mint operator--(int) {
    mint res = *this;
    v ? --v : v = mod - 1;
    return res;
  }
  friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
  friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
  friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
  friend mint operator-(const mint &b) { return mint(0) -= b; }
  friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
  friend bool operator!=(const mint &a, const mint &b) { return a.v != b.v; }
  template <typename Temp>
  mint pow(Temp k) {
    mint a = *this, res = 1;
    for (; k; k /= 2, a *= a)
      if (k & 1) res *= a;
    return res;
  }
  mint inv() { return pow(mod - 2); }
};
int n, m;
struct seg {
  int l, r;
  seg(int L = 0, int R = 0) : l(L), r(R) {}
} a[N + 9], b[N + 9];
void into() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int p;
    scanf("%d", &p);
    b[i] = a[p];
  }
}
modint<int, long long, mod> c[N * 2 + 9];
void Add(int p, modint<int, long long, mod> v) {
  for (; p <= n << 1; p += p & -p) c[p] += v;
}
modint<int, long long, mod> Query(int p) {
  modint<int, long long, mod> res = 0;
  for (; p; p -= p & -p) res += c[p];
  return res;
}
modint<int, long long, mod> Query(int l, int r) {
  return Query(r) - Query(l - 1);
}
modint<int, long long, mod> dp[N * 2 + 9];
void Get_dp() {
  sort(a + 1, a + n + 1, [&](const seg &a, const seg &b) { return a.r < b.r; });
  for (int i = 1; i <= n; ++i) {
    auto [l, r] = a[i];
    Add(l, dp[r] = Query(l, r) + 1);
  }
}
modint<int, long long, mod> sum[N * 2 + 9], ans;
void Get_ans() {
  for (int i = 1; i <= n << 1; ++i) sum[i] = dp[i] + sum[i - 1];
  sort(b + 1, b + m + 1, [&](const seg &a, const seg &b) { return a.r > b.r; });
  for (int i = 1, lim = 0; i <= m; ++i) {
    auto [l, r] = b[i];
    if (b[i].l < lim) continue;
    ans += sum[b[i].r - 1] - sum[lim] + 1;
    lim = b[i].l;
  }
}
void work() {
  Get_dp();
  Get_ans();
}
void outo() { printf("%d\n", ans.v); }
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
