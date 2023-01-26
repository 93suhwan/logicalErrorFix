#include <bits/stdc++.h>
using namespace std;
void init() {}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v) cin >> it;
  int ans = 0;
  while (!is_sorted(v.begin(), v.end())) {
    for (int i = ans % 2; i + 1 < n; i += 2) {
      if (v[i] > v[i + 1]) {
        swap(v[i], v[i + 1]);
      }
    }
    ans += 1;
  }
  cout << ans << endl;
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
