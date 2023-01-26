#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int test;
  std::cin >> test;
  while (test--) {
    long long n;
    std::cin >> n;
    std::vector<double> a(n);
    std::map<double, int> fre;
    double sum = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      fre[a[i]]++;
      sum += a[i];
    }
    double x = sum - sum / n * (n - 2);
    long long res = 0;
    for (int i = 0; i < n; i++) {
      if (x - a[i] == a[i]) {
        res += fre[x - a[i]] - 1;
      } else {
        res += fre[x - a[i]];
      }
    }
    std::cout << res / 2 << '\n';
  }
  return 0;
}
