#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    x[i] /= 2;
    y[i] /= 2;
  }
  long long res = 0, res2 = 0;
  for (int i = 0; i < n; ++i) {
    long long odd = 0, even = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }
      if ((x[j] + x[i]) % 2 == 0 && (y[j] + y[i]) % 2 == 0) {
        ++even;
      } else {
        ++odd;
      }
    }
    res += even * odd;
    res2 += even * (even - 1) / 2;
  }
  printf("%lld\n", res / 2LL + res2 / 3LL);
}
int main() {
  int t;
  t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
