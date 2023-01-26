#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
void solve() {
  long long n, m, i, j, f = 1, k, b, a, t = 0;
  scanf("%lld%lld", &a, &b);
  n = a + b;
  a = min(a, b);
  t = n / 2;
  k = t - a;
  if (n % 2) {
    cout << (t - k + 1) * 2 << "\n";
    for (i = k; i <= t; i++) {
      printf("%d ", i);
    }
    for (i = t; i >= k; i--) {
      printf("%d ", n - i);
    }
    printf("\n");
  } else {
    cout << (t - k) * 2 << "\n";
    for (i = k; i < t; i++) {
      printf("%d ", i);
    }
    for (i = t - 1; i >= k; i--) {
      printf("%d ", n - i);
    }
    printf("\n");
  }
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
