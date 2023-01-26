#include <bits/stdc++.h>
using namespace std;
const long long N = 300000;
long long f[N + 2];
void updf(long long x, long long d) {
  if (x > N) return;
  for (; x <= N; x += (x & -x)) f[x] += d;
}
long long cntf(long long x) {
  long long ans = 0;
  for (x = min(x, N); x > 0; x -= (x & -x)) ans += f[x];
  return ans;
}
long long fn[N + 2];
void updfn(long long x, long long d) {
  if (x > N) return;
  for (; x <= N; x += (x & -x)) fn[x] += d;
}
long long cntfn(long long x) {
  long long ans = 0;
  for (x = min(x, N); x > 0; x -= (x & -x)) ans += fn[x];
  return ans;
}
long long g[N + 2];
void updg(long long x, long long d) {
  if (x > N) return;
  for (; x <= N; x += (x & -x)) g[x] += d;
}
long long cntg(long long x) {
  long long ans = 0;
  for (x = min(x, N); x > 0; x -= (x & -x)) ans += g[x];
  return ans;
}
int main() {
  long long n;
  scanf("%lld", &n);
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    ans += x * i - cntg(x);
    for (long long j = 0; j <= N; j += x)
      ans += cntf(j + x - 1) - cntf(j) - j * (cntfn(j + x - 1) - cntfn(j));
    printf("%lld ", ans);
    updfn(x, 1);
    updf(x, x);
    for (long long j = x; j <= N; j += x) {
      updg(j, j);
      updg(j + x, -j);
    }
  }
  printf("\n");
  return 0;
}
