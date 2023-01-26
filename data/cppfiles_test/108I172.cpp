#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const double eps = 1e-11;
template <class T>
using vi2 = vector<vector<T>>;
using ll = long long;
using pii = pair<int, int>;
using ull = unsigned long long;
template <class T>
T fp(T a, int b) {
  T res = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) res = res * a;
  return res;
}
struct MINT {
  int num;
  MINT(ll x = 0) {
    x %= MOD;
    if (x < 0) x += MOD;
    num = x;
  }
  inline int val() const { return num; }
  MINT inv() const { return fp(*this, MOD - 2); }
  MINT operator-() { return MINT(MOD - num); }
  MINT operator+(const MINT x) const {
    return MINT(num + x.num >= MOD ? num + x.num - MOD : num + x.num);
  }
  MINT operator-(const MINT x) const {
    return MINT(num - x.num < 0 ? num - x.num + MOD : num - x.num);
  }
  MINT operator*(const MINT x) const { return MINT(1LL * num * x.num % MOD); }
  MINT operator/(const MINT x) const { return *this * x.inv(); }
};
int main() {
  auto solve = [&]() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    vector<tuple<int, int, int>> a(n + 1);
    for (int i = 1, _i = int(n); i <= _i; i++) cin >> get<0>(a[i]);
    for (int i = 1, _i = int(n); i <= _i; i++) cin >> get<1>(a[i]);
    for (int i = 1, _i = int(n); i <= _i; i++) get<2>(a[i]) = i;
    sort(a.begin() + 1, a.end());
    vector<int> pre(n + 1), sur(n + 2);
    for (int i = 1, _i = int(n); i <= _i; i++)
      pre[i] = max(pre[i - 1], get<1>(a[i]));
    for (int i = n, _i = int(1); i >= _i; i--)
      sur[i] = max(sur[i + 1], get<1>(a[i]));
    for (int i = 1, _i = int(n); i <= _i; i++) {
      if (pre[i] >= sur[n]) ans[get<2>(a[i])] = 1;
    }
    for (int i = 1, _i = int(n); i <= _i; i++) cout << ans[i];
    cout << endl;
  };
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
