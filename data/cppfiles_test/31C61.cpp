#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1 << 19;
long long n, k;
long long ans[maxn], mx[maxn], mn[maxn];
bool occ[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 0; i < (long long)(1 << k); ++i)
    mx[i] = -1e9, mn[i] = 1e9, ans[i] = 2e9;
  for (long long i = 0; i < (long long)(n); ++i) {
    long long u;
    cin >> u;
    occ[u] = 1, mx[u] = u, mn[u] = u;
  }
  for (long long i = 0; i < k; ++i) {
    for (long long j = 0; j < (1 << k); j += (1 << i + 1)) {
      for (long long t = 0; t < (long long)(1 << i); ++t) {
        ans[j + t] = ans[j + t + (1 << i)] =
            min(ans[j + t], ans[j + t + (1 << i)]);
        ans[j + t] = min(ans[j + t], mn[j + t + (1 << i)] - mx[j + t]);
        ans[j + t + (1 << i)] =
            min(ans[j + t + (1 << i)],
                mn[j + t] - mx[j + t + (1 << i)] + (1 << i + 1));
      }
    }
    for (long long j = 0; j < (1 << k); j += (1 << i + 1)) {
      for (long long t = 0; t < (long long)(1 << i); ++t) {
        long long upmn0 = min(mn[j + t], mn[j + t + (1 << i)]);
        long long upmn1 =
            min(mn[j + t + (1 << i)] - (1 << i), mn[j + t] + (1 << i));
        long long upmx0 = max(mx[j + t], mx[j + t + (1 << i)]);
        long long upmx1 =
            max(mx[j + t + (1 << i)] - (1 << i), mx[j + t] + (1 << i));
        mn[j + t] = upmn0, mn[j + t + (1 << i)] = upmn1;
        mx[j + t] = upmx0, mx[j + t + (1 << i)] = upmx1;
      }
    }
  }
  for (long long i = 0; i < (long long)(1 << k); ++i) cout << ans[i] << " ";
  return 0;
}
