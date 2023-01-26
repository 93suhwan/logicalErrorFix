#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt;
  tt = 1;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long sum = 0;
    for (long long i = 0; i < n; ++i) sum += a[i];
    function<long long(long long, long long, long long, long long)> solve =
        [](long long hp, long long ost, long long x, long long y) {
          return max((long long)0, x - hp) + max((long long)0, y - ost);
        };
    long long m;
    cin >> m;
    for (long long i = 0; i < m; ++i) {
      long long x, y;
      cin >> x >> y;
      long long ans = LLONG_MAX / 2;
      auto tr1 = lower_bound(a.begin(), a.end(), x);
      if (tr1 != a.end()) ans = min(ans, solve(*tr1, sum - (*tr1), x, y));
      auto tr2 = tr1;
      if (tr2 != a.begin())
        --tr2, ans = min(ans, solve(*tr2, sum - (*tr2), x, y));
      cout << ans << endl;
    }
  }
}
