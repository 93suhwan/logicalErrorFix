#include <bits/stdc++.h>
using namespace std;
bool flag = 0;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long mx = 0;
  for (long long i = 0; i < n - 1; i++) {
    mx = max(mx, arr[i] * arr[i + 1]);
  }
  cout << mx;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
