#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long sz = 2e5 + 5;
long long ans[10000];
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, vector<long long> > > v;
  vector<long long> ara(n);
  long long ans = 1e18;
  for (long long i = 0; i < n; ++i) cin >> ara[i];
  for (long long i = 0; i < n; ++i) {
    for (long long j = i; j < n; ++j) {
      vector<long long> vv = ara;
      long long p = i, q = j;
      while (p <= q) {
        ara[p] = ara[p] & ara[q];
        ara[q] = ara[p];
        p++, q--;
      }
      long long mn = *min_element(vv.begin(), vv.end());
      ans = min(ans, mn);
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  long long T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
