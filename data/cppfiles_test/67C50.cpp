#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 1000 + 10;
ll Choose(ll n, ll m) {
  if (m < 0 || m > n) {
    return 0ll;
  }
  ll res = 1;
  for (int i = 0; i < m; ++i) {
    res *= n - i;
  }
  for (int i = 1; i <= m; ++i) {
    res /= i;
  }
  return res;
}
double Calc(int n, int x) {
  return 1.0 - 1.0 * Choose(n - x, 3) / Choose(n, 3) -
         0.5 * x * Choose(n - x, 2) / Choose(n, 3);
}
int main() {
  int n;
  double p;
  scanf("%d %lf", &n, &p);
  for (int k = 0; k <= n; ++k) {
    if (Calc(n, k) >= p) {
      printf("%d\n", k);
      break;
    }
  }
  return 0;
}
