#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
const long long N = 3e5 + 9;
void solve() {
  long long n;
  cin >> n;
  vector<long long> even, odd;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    if (x & 1)
      odd.push_back(i);
    else
      even.push_back(i);
  }
  long long u = even.size(), v = odd.size();
  if (n % 2 == 0) {
    if (u != v) {
      cout << -1 << "\n";
      return;
    }
    long long tmp1 = 0, j = 0;
    for (long long i = 1; i <= n; i += 2) tmp1 += abs(i - even[j++]);
    long long tmp2 = 0;
    j = 0;
    for (long long i = 1; i <= n; i += 2) tmp2 += abs(i - odd[j++]);
    cout << min(tmp1, tmp2) << "\n";
    return;
  }
  if (abs(u - v) > 1) {
    cout << -1 << "\n";
    return;
  }
  long long tmp = 0, j = 0;
  if (u == v + 1) {
    for (long long i = 1; i <= n; i += 2) tmp += abs(i - even[j++]);
  }
  if (u + 1 == v) {
    for (long long i = 1; i <= n; i += 2) tmp += abs(i - odd[j++]);
  }
  cout << tmp << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
