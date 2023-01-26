#include <bits/stdc++.h>
using namespace std;
const long long MN = 200005;
long long t, n, m, k;
int32_t main() {
  cin.tie(0), cin.sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    long long sml = n / m;
    long long big = (n + m - 1) / m;
    long long numbig = n % m;
    long long numsml = m - numbig;
    long long fb = 1;
    for (long long i = 1; i <= k; i++) {
      long long used[n + 5];
      memset(used, 0, sizeof(used));
      for (long long j = 1; j <= numbig; j++) {
        vector<long long> v;
        while (v.size() < big) {
          v.push_back(fb);
          used[fb] = 1;
          fb++;
          if (fb > n) fb -= n;
        }
        printf("%d", big);
        for (long long p : v) printf(" %d", p);
        printf("\n");
      }
      vector<long long> v;
      for (long long j = 1; j <= n; j++) {
        if (used[j]) continue;
        v.push_back(j);
        if (v.size() == sml) {
          printf("%d", sml);
          for (long long p : v) printf(" %d", p);
          printf("\n");
          v.clear();
        }
      }
    }
    printf("\n");
  }
  return 0;
}
