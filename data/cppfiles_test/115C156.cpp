#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long ans, l = 1, r = h;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    long long curs = 0, c = 0;
    for (long long i = 0; i < n; i++) {
      if (v[i] + mid - 1 <= curs) continue;
      if (curs < v[i]) {
        c += mid;
        curs = v[i] + mid - 1;
        continue;
      }
      c += (v[i] + mid - 1 - curs);
      curs = v[i] + mid - 1;
    }
    if (c >= h) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long numberoftestcases = 1;
  cin >> numberoftestcases;
  while (numberoftestcases--) solve();
  return 0;
}
