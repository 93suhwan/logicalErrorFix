#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
const long long N = 1e5 + 1;
const long long mod = 1e9 + 7;
void solve() {
  long long w, h;
  cin >> w >> h;
  deque<long long> pts[4];
  for (long long i = 0; i < 4; i++) {
    long long k;
    cin >> k;
    for (long long j = 0; j < k; j++) {
      long long x;
      cin >> x;
      pts[i].push_back(x);
    }
    sort(pts[i].begin(), pts[i].end());
  }
  long long ans = 0;
  for (long long i = 0; i < 2; i++) {
    ans = max(ans, h * (pts[i].back() - pts[i][0]));
  }
  for (long long i = 2; i < 4; i++) {
    ans = max(ans, w * (pts[i].back() - pts[i][0]));
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
