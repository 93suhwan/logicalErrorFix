#include <bits/stdc++.h>
using namespace std;
inline void file_handling() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
void solve() {
  long long N;
  cin >> N;
  vector<long long> v(N);
  for (long long &i : v) cin >> i;
  long long mx = *max_element(v.begin(), v.end());
  long long count_mx = count(v.begin(), v.end(), mx);
  long long k = count(v.begin(), v.end(), mx - 1);
  long long fac = 1LL;
  for (long long i = 1; i <= N; ++i) {
    fac = ((fac % 998244353) * (i)) % 998244353;
  }
  if (count_mx > 1) {
    cout << fac << '\n';
  } else if (k == 0) {
    cout << 0 << '\n';
  } else {
    cout << fac - fac / (k + 1) << '\n';
  }
}
signed main() {
  file_handling();
  long long testCases = 1;
  cin >> testCases;
  while (testCases--) solve();
  return 0;
}
