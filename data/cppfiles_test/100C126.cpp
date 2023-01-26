#include <bits/stdc++.h>
int main() {
  std::cin.tie(NULL)->ios_base::sync_with_stdio(false);
  int t, n, max, a[200000];
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a, a + n);
    max = a[0];
    for (int i = 1; i < n; i++)
      if (a[i] - a[i - 1] > max) max = a[i] - a[i - 1];
    std::cout << max << '\n';
  };
  return 0;
};
