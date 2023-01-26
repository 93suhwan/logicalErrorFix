#include <bits/stdc++.h>
constexpr int maxn = 1e3 + 10, lim = 1e9;
int query(const int x, const int y) {
  int res = 0;
  std::cout << "? " << x << " " << y << std::endl;
  std::cin >> res;
  if (res == -1) std::exit(-1);
  return res;
}
void answer(const int x1, const int y1, const int x2, const int y2) {
  std::cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
  std::exit(0);
}
void solve() {
  const auto p = query(lim, 1), q = query(lim, lim), d = q - p,
             b = (d + lim) / 2, y = lim - b, t = query(lim, y);
  int l = 1, r = y, mi = -1;
  while (l <= r) {
    const auto mid = (l + r) >> 1;
    if (query(lim, mid) == t)
      mi = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  const auto mx = lim + 1 - mi - d;
  assert(mi <= mx);
  answer(1 + query(1, mi), mi, lim - query(lim, mi), mx);
}
int main() {
  int t = 1;
  for (auto REPN_lIM = t, REPN = 1; REPN <= REPN_lIM; REPN++) solve();
  return (0 - 0);
}
