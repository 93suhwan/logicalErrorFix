#include <bits/stdc++.h>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n;
char c, s[300005];
void Solve() {
  std::cin >> n >> c >> (s + 1);
  if (std::all_of(s + 1, s + n + 1, [](const char &x) { return x == c; })) {
    std::cout << "0\n";
    return;
  }
  int p = n / 2 + 1;
  for (int i = 1; i <= p; i++)
    if (s[p] == c) {
      std::cout << "1\n" << p << "\n";
      return;
    }
  std::cout << "2\n" << n << ' ';
  for (int i = 2; i < n; i++)
    if (n % i) {
      std::cout << i << '\n';
      return;
    }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}
