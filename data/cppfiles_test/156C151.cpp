#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
void solve() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  std::vector<long long> v(n), prefSum(n + 1);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) prefSum[i + 1] = prefSum[i] + v[i];
  long long sum = accumulate(v.begin(), v.end(), 0ll);
  if (sum <= k) {
    cout << 0 << "\n";
    return;
  }
  long long ans = inf;
  for (long long sets = 0; sets <= n - 1; sets++) {
    long long currSum = prefSum[n - sets] + v[0] * sets;
    long long reduces = sets + 1;
    long long need = max((currSum - k + reduces - 1) / reduces, 0ll);
    ans = min(ans, need + sets);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
