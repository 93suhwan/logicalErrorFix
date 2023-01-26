#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long s = 0;
  char c = getchar();
  bool f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = 0;
  for (; c >= '0' && c <= '9'; c = getchar())
    s = (s << 3) + (s << 1) + (c ^ 48);
  return f ? s : ~(s - 1);
}
inline void wt(long long first) { printf("%lld", first); }
inline void wtl(long long first) { printf("%lld\n", first); }
inline void wtb(long long first) { printf("%lld ", first); }
const long long N = 1e6 + 7;
long long dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
long long n, m, k;
long long ans = 0;
void solve() {
  m = rd();
  n = rd();
  for (long long i = 1; i <= n - 1; i++) wtb(1);
  wtl(m - n + 1);
}
signed main() {
  for (long long _ = rd(); _; _--) {
    solve();
  }
  return 0;
}
