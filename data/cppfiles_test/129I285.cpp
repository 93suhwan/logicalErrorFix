#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long INF = 1e18;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  vector<bool> present(n + 1, false);
  vector<long long> v;
  for (long long i = 1; i <= n; i++) {
    if (arr[i] > n) {
      v.push_back(arr[i]);
    } else if (!present[arr[i]]) {
      present[arr[i]] = true;
    } else
      v.push_back(arr[i]);
  }
  bool ok = true;
  sort(v.begin(), v.end());
  long long idx = 0;
  for (long long i = 1; i <= n; i++) {
    if (present[i]) {
      continue;
    } else {
      if (i >= v[idx] / 2) {
        ok = false;
      }
      idx += 1;
    }
  }
  long long ans;
  if (ok)
    ans = (long long)v.size();
  else
    ans = -1;
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
