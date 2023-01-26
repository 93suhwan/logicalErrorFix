#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, ans = 0, t = 1;
  scanf("%lld%lld", &n, &k);
  --n;
  while (n > 0 && t < k) {
    n -= t;
    t <<= 1;
    ++ans;
  }
  printf("%lld\n", n ? ans + (n + k - 1) / k : ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
