#include <bits/stdc++.h>
using namespace std;
constexpr size_t MAXN = 2e5 + 5;
long long a[MAXN], b[MAXN], cnt[MAXN];
inline long long GCD(long long a, long long b) {
  return !b ? a : GCD(b, a % b);
}
inline void Solve() {
  long long n;
  cin >> n;
  long long sum = 0;
  for (long long i = 1; i <= n; i++) cin >> a[i], sum += a[i], b[i] = a[i];
  long long g = GCD(sum, n);
  if (n / g > 2) {
    cout << "0\n";
    return;
  }
  sum /= g;
  if (n / g == 1) sum <<= 1;
  sort(b + 1, b + n + 1);
  long long tot = unique(b + 1, b + n + 1) - b - 1;
  b[0] = b[tot + 1] = -114514;
  for (long long i = 1; i <= tot; i++) cnt[i] = 0;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long pos = lower_bound(b + 1, b + tot + 1, sum - a[i]) - b;
    if (b[pos] == sum - a[i]) ans += cnt[pos];
    pos = lower_bound(b + 1, b + tot + 1, a[i]) - b;
    cnt[pos]++;
  }
  cout << ans << '\n';
}
signed main(void) {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) Solve();
}
