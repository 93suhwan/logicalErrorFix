#include <bits/stdc++.h>
using namespace std;
long long dv2(long long a) {
  if (a & 1) return a / 2 + 1;
  return a / 2;
}
void work(long long s, long long n, long long k) {
  long long lim = 0;
  if (s == k) return puts("Yes"), void();
  lim += (k - s % k) * dv2(s / k);
  lim += s % k * dv2(s / k + 1);
  puts(n > lim ? "Yes" : "No");
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
