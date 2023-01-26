#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<string> v(n - 2);
  for (int i = 0; i < n - 2; i++) cin >> v[i];
  if (n == 3) {
    cout << "a" << v[0];
    return;
  }
  string ans = "";
  ans = v[0][0];
  for (int i = 1; i < n - 2; i++) {
    if (v[i - 1][1] == v[i][0]) {
      ans += v[i][0];
    } else {
      ans += v[i - 1][1];
      ans += v[i][0];
    }
  }
  ans += v[n - 3][1];
  if (ans.length() != n) ans += 'a';
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
