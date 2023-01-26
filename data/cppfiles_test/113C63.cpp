#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  tc = 1;
  long long mod = 1e18 + 2;
  while (tc--) {
    long long i, j, k, n, m;
    scanf("%lld", &n);
    vector<long long> v;
    long long tot = 0;
    for (i = 0; i < n; i++) {
      long long x;
      scanf("%lld", &x);
      v.push_back(x);
      tot += x;
      tot %= mod;
    }
    sort(v.begin(), v.end());
    scanf("%lld", &m);
    while (m--) {
      long long d, a;
      scanf("%lld %lld", &d, &a);
      if (binary_search(v.begin(), v.end(), d)) {
        cout << max(0LL, a - (tot - d));
        printf("\n");
        continue;
      }
      long long id = upper_bound(v.begin(), v.end(), d) - v.begin();
      id--;
      if (id < 0) {
        cout << max(0LL, a - (tot - v[0]));
        printf("\n");
      } else if (id + 1 >= n) {
        cout << (d - v[n - 1]) + max(0LL, a - (tot - v[n - 1]));
        printf("\n");
      } else {
        long long ans1 = INT_MAX;
        long long ans2 = INT_MAX;
        long long xx = tot;
        ans1 = d - v[id] + max(0LL, a - (tot - v[id]));
        ans2 = max(0LL, a - (tot - v[id + 1]));
        cout << min(ans1, ans2);
        printf("\n");
      }
    }
  }
}
