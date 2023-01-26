#include <bits/stdc++.h>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T;
long long s, n, k;
void Solve() {
  std::cin >> s >> n >> k;
  long long c1 = s % k + 1, c2 = k - c1, l1 = s / k + 1, l2 = s / k;
  l1 = (l1 + 1) >> 1, l2 = (l2 + 1) >> 1;
  if (c1 * l1 + c2 * l2 > n)
    std::cout << "NO\n";
  else
    std::cout << "YES\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
