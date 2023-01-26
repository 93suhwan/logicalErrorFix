#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
void solve() {
  cin >> n;
  a.resize(n);
  for (auto& x : a) {
    cin >> x;
  }
  int cnt = *max_element(a.begin(), a.end()) / 3, ans = INT_MAX;
  for (int i = max(0, cnt - 10); i <= cnt + 10; i++) {
    int twos = 0;
    for (auto x : a) {
      int cur = min(i, x / 3);
      int rem = x - cur - cur - cur;
      twos = max(twos, (rem / 2));
    }
    for (int j = max(0, twos - 10); j <= twos + 10; j++) {
      int res = 0;
      for (auto x : a) {
        int cur = min(i, x / 3);
        int rem = x - cur - cur - cur;
        int cnt2 = min(j, (rem / 2));
        int rem2 = rem - cnt2 - cnt2;
        if (rem2 == 1 && j - cnt2 >= 2 && cur) continue;
        res = max(res, rem2);
      }
      ans = min(ans, i + j + res);
    }
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
