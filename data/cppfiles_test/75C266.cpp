#include <bits/stdc++.h>
using namespace std;
const long long N = 100100;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    long long mx = 0;
    for (long long j = 0; j < k; j++) {
      long long x;
      cin >> x;
      mx = max(mx, x - j + 1);
    }
    v[i] = {mx, k};
  }
  sort(v.begin(), v.end());
  vector<long long> pref(n, 0);
  for (long long i = 0; i < n; i++) {
    pref[i] = v[i].second;
    if (i) pref[i] += pref[i - 1];
  }
  long long ans = v[0].first, i = 0, j = 1;
  while (j < n) {
    while (i <= j && v[i].first + pref[j - 1] < v[j].first) {
      i++;
    }
    ans = max(ans, v[i].first - (v[i].first + pref[j - 1] - v[j].first));
    j++;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
