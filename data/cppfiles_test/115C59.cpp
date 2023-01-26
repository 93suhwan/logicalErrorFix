#include <bits/stdc++.h>
using namespace std;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, h;
  cin >> n >> h;
  vector<long long> vec(n);
  for (long long i = 0; i < n; i++) cin >> vec[i];
  long long l = 0, r = h, mid, cur;
  long long ans = h;
  while (l <= r) {
    mid = (l + r) / 2;
    cur = mid;
    for (int i = 0; i < n - 1; i++) {
      cur += min(vec[i + 1] - vec[i], mid);
    }
    if (cur >= h) {
      ans = min(ans, mid);
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
