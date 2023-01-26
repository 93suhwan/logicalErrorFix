#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 200005;
void solve() {
  long long n;
  cin >> n;
  long long v[n][2];
  long long sum = 0;
  for (long long i = 0; i < n; i++) cin >> v[i][0], sum += v[i][0];
  for (long long i = 0; i < n; i++) cin >> v[i][1], sum += v[i][1];
  vector<long long> pref(n);
  for (long long i = 0; i < n; i++) {
    if (i == 0)
      pref[i] = v[i][0];
    else
      pref[i] = pref[i - 1] + v[i][0];
  }
  vector<long long> suff(n);
  for (long long i = n - 1; i >= 0; i--) {
    if (i == n - 1)
      suff[i] = v[i][1];
    else
      suff[i] = suff[i + 1] + v[i][1];
  }
  long long ans = INT_MAX;
  for (long long i = 0; i < n; i++) {
    long long d = pref[i] + suff[i];
    long long e = pref[n - 1] - pref[i];
    long long f = suff[0] - suff[i];
    ans = min(ans, max(e, f));
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
