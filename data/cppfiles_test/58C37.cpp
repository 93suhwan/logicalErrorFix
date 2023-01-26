#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma loop - opt(on)
using namespace std;
struct BIT {
  static const long long int n = (1 << 19), lg = 19;
  vector<long long int> cnt = vector<long long int>(n + 1, 0);
  stack<long long int> op;
  long long int lowbit(long long int x) { return x & (-x); }
  void modify(long long int x, long long int v) {
    if (v < 0) op.push(x);
    for (long long int i = x; i <= n; i += lowbit(i)) {
      cnt[i] += v;
    }
  }
  long long int query(long long int k) {
    long long int ans = 0, cal = 0;
    for (long long int i = lg - 1; i >= 0; i--)
      if (cal + cnt[ans | (1 << i)] < k) {
        ans = (ans | (1 << i)), cal += cnt[ans];
      }
    return ans + 1;
  }
  void init_() {
    while (op.size()) {
      long long int x = op.top();
      op.pop();
      modify(x, 1);
    }
  }
};
namespace solver {
long long int n, m;
BIT bit;
const long long int P = (1 << 19);
vector<long long int> x, y, fac, inv;
vector<pair<long long int, long long int> > a;
long long int pow_(long long int a, long long int times) {
  long long int ans = 1;
  for (; times > 0; times >>= 1, a = a * a % 998244353) {
    if (times & 1) ans = ans * a % 998244353;
  }
  return ans;
}
void build() {
  fac.assign(P, 1);
  inv.assign(P, 1);
  for (long long int i = 1; i <= P - 1; i++)
    fac[i] = fac[i - 1] * i % 998244353;
  inv[P - 1] = pow_(fac[P - 1], 998244353 - 2);
  for (long long int i = P - 2; i >= 0; i--)
    inv[i] = inv[i + 1] * (i + 1) % 998244353;
  for (long long int i = 1; i <= P; i++) bit.modify(i, 1);
}
long long int C(long long int n, long long int m) {
  return fac[n] * inv[m] % 998244353 * inv[n - m] % 998244353;
}
void init_(long long int _n, long long int _m) {
  n = _n, m = _m;
  x.assign(m + 1, 0);
  y.assign(m + 1, 0);
  a.clear();
  bit.init_();
}
long long int solve() {
  for (long long int i = m; i >= 1; i--) {
    long long int id = bit.query(y[i]);
    a.push_back({id, x[i]});
    bit.modify(id, -1);
  }
  long long int c = m;
  sort(a.begin(), a.end());
  for (long long int i = 1; i <= m - 1; i++) {
    if (a[i].first == a[i - 1].first + 1 && a[i].second > a[i - 1].second) c--;
  }
  return C(2 * n - 1 - c, n);
}
};  // namespace solver
using namespace solver;
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long int t;
  cin >> t;
  build();
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    init_(n, m);
    for (long long int i = 1; i <= m; i++) cin >> x[i] >> y[i];
    cout << solve() << "\n";
  }
  return 0;
}
