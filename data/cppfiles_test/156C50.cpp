#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  long long k, sum = 0;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  if (sum <= k) {
    cout << "0\n";
    return;
  }
  long long need = k / n;
  long long ans = 0;
  ans += max(0ll, a[0] - need);
  a[0] = min(need, a[0]);
  long long mn = 1e18;
  int pt = 1;
  sum = a[0];
  for (long long add = 0; add <= n + n + n; add++) {
    long long cur = add;
    while (pt < n &&
           (n - (pt + 1)) * 1ll * (a[0] - add) + sum - add + a[pt] <= k) {
      pt++;
      sum += a[pt - 1];
    }
    cur += n - pt;
    mn = min(mn, cur);
  }
  cout << ans + mn << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
