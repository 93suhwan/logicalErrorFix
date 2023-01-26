#include <bits/stdc++.h>
using namespace std;
int execute_tests(bool);
long long int f(long long int a, long long int d, long long int N) {
  if (N - a < 0) return 0;
  long long int n = max(0ll, (N - a) / d + 1);
  long long int ret = 2ll * a + (n - 1) * d * 1ll;
  ret *= n;
  ret /= 2ll;
  return ret;
}
void solve() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long int x0;
    scanf("%lld", &x0);
    long long int n;
    scanf("%lld", &n);
    long long int ans;
    if (x0 % 2ll == 0) {
      ans = x0 - (1 + f(4, 4, n) + f(5, 4, n) - f(2, 4, n) - f(3, 4, n));
    } else {
      ans = x0 + 1 + f(4, 4, n) + f(5, 4, n) - f(2, 4, n) - f(3, 4, n);
    }
    printf("%lld", ans);
    ;
    putchar('\n');
  }
}
int main() {
  solve();
  return execute_tests(false);
}
int execute_tests(bool run) { return 0; }
