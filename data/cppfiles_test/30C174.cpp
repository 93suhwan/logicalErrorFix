#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 2 * 1e5;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  int ans = INT_MAX;
  for (long long i = 0; i < 26; i++) {
    int l = 0;
    int r = n - 1;
    int cnt = 0;
    bool flag = true;
    while (l <= r) {
      if (s[l] == s[r]) {
        l = l + 1;
        r = r - 1;
      } else {
        if (s[l] == alpha[i]) {
          l = l + 1;
          cnt++;
        } else if (s[r] == alpha[i]) {
          r = r - 1;
          cnt++;
        } else {
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      ans = min(ans, cnt);
    }
  }
  if (ans == INT_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
