#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 0, s = 0;
  char c = getchar();
  while (c > '9' || c < '0') f = (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    s = (s << 3) + (s << 1) + (c ^ '0'), c = getchar();
  return f ? -s : s;
}
const long long N = 200005;
long long T, s = 0;
long long n, a[N];
long long ans = 0;
map<long long, long long> mp;
void work() {
  n = read();
  s = 0;
  mp.clear();
  ans = 0;
  for (long long i = 1; i <= n; i++) a[i] = read(), s += a[i];
  for (long long i = 1; i <= n; i++) {
    ans += mp[2 * s - n * a[i]];
    mp[n * a[i]]++;
  }
  printf("%lld\n", ans);
  return;
}
signed main() {
  T = read();
  while (T--) work();
  return 0;
}
