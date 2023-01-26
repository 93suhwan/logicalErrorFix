#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
void solve() {
  long long x, n;
  scanf("%lld%lld", &x, &n);
  if (x & 1) {
    long long t = n / 4;
    int a[5] = {0, 1, -1, -1, 1};
    for (long long i = 4 * t + 1; i <= n; i++) {
      x += i * a[i - 4 * t];
    }
  } else {
    long long t = n / 4;
    int a[5] = {0, -1, 1, 1, -1};
    for (long long i = 4 * t + 1; i <= n; i++) {
      x += i * a[i - 4 * t];
    }
  }
  printf("%lld\n", x);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
