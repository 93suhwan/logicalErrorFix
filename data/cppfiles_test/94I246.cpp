#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e2 + 10;
long long a[maxn], bin[maxn], can[maxn];
long long n, k, ans;
signed main() {
  bin[0] = 1;
  for (register long long i = 1; i <= 9; ++i) bin[i] = bin[i - 1] * 10;
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (register long long i = 1; i <= n; ++i) cin >> a[i];
    for (register long long i = 1; i < n; ++i)
      can[i] = (bin[a[i + 1]] - bin[a[i]]) / bin[a[i]];
    ans = 0;
    for (register long long i = 1; i < n; ++i) {
      if (can[i] <= k) {
        k -= can[i];
        ans += can[i] * bin[a[i]];
      } else
        ans += (k + 1) * bin[a[i]], k = 0;
    }
    if (k) ans += bin[a[n]] * (k + 1);
    cout << ans;
    puts("");
  }
  return 0;
}
