#include <bits/stdc++.h>
const int mxn = 2e5 + 5, mxk = 5;
const int mod = 1e9 + 7;
inline int qpow(int x, int n) {
  int ans = 1;
  for (; n; n >>= 1, x = 1LL * x * x % mod)
    if (n & 1) ans = 1LL * ans * x % mod;
  return ans;
}
int n, q;
int a[mxn];
struct Query {
  int l, d, i;
};
std::vector<Query> qry[mxn];
struct BIT {
  int s[mxn];
  void update(int x, int v) {
    for (++x; x < mxn; x += x & -x) s[x] = (s[x] + v) % mod;
  }
  int query(int x) {
    int ans = 0;
    for (++x; x; x -= x & -x) ans = (ans + s[x]) % mod;
    return ans;
  }
} bit[mxk];
int calc(int l, int r, int k) {
  return (bit[k].query(r) + mod - bit[k].query(l - 1)) % mod;
}
int binom[mxk][mxk];
int pref[mxn][mxk];
struct __INIT__ {
  __INIT__() {
    for (int i = 0; i < (int)(mxk); ++i)
      for (int j = 0; j < (int)(i + 1); ++j)
        binom[i][j] = j ? binom[i - 1][j - 1] + binom[i - 1][j] : 1;
    for (int i = 0; i < (int)(mxn); ++i)
      for (int j = 0; j < (int)(mxk); ++j)
        pref[i + 1][j] = (pref[i][j] + qpow(i, j)) % mod;
  }
} __;
int calc_real(int l, int r, int d, int k) {
  int sum = calc(l, r, 1);
  int rest =
      (sum + mod - 1LL * ((1LL * (r - l + 1) * (r - l) / 2) % mod) * d % mod) %
      mod;
  int start = 1LL * rest * qpow(r - l + 1, mod - 2) % mod;
  int ans = 0;
  for (int j = 0; j < (int)(k + 1); ++j)
    ans = (ans + 1LL * binom[k][j] * qpow(start, j) % mod * qpow(d, k - j) %
                     mod * pref[r - l + 1][k - j]) %
          mod;
  return ans;
}
bool ans[mxn];
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", &a[i]);
  for (int i = 0; i < (int)(q); ++i) {
    int l, r, d;
    scanf("%d %d %d", &l, &r, &d);
    --l, --r;
    qry[r].push_back({l, d, i});
  }
  std::map<int, int> last;
  for (int r = 0; r < (int)(n); ++r) {
    if (last.find(a[r]) != last.end()) {
      for (int k = 0; k < (int)(mxk); ++k)
        bit[k].update(last[a[r]], mod - qpow(a[r], k));
    }
    last[a[r]] = r;
    for (int k = 0; k < (int)(mxk); ++k) bit[k].update(r, qpow(a[r], k));
    for (auto Q : qry[r]) {
      int l = Q.l, d = Q.d, i = Q.i;
      ans[i] = true;
      for (int k = 0; k < (int)(mxk); ++k)
        ans[i] &= calc(l, r, k) == calc_real(l, r, d, k);
    }
  }
  for (int i = 0; i < (int)(q); ++i) puts(ans[i] ? "Yes" : "No");
  return 0;
}
