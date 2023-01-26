#include <bits/stdc++.h>
using namespace std;
int n;
double p;
double f(double x) {
  if (x > n - 1) return 1;
  return -3 * x * x * x + (n - 1) * x * x + (n * n + 2 * n + 2) * x -
         n * (n - 1) * (n - 2) * p;
}
int main() {
  cin >> n >> p;
  double l = 0, r, mid;
  r = (2 * n - 2 + sqrt(16 * n * n + 16 * n + 28)) / 6.0;
  while (r - l > 1e-6) {
    mid = (l + r) * 0.5;
    if (f(mid) < 0)
      l = mid;
    else
      r = mid;
  }
  cout << ceil(mid) << endl;
  return 0;
}
