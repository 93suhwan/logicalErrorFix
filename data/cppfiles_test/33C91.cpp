#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int64_t INF = 2e18;
const long long MAX = 2e9;
const long long N = 2e5 + 5;
const long long ep = 1e-9;
void io() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long ans = INT_MIN;
  for (long long i = 0; i < n - 1; i++) {
    ans = max(ans, arr[i] * arr[i + 1]);
  }
  cout << ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
