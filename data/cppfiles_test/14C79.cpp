#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n, 0);
  for (long long i = 0; i < n; ++i) cin >> arr[i];
  vector<vector<long long>> ans;
  for (long long i = 0; i < n; ++i) {
    long long minval = arr[i];
    long long idx = i;
    for (long long j = i + 1; j < n; ++j) {
      if (arr[j] < minval) {
        minval = arr[j];
        idx = j;
      }
    }
    if (idx == i) continue;
    long long st = i + 1;
    long long ed = idx + 1;
    long long mv = idx - i;
    ans.push_back({st, ed, mv});
    for (long long j = idx; j >= i + 1; --j) {
      swap(arr[j], arr[j - 1]);
    }
  }
  cout << (long long)ans.size() << "\n";
  for (auto x : ans) {
    cout << x[0] << " " << x[1] << " " << x[2] << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
