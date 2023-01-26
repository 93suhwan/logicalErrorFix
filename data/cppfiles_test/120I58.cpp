#include <bits/stdc++.h>
using namespace std;
vector<long long> dx = {1, -1, 0, 0};
vector<long long> dy = {0, 0, -1, 1};
const long long N = 2e5 + 5;
void solve() {
  long long l, r;
  cin >> l >> r;
  long long a = l;
  long long cnt = (l % 2 == 0) ? 1 : 0;
  for (long long i = l + 1; i < r + 1; i++) {
    if (i % 2 == 0) cnt++;
    a &= i;
  }
  if (a) {
    cout << 0 << '\n';
    return;
  }
  long long one;
  long long cur = 1;
  while (cur <= l) {
    cur *= 2;
  }
  long long r1 = cur - l;
  one = cur;
  cur = 1;
  while (cur <= r) {
    cur *= 2;
  }
  long long r3 = r - cur / 2 + 1;
  long long r2 = cur / 2 - one;
  long long ans = min({r1 + r2, r2 + r3, r1 + r3, cnt});
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
