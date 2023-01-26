#include <bits/stdc++.h>
using namespace std;
vector<long long int> secs;
long long int n, h;
bool check(long long int k) {
  long long int damage = 0;
  for (int i = n - 1; i >= 0; i--) {
    long long int add = 0;
    if (i == n - 1) {
      add += k;
    } else {
      add += min(k, secs[i + 1] - secs[i]);
    }
    damage += add;
  }
  return damage >= h;
}
void solve() {
  cin >> n >> h;
  secs.resize(n);
  for (auto &x : secs) cin >> x;
  long long int l = 1, r = 1e18 + 1, ans = -1;
  while (l <= r) {
    long long int mid = l + (r - l) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << '\n';
}
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
