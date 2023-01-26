#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> m1, m2;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    m1[x]++;
    m2[y]++;
  }
  long long ans = (n * (n - 1) * (n - 2)) / 6;
  long long count1 = 0, count2 = 0;
  for (auto i : m1) {
    count1 += (i.second - 1);
  }
  for (auto i : m2) {
    count2 += (i.second - 1);
  }
  ans = ans - (count1 * count2);
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long _t;
  cin >> _t;
  while (_t--) solve();
  return 0;
}
