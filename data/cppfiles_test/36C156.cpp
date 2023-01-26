#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::string res(n, 'a');
    if (n == 1)
      0;
    else if (n % 2) {
      res[(n - 3) / 2] = 'b';
      res[n - 1] = 'c';
    } else {
      res[n / 2 - 1] = 'b';
    }
    std::cout << res << "\n";
  }
}
