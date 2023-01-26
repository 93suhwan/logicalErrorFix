#include <bits/stdc++.h>
using namespace std;
namespace Solve {
inline int mymin(long long a, long long b) { return a < b ? a : b; }
long long a, b, c;
int calc(int src, int d, int nd) {
  int ret = src;
  if (nd & 1)
    ret = abs(ret - d);
  else if (nd > 0)
    ret = mymin(ret, abs(ret - 2 * d));
  return ret;
}
void work() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &a, &b, &c);
    long long ans = 0;
    ans = calc(ans, 3, c);
    ans = calc(ans, 2, b);
    ans = calc(ans, 1, a);
    printf("%lld\n", ans);
  }
  return;
}
}  // namespace Solve
int main() {
  Solve::work();
  return 0;
}
