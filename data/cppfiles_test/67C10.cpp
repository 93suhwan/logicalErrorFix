#include <bits/stdc++.h>
int n;
double p;
double C2(double x) {
  if (x < 1) return 0;
  return x * (x - 1) / 2;
}
double C3(double x) {
  if (x < 2) return 0;
  return x * (x - 1) * (x - 2) / 6;
}
int main() {
  std::cin >> n >> p;
  for (int i = 0; i <= n; i++)
    if ([&](int x) {
          double an = (double)C2(n - x) * x / C3(n) * (1.0 / 3 + 1.0 / 6) +
                      (double)(n - x) * C2(x) / C3(n) + (double)C3(x) / C3(n);
          return an >= p;
        }(i))
      return std::cout << i, 0;
}
