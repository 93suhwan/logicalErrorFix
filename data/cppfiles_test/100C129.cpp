#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  if (v.size() == 1) {
    cout << v[0] << '\n';
    return;
  }
  long long x = 0, ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    ans = max(ans, v[i] - x);
    x = v[i];
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
