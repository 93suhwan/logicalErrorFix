#include <bits/stdc++.h>
using i64 = long long;
template <typename T>
struct Fenwick {
  const int n;
  std::vector<T> a;
  Fenwick(int n) : n(n), a(n) {}
  void add(int x, T v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] += v;
    }
  }
  T sum(int x) {
    T ans = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      ans += a[i - 1];
    }
    return ans;
  }
  T rangeSum(int l, int r) { return sum(r) - sum(l - 1); }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  const int m = *std::max_element(a.begin(), a.end());
  i64 ans = 0;
  Fenwick<i64> f1(m + 1), f2(m + 1);
  i64 suma = 0;
  for (int i = 0; i < n; i++) {
    ans += i64(i) * a[i];
    ans -= f1.sum(a[i]);
    for (int j = a[i]; j <= m; j += a[i]) {
      f1.add(j, a[i]);
    }
    ans += suma;
    for (int j = a[i]; j <= m; j += a[i]) {
      ans -= f2.rangeSum(j, m) * a[i];
    }
    f2.add(a[i], 1);
    suma += a[i];
    std::cout << ans << " \n"[i == n - 1];
  }
  return 0;
}
