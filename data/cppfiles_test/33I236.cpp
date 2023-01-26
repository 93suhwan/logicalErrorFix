#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MX = 10e6;
inline void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  auto a = max_element((v).begin(), (v).end()) - v.begin();
  if (a == n - 1) {
    cout << v[a] * v[a - 1];
  } else if (a == 0) {
    cout << v[a] * v[a + 1];
  } else {
    cout << max(v[a] * v[a + 1], v[a] * v[a - 1]);
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
