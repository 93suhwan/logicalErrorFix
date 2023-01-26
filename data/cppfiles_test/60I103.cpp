#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int test;
  std::cin >> test;
  while (test--) {
    long long n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> fre;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      fre[a[i]]++;
      sum += a[i];
    }
    if (sum % n != 0) {
      std::cout << 0 << '\n';
      ;
      continue;
    }
    long long x = sum - sum / n * (n - 2);
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
