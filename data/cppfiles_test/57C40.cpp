#include <bits/stdc++.h>
using namespace std;
long long dv2(long long a) {
  if (a & 1) return a / 2 + 1;
  return a / 2;
}
void work(long long s, long long n, long long k) {
  if (s == k) return puts("Yes"), void();
  long long lim = 0;
  lim += (s % k + 1) * dv2(s / k + 1);
  lim += (k - s % k - 1) * dv2(s / k);
  puts(n > lim - 1 ? "Yes" : "No");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long s, n, k;
    scanf("%lld%lld%lld", &s, &n, &k);
    work(s, n, k);
  }
  return 0;
}
