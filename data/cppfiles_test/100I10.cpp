#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
template <typename T>
T add(T x) {
  return x;
}
template <typename T, typename... Ts>
T add(T x, Ts... y) {
  T res = x + add(y...);
  if (res >= MOD) res -= MOD;
  return res;
}
template <typename T, typename... Ts>
T sub(T x, Ts... y) {
  return add(x, MOD - add(y...));
}
template <typename T, typename... Ts>
void udd(T &x, Ts... y) {
  x = add(x, y...);
}
template <typename T>
T mul(T x) {
  return x;
}
template <typename T, typename... Ts>
T mul(T x, Ts... y) {
  return (x * 1ll * mul(y...)) % MOD;
}
template <typename T, typename... Ts>
void uul(T &x, Ts... y) {
  x = mul(x, y...);
}
int bin(long long a, long long deg) {
  int r = 1;
  while (deg) {
    if (deg & 1) uul(r, a);
    deg >>= 1;
    uul(a, a);
  }
  return r;
}
int inv(long long x) {
  assert(x);
  return bin(x, MOD - 2);
}
vector<int> fac(2 * 1e5 + 1);
void precalc() {
  fac[0] = 1;
  for (int i = 1; i <= 2 * 1e5; ++i) {
    fac[i] = mul(fac[i - 1], i);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &val : a) {
    cin >> val;
  }
  long long maxx = a[0];
  long long maxx_cnt = 1;
  long long second_max = -1;
  long long second_max_cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > maxx) {
      second_max = maxx;
      second_max_cnt = maxx_cnt;
      maxx = a[i];
      maxx_cnt = 1;
    } else if (a[i] == maxx) {
      ++maxx_cnt;
    } else if (second_max < a[i] && a[i] < maxx) {
      second_max = a[i];
      second_max_cnt = 1;
    } else if (a[i] == second_max) {
      ++second_max_cnt;
    }
  }
  if (second_max == -1) {
    cout << fac[n] << "\n";
    return;
  }
  if (maxx_cnt == 2) {
    cout << fac[n] << "\n";
    return;
  }
  if (second_max != maxx - 1) {
    cout << "0\n";
    return;
  }
  cout << mul(fac[n], inv(second_max_cnt + 1), second_max_cnt) << "\n";
}
int main() {
  precalc();
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
