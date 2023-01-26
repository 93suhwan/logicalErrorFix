#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& el : a) cin >> el;
  int ans = 2e9;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      int res = 0;
      for (auto& el : a) {
        int cur = 2e9;
        for (int q = 0; q <= i; q++)
          for (int w = 0; w <= j; w++)
            if (el - 2 * q - w >= 0 && (el - 2 * q - w) % 3 == 0)
              cur = min(cur, (el - 2 * q - w) / 3);
        res = max(res, cur);
      }
      ans = min(ans, res + i + j);
    }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
