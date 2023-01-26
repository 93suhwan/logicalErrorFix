#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (auto &i : v) {
    cin >> i;
  }
  bool is = true;
  while (is) {
    is = false;
    n = v.size();
    for (long long int i = n - 1; i >= 0; --i) {
      if (v[i] % (i + 2) != 0) {
        v.erase(next(v.begin(), i));
        is = true;
        break;
      }
    }
  }
  if (v.empty()) {
    cout << "YES" << '\n';
    ;
    ;
    return;
  }
  cout << "NO" << '\n';
  ;
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
