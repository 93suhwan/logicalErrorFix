#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long inf = 1LL << 62;
int t, n, k;
int a[N];
inline long long max(long long x, long long y) { return x > y ? x : y; }
void work() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long ans = -inf;
  for (long long j = 1; j <= n; j++)
    for (long long i = max(1, j - 2 * k); i < j; i++)
      ans = max(ans, i * j - k * (a[i] | a[j]));
  printf("%lld\n", ans);
  return;
}
int main() {
  scanf("%d", &t);
  while (t--) work();
}
