#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int64_t p(long long n) {
  int64_t ans = 1;
  for (long long i = 0; i < n; i++) ans *= 10;
  return ans;
}
void solve() {
  long long x, n;
  cin >> x >> n;
  if (x % 2 == 0) {
    long long y = n % 4;
    if (y == 0) {
      cout << x << '\n';
      return;
    }
    long long i = n - y + 1;
    while (i <= n) {
      if (x & 1)
        x += i;
      else
        x -= i;
      i++;
    }
    cout << x << '\n';
  } else {
    long long y = n % 4;
    if (y == 0) {
      cout << x << '\n';
      return;
    }
    long long i = n - y + 1;
    while (i <= n) {
      if (x & 1)
        x += i;
      else
        x -= i;
      i++;
    }
    cout << x << '\n';
  }
}
int32_t main() {
  long long test_cases;
  cin >> test_cases;
  while (test_cases--) {
    solve();
  }
}
